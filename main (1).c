//DNA LAB EXPERIMENT

#include <kipr/wombat.h>

int rightMotor = 0;
int rightPower = 100;
int leftMotor = 3;
int leftPower = 100;

int elbow = 0;
int flatWrist = 1;
int spinWrist = 2;
int claw = 3;

int flatDown = 1950;
int flatUp = 45;
int midWrist = 1025;
int elbowDown = 1950;
int elbowUp = 100;
int midElbow = 1025;
int horizontal = 1732;
int vertical = 550;
int open = 888;
int closed = 1375;

int orangeHeight = 950;
int greenHeight = 1300;
int blueHeight = 1490;

int blueClosed = 1280;

int currentElbow;
int currentFlatWrist;
int currentLeftMotor;
int currentRightMotor;

int count = 0;

void forward();
void backward();
void backwardSlow();
void spinRight();
void hold();
void pullUp();
void pullDown();
void openClaw();
void closeClaw();
void spinVert();
void spinHoriz();

int main()
{
    enable_servos();
    
    pullDown(blueHeight);
    pullUp();
    
    /*
    while(count == 0){
        
        count++;
    }
    
    openClaw();
    pullUp();
	hold(2000);
    spinVert();
    hold(2000);
    spinHoriz();
    hold(2000);
    pullDown(blueHeight);
    hold(5000);
    closeClaw(blueClosed);
    hold(3000);
    
    backwardSlow();
    msleep(4000);
    hold(3000);
   
    spinRight();
*/
    
    return 0;
}

void forward(){
	motor(rightMotor, rightPower);
    motor(leftMotor, leftPower);
}

void backward(){
	motor(rightMotor, -rightPower);
    motor(leftMotor, -leftPower);
}

void backwardSlow(){
	motor(rightMotor, (-0.5*rightPower));
    motor(leftMotor, (-0.5*leftPower));
}

void spinRight(){
	motor(rightMotor, (-0.2*rightPower));
    motor(leftMotor, (0.2*leftPower));
    msleep(7500);
}

void hold(){
	motor(rightMotor, 0);
    motor(leftMotor, 0);
}

void pullUp(){
    currentElbow = get_servo_position(elbow);
    currentFlatWrist = get_servo_position(flatWrist);
    currentLeftMotor = get_motor_position_counter(leftMotor);
    currentRightMotor = get_motor_position_counter(rightMotor);
    
	while(currentElbow > midElbow || currentFlatWrist > midWrist){
    	set_servo_position(elbow, currentElbow);
        msleep(40);
        currentElbow = currentElbow - 40;
        
        set_servo_position(flatWrist, currentFlatWrist);
        msleep(40);
        currentFlatWrist = currentFlatWrist - 40;
        
        mrp(rightMotor, 500, -6);//4
        mrp(leftMotor, 500, -6);//4
        bmd(rightMotor);
        bmd(leftMotor);

    }
    
    while(currentElbow > elbowUp || currentFlatWrist > flatUp){
    	set_servo_position(elbow, currentElbow);
        msleep(40);
        currentElbow = currentElbow - 40;
        
        set_servo_position(flatWrist, currentFlatWrist);
        msleep(40);
        currentFlatWrist = currentFlatWrist - 40;
        
        mrp(rightMotor, 500, 2);
        mrp(leftMotor, 500, 2);
        bmd(rightMotor);
        bmd(leftMotor);

    }
}

void pullDown(int height){
    /*
    int elbowDown = 1950;
    int elbowUp = 100;
    int midElbow = 1025;
    */
    
	currentElbow = get_servo_position(elbow);
    currentFlatWrist = get_servo_position(flatWrist);
    currentLeftMotor = get_motor_position_counter(leftMotor);
    currentRightMotor = get_motor_position_counter(rightMotor);
    
  if(height >= midElbow){
    while(currentElbow < midElbow || currentFlatWrist < midWrist){
     	set_servo_position(elbow, currentElbow);
        msleep(40);
        currentElbow = currentElbow + 40;
         
        set_servo_position(flatWrist, currentFlatWrist);
        msleep(40);
        currentFlatWrist = currentFlatWrist + 40;
         
        mrp(rightMotor, 500, -12);//8
        mrp(leftMotor, 500, -12);//8
        bmd(rightMotor);
        bmd(leftMotor);

    }
     
    while(currentElbow < height || currentFlatWrist < flatUp){
     	set_servo_position(elbow, currentElbow);
        msleep(40);
        currentElbow = currentElbow + 40;
         
        set_servo_position(flatWrist, currentFlatWrist);
        msleep(40);
        currentFlatWrist = currentFlatWrist + 40;
         
        mrp(rightMotor, 500, 2);
        mrp(leftMotor, 500, 2);
        bmd(rightMotor);
        bmd(leftMotor);

    }
  }
    
  if(height < midElbow){
	while(currentElbow < height || currentFlatWrist < flatUp){
     	set_servo_position(elbow, currentElbow);
        msleep(40);
        currentElbow = currentElbow + 40;
         
        set_servo_position(flatWrist, currentFlatWrist);
        msleep(40);
        currentFlatWrist = currentFlatWrist + 40;
         
        mrp(rightMotor, 500, -8);//2
        mrp(leftMotor, 500, -8);//2
        bmd(rightMotor);
        bmd(leftMotor);

    }
  }
}

void closeClaw(int closed){
	set_servo_position(claw, closed);
    msleep(750);
}

void openClaw(){
	set_servo_position(claw, open);
    msleep(750);
}

void spinVert(){
	set_servo_position(spinWrist, vertical);
    msleep(750);
}

void spinHoriz(){
	set_servo_position(spinWrist, horizontal);
    msleep(750);
}


/*

clear_motor_position_counter(0); //cmpc
mrp(0, 1000); //move relative position
mrp(3, 1000);
bmd(0); //block motor done
bmd(3);

get_motor_position(0); //gmpc

*/
