def get_checksums(data_list):
    """
    输入: data_list (包含 HEAD, D_ADDR, ID, LEN, DATA 的列表或 bytes)
    输出: (sum_check, add_check)
    """
    sum_check = 0
    add_check = 0
    
    for byte in data_list:
        # 核心逻辑：8位累加，溢出取模 256
        sum_check = (sum_check + byte) & 0xFF
        add_check = (add_check + sum_check) & 0xFF
        
    return sum_check, add_check

# --- 使用示例 ---
# 假设你的数据如下：
# HEAD=0xAA, D_ADDR=0x01, ID=0x01, LEN=0x01, DATA=0x05
my_packet_data = [0xAA, 0xFF, 0x02, 0x75, 0x0B,0xF9,0xFF,0xE2,0xA1]

sc, ac = get_checksums(my_packet_data)

print(f"计算结果：")
print(f"和校验 (SUM CHECK): 0x{sc:02X} (十进制: {sc})")
print(f"附加校验 (ADD CHECK): 0x{ac:02X} (十进制: {ac})")