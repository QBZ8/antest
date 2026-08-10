package com.example.onenet_app // 如果你的包名变了，请改回原来的

import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import okhttp3.*
import okhttp3.MediaType.Companion.toMediaType
import okhttp3.RequestBody.Companion.toRequestBody
import org.json.JSONObject
import java.io.IOException
import java.util.concurrent.TimeUnit

class MainActivity : AppCompatActivity() {

    // 【优化】初始化 OkHttp 客户端，增加明确的超时时间（10秒）
    private val client = OkHttpClient.Builder()
        .connectTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .build()

    // UI 组件
    private lateinit var etProductId: EditText
    private lateinit var etDeviceName: EditText
    private lateinit var etAuthToken: EditText
    private lateinit var btnLightOn: Button
    private lateinit var btnLightOff: Button

    // 新增查询组件
    private lateinit var etQueryId: EditText
    private lateinit var btnQuery: Button
    private lateinit var tvResult: TextView

    private lateinit var tvLog: TextView
    private lateinit var scrollLog: androidx.core.widget.NestedScrollView

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        initViews()
        setupListeners()
    }

    private fun initViews() {
        etProductId = findViewById(R.id.et_product_id)
        etDeviceName = findViewById(R.id.et_device_name)
        etAuthToken = findViewById(R.id.et_auth_token)
        btnLightOn = findViewById(R.id.btn_light_on)
        btnLightOff = findViewById(R.id.btn_light_off)

        etQueryId = findViewById(R.id.et_query_id)
        btnQuery = findViewById(R.id.btn_query)
        tvResult = findViewById(R.id.tv_result)

        tvLog = findViewById(R.id.tv_log)
        scrollLog = findViewById(R.id.scroll_log)
    }

    private fun setupListeners() {
        // HTTP 方案不需要连接，直接点击按钮下发指令
        btnLightOn.setOnClickListener { sendCommandViaHttp(true) }
        btnLightOff.setOnClickListener { sendCommandViaHttp(false) }

        // 点击查询数据
        btnQuery.setOnClickListener { queryDataViaHttp() }
    }

    // --------------------------------------------------------
    // 查询设备数据 (HTTP GET)
    // --------------------------------------------------------
    private fun queryDataViaHttp() {
        val productId = etProductId.text.toString().trim()
        val deviceName = etDeviceName.text.toString().trim()
        val authToken = etAuthToken.text.toString().trim()
        val targetIdentifier = etQueryId.text.toString().trim()

        if (productId.isEmpty() || deviceName.isEmpty() || authToken.isEmpty() || targetIdentifier.isEmpty()) {
            log("⚠️ 请先填写完整配置参数和需要查询的标识符！")
            return
        }

        val url = "https://iot-api.heclouds.com/thingmodel/query-device-property?product_id=$productId&device_name=$deviceName"

        log("⏳ 正在查询 [$targetIdentifier] 的实时数据...")
        tvResult.text = "查询中..."
        tvResult.setTextColor(android.graphics.Color.parseColor("#8E8E93"))

        val request = Request.Builder()
            .url(url)
            .get()
            .addHeader("Authorization", authToken)
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                log("❌ 查询失败 (网络错误): ${e.message}")
                runOnUiThread { tvResult.text = "网络错误" }
            }

            override fun onResponse(call: Call, response: Response) {
                val responseBodyStr = response.body?.string() ?: ""

                runOnUiThread {
                    if (response.isSuccessful) {
                        log("✅ 查询成功！\n返回: $responseBodyStr")
                        try {
                            val rootObj = JSONObject(responseBodyStr)
                            if (rootObj.optInt("code") == 0) {
                                val dataArray = rootObj.optJSONArray("data")
                                var foundValue: String? = null

                                if (dataArray != null) {
                                    for (i in 0 until dataArray.length()) {
                                        val item = dataArray.getJSONObject(i)
                                        if (item.optString("identifier") == targetIdentifier) {
                                            foundValue = item.optString("value")
                                            break
                                        }
                                    }
                                }

                                if (foundValue != null) {
                                    tvResult.text = foundValue
                                    tvResult.setTextColor(android.graphics.Color.parseColor("#FF9500"))
                                } else {
                                    tvResult.text = "暂无数据"
                                    tvResult.setTextColor(android.graphics.Color.parseColor("#FF3B30"))
                                    log("⚠️ 在云端未找到标识符为 [$targetIdentifier] 的数据。")
                                }
                            } else {
                                tvResult.text = "查询出错"
                                log("⚠️ 云端报错: ${rootObj.optString("msg")}")
                            }
                        } catch (e: Exception) {
                            tvResult.text = "解析异常"
                            log("❌ JSON 解析错误: ${e.message}")
                        }
                    } else {
                        tvResult.text = "请求失败"
                        log("⚠️ HTTP 错误代码: ${response.code}\n错误详情: $responseBodyStr")
                    }
                }
            }
        })
    }

    // --------------------------------------------------------
    // 控制设备 (HTTP POST) - 【优化】增加超时自动重试机制
    // --------------------------------------------------------
    private fun sendCommandViaHttp(turnOn: Boolean, retryCount: Int = 3) {
        val productId = etProductId.text.toString().trim()
        val deviceName = etDeviceName.text.toString().trim()
        val authToken = etAuthToken.text.toString().trim()

        if (productId.isEmpty() || deviceName.isEmpty() || authToken.isEmpty()) {
            log("⚠️ 请先填写完整 Product ID、Device Name 和 API Token！")
            return
        }

        val url = "https://iot-api.heclouds.com/thingmodel/set-device-property"

        val jsonBody = JSONObject().apply {
            put("product_id", productId)
            put("device_name", deviceName)
            val params = JSONObject().apply {
                put("LED", turnOn) // 确保你的物模型里叫 LED_Green，如果代码里是 LED，请改成 LED
            }
            put("params", params)
        }.toString()

        if (retryCount == 3) {
            log("⏳ 正在发送控制指令...\n内容: $jsonBody")
        }

        val requestBody = jsonBody.toRequestBody("application/json; charset=utf-8".toMediaType())
        val request = Request.Builder()
            .url(url)
            .post(requestBody)
            .addHeader("Authorization", authToken)
            .build()

        client.newCall(request).enqueue(object : Callback {
            override fun onFailure(call: Call, e: IOException) {
                // 【核心优化】：检测到失败或超时，自动重试
                if (retryCount > 0) {
                    log("⚠️ 网络异常或超时，正在重试... (剩余 $retryCount 次)")
                    sendCommandViaHttp(turnOn, retryCount - 1)
                } else {
                    log("❌ 控制请求彻底失败: ${e.message}")
                }
            }

            override fun onResponse(call: Call, response: Response) {
                val responseBodyStr = response.body?.string() ?: ""
                runOnUiThread {
                    if (response.isSuccessful) {
                        log("✅ 云端已接收指令！\n返回: $responseBodyStr")
                    } else {
                        log("⚠️ HTTP 错误代码: ${response.code}\n返回: $responseBodyStr")
                    }
                }
            }
        })
    }

    private fun log(message: String) {
        runOnUiThread {
            val time = java.text.SimpleDateFormat("HH:mm:ss", java.util.Locale.getDefault()).format(java.util.Date())
            tvLog.append("[$time] $message\n\n")
            scrollLog.post { scrollLog.fullScroll(android.view.View.FOCUS_DOWN) }
        }
    }
}