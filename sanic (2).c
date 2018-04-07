//area of an average sized is 1540

#include <kipr/botball.h>
#include "fxns.h"


int main()
{    
    //initialization
    camera_open();
    camera_update();
    msleep(500);
    enable_servos();
    msleep(100);
    set_servo_position(CLAW, 450);
    set_servo_position(LIFT, 263);
    msleep(500);
    msleep(500);

    //wait_for_light(5);
    shut_down_in(119);
 
    //look at the color of the first cube
    int i = 0;
    for(i; i<10;i++){
        camera_update();
        msleep(100);
    } 
    int yarea=get_object_area(YELLOW,0);
    int rarea=get_object_area(RED,0);
    printf(" RED area is %d", rarea);
    printf(" YELLOW area is %d", yarea);
    if(yarea>500){
        box1 = yellow;
        printf("\n First box is YELLOW");
    }else if(rarea>500){
        box1 = red;
        printf("\n First box is RED");
    }
    else{
        box1 = green;
        printf("\n First box is GREEN");
    }
    
    //move out of the starting box
    move(3,1300);
    ao();
    msleep(10);
    
    //look for the black line twice
    while(analog(RTOP) < 2000)
    {
        mav(LMOTOR,1300);
        mav(RMOTOR,1300);
    }
   
       while(analog(RTOP) > 2000)
    {
        mav(LMOTOR,1300);
        mav(RMOTOR,1300);
    }
    
       while(analog(RTOP) < 2000)
    {
        mav(LMOTOR,1300);
        mav(RMOTOR,1300);
    }
    printf("\n Saw second line");
    move(5,1300);
    while(analog(RTOP) <2000)
    {
        mav(LMOTOR,500);
        mav(RMOTOR,-500);
    }
    ao();
    msleep(10);
    
    //single line follow until perpendicular one
    while(analog(LTOP) < 2000)
    {
      if(analog(RTOP)>2000)
      {
          mav(RMOTOR,1300);
          mav(LMOTOR,600);
      }
      else
      {
      mav(RMOTOR,600);
      mav(LMOTOR,1300);
      }
    }
    
    //boost self over the line
    set_servo_position(LIFT, 1300);
    msleep(500);
    move(1,1300);
    set_servo_position(LIFT, 263);
    msleep(500);
    
    //go past the line and look for middle cube
    int t = seconds() + 5;
       while(seconds() < t)
    {
      if(analog(RTOP)>2000)
      {
          mav(RMOTOR,1200);
          mav(LMOTOR,700);
      }
      else
      {
      mav(RMOTOR,700);
      mav(LMOTOR,1200);
      }
    }
    ao();
    msleep(10);
    
    int l = 0;
    for(l; l<10;l++){
        camera_update();
        msleep(100);
    } 
    
    yarea=get_object_area(YELLOW,0);
    rarea=get_object_area(RED,0);
    printf("RED area is %d", rarea);
    printf("YELLOW area is %d", yarea);
    if(box1 == yellow){
        if(rarea > 200){
            box2 = red;
            printf("\n Second box is RED");
            box3 = green;
        }else{
            box2 = green;
            printf("\n Second box is GREEN");
            box3 = red;
        }
    }else if(box1 == red){
        if(yarea > 200){
            box2 = yellow;
            printf("\n Second box is YELLOW");
            box3 = green;
        }else{
            box2 = green;
            printf("\n Second box is GREEN");
            box3 = yellow;
        }
    }
    else{
        box2 = yellow;
            printf("\n Second box is YELLOW");
        if(box1 == green){
            box3 = red;
        }else{
            box3 = green;
        }
    }
    
    //go back
    turn(180,1300);
    while(analog(RTOP) < 2000)
    {
      if(analog(LTOP)>2000)
      {
          mav(RMOTOR,600);
          mav(LMOTOR,1300);
      }
      else
      {
      mav(RMOTOR,1300);
      mav(LMOTOR,600);
      }
    }
    
    //turn and go for the yellow crates
    turn(80,1300);
    ao();
    msleep(10);
    set_servo_position(LIFT, LIFT_DOWN);
    msleep(500);
    move(4,1300);
    ao();
    msleep(10);
    set_servo_position(CLAW, CLAW_CLOSED);
    msleep(500);
    set_servo_position(LIFT, LIFT_UP);
    msleep(500);
    
    //move forward
    move(-4,1300);
    ao();
    msleep(10);
    turn(180,1300);
    move(5,1300);
    ao();
    msleep(10);
    
    //turn to straighten against black line
    while(analog(LTOP)<2000){
        mav(LMOTOR,-1000);
        mav(RMOTOR,-1000);
    }
    ao();
    msleep(10);
    while(analog(RTOP)<2000){
        mav(RMOTOR,-800);
    }
    ao();
    msleep(10);
    
    //move forward to middle cube and drop
    move(11,1300);
    ao();
    msleep(10);
    turn(-30,500);
    ao();
    msleep(10);
    move(2,1000);
    ao();
    msleep(10);
    set_servo_position(LIFT, LIFT_DOWN);
    msleep(500);
    set_servo_position(CLAW, CLAW_OPEN);
    msleep(500);
    set_servo_position(LIFT, LIFT_UP);
    msleep(500);
    set_servo_position(CLAW, CLAW_CLOSED);
    msleep(500);
    set_servo_position(LIFT, LIFT_UP - 190);
    msleep(500);
    move(-2,1000);
    ao();
    msleep(10);
    turn(60,1300);
    ao();
    msleep(10);
    move(2,1300);
    ao();
    msleep(10);
    turn(30,1300);
    ao();
    msleep(10);
    move(-20,1300);
    ao();
    msleep(10);
    
    printf("\n");
    printf("%d\n",box1);
    printf("%d\n",box2);
    printf("%d\n",box3);

    
    /*
    
    move(-3,1300);
    turn(30,1300);
    
      while(analog(LTOP) < 2000)
    {
      int x = analog(RTOP);
      //printf("Black line sensor reads: %d \n", x);
      if(analog(RTOP)>2000)
      {
          mav(RMOTOR,1300);
          mav(LMOTOR,600);
      }
      else
      {
      mav(RMOTOR,600);
      mav(LMOTOR,1300);
      }
    }
    
   while(analog(LTOP) > 2000)
   {
       move(-1,1300);
   }
    
       while(analog(LTOP) <2000)
   {
       mav(LMOTOR,-500);
       mav(RMOTOR,-500);
   }
    
    */
    
  return 0;
}