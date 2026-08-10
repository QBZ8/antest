#include "User_Task.h"
#include "Drv_RcIn.h"
#include "LX_FC_Fun.h"
#include "Drv_Uart.h"
#include "U2.h"
#include "U3.h"
#include "pid.h"
#include "control.h"
static u8 one_key_takeoff_f = 1, one_key_land_f = 1, one_key_mission_f = 0;
static u8 mission_step;

void UserTask_OneKeyCmd(void)
{
    //////////////////////////////////////////////////////////////////////
    //一键起飞/降落例程
    //////////////////////////////////////////////////////////////////////
    //用静态变量记录一键起飞/降落指令已经执行。

    //判断有遥控信号才执行
    if (rc_in.fail_safe == 0)
    {
        
        //判断第6通道拨杆位置 1700<CH_6<2000
        if (rc_in.rc_ch.st_data.ch_[ch_6_aux2] > 1700 && rc_in.rc_ch.st_data.ch_[ch_6_aux2] < 2200)
        {
            //还没有执行
            if (one_key_mission_f == 0)
            {
                //标记已经执行
                one_key_mission_f = 1;
                //开始流程
                mission_step = 1;
            }
        }
        else
        {
            //复位标记，以便再次执行
            one_key_mission_f = 0;
			FC_Lock();
			
        }
        //
        if (one_key_mission_f == 1)
        {
			static u16 time_dly_cnt_ms;
		    	//
		    	switch(mission_step)
		    	{
		    		case 0:
		    		{
		    			//reset
		    			time_dly_cnt_ms = 0;
		    		}
		    		break;
		    		case 1:
		    		{
		    			//切换模式
		    			mission_step += LX_Change_Mode(2);
		    		}
		    		break;
		    		case 2:
		    		{						
						mission_step+=1;
		    		}
		    		break;
		    		case 3:
		    		{
		    			//解锁
		    			mission_step += FC_Unlock();
		    		}
		    		break;
		    		case 4:
		    		{
		    			//等2秒
		    			if(time_dly_cnt_ms<2000)
		    			{
		    				time_dly_cnt_ms+=20;//ms
		    			}
		    			else
		    			{
		    				time_dly_cnt_ms = 0;
		    				mission_step += 1;
		    			}
		    		}
		    		break;
		    		case 5:
		    		{
		    			//起飞
		    			mission_step += OneKey_Takeoff(50);//参数单位：厘米； 0：默认上位机设置的高度。
		    		}
		    		break;
					/*case 6:
					{//等2秒
						if(time_dly_cnt_ms<2000)
		    			{
		    				time_dly_cnt_ms+=20;//ms
		    			}
		    			else
		    			{
		    				time_dly_cnt_ms = 0;
		    				mission_step += 1;
		    			}
					}*/
					break;
					case 6:
		    		{
		    			mission_step+=test();				
		    			//OneKey_Land();
						//FC_Lock();
						
					}
		    		break;
                    
					case 7:
		    		{
		    			//等2秒
						//mission_step+=test();
						if(time_dly_cnt_ms<2000)
		    			{
		    				time_dly_cnt_ms+=20;//ms
		    			}
		    			else
		    			{
							
		    				time_dly_cnt_ms = 0;
		    				mission_step += 1;
		    			}
						
					}
					break;
					case 8:
		    		{
		    			//test();				//执行一键降落
		    			mission_step+=test();
						//FC_Lock();
						
					}
					
		    		break;	
					case 9:
		    		{
		    			//等2秒
						if(time_dly_cnt_ms<2000)
		    			{
		    				time_dly_cnt_ms+=20;//ms
		    			}
		    			else
		    			{
		    				time_dly_cnt_ms = 0;
		    				mission_step += 1;
		    			}
						//mission_step+=test();
						
					}
		    		break;
					case 10:
		    		{
		    			//mission_step+=test();				//执行一键降落
		    			mission_step+=OneKey_Land();
						//FC_Lock();
						
					}
		    		break;
					/*case 12:
		    		{
		    			//mission_step+=test();				//执行一键降落
		    			mission_step+=OneKey_Land();
						//FC_Lock();
						
					}
		    		break;	
					case 13:
		    		{
		    			//等2秒
						if(time_dly_cnt_ms<5000)
		    			{
		    				time_dly_cnt_ms+=20;//ms
		    			}
		    			else
		    			{
		    				time_dly_cnt_ms = 0;
		    				mission_step += 1;
		    			}
						//mission_step+=test();
						
					}
					case 14:
		    		{
		    			//mission_step+=test();				//执行一键降落
		    			//mission_step+=OneKey_Land();
						FC_Lock();
						
					}*/
					default:
						
					break;
				}
        }
        else
        {
            mission_step = 0;
			FC_Lock();
        }
    }
	else
	{
		FC_Lock();
	}
    ////////////////////////////////////////////////////////////////////////
}




