/*
Authors : Marwan Mohamed & Abdelrahman Zohair
Major   : Mechatronics and Robotics Engineering
Company : Hydrotron
*/

#include "Variables.h"

#include "Serial_Get_Data.h"

#include "Serial_Put_Data.h"

#include "Motor.h"

//#include "Debug.h"


void setup() {
  Serial.begin(9600);
  Motor_setup();    
  //Debug_setup();
}

void loop() {
  Get_Serial_Data('#', '|', '*');
  delay(1);
  

  if (isToggling(toggle_ACK, 500)&&joystick_ACK==1) {
    is_ok_flag=1;
    step_emergency_action=1;
    }

 //mySerial.print(toggle_ACK);

  if(is_ok_flag==1&&  (isToggling(toggle_ACK, 500)==0 || joystick_ACK==0) ){
    emergency_action(30000,10000);

  }
  else{
    //Debug_loop();
    Motor_loop();

  }
  
  //mySerial.print(is_ok);

  //mySerial.print(toggle_ACK);
  //mySerial.print(" , ");
  //mySerial.println(joystick_ACK);   


  
  y1 = var_res_int[1]; //BUTTON_FORW_BACK 0 Max_For/ 90 Stop / 180 Max_Back
  x2 = var_res_int[2]; //BUTTON_LR  0 Max_Left/ 90 Stop / 180 Max_Right
  y3 = var_res_int[3]; //BUTTON_UP 0 Stop / 180 Max_UP
  x3 = var_res_int[4]; //BUTTON_DOWN 0 Stop / 180 Max_Down
  toggle_ACK= var_res_int[5];
  joystick_ACK= var_res_int[6];
  

  ////// thurster 3075 RPM//////////

  //////////////////////mapping//////////////////

  forw_ = map(y1, 70, 0, 1500, 1150);
  back_ = map(y1, 100, 180, 1500, 1850);

  right = map(x2, 70, 0, 1500, 1850);
  right_1 = map(x2, 70, 0, 1500, 1150);

  left = map(x2, 100, 180, 1500, 1150);
  left_1 = map(x2, 100, 180, 1500, 1850);

  UP = map(x3, 0, 170, 1500, 1850); //90
  DOWN = map(y3, 0, 170, 1500, 1150); //90

}
