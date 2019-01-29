#pragma config(Sensor, dgtl1,  rightQuad,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           DriveLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           Flip,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR  										 */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// we don't need a pre_auton
}
task resetEverything() {
	motor[DriveLeft] = 0;
	motor[DriveRight] = 0;

}
// Start Autonomous
task autonomous()
{
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] > -2400) {
		motor[DriveLeft] = 120;
		motor[DriveRight] = 120;
	}
	Motor[DriveLeft]= 0;
	Motor[DriveRight]= 0;
	wait(2);
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] < 1420) {
		motor[DriveLeft] = -120;
		motor[DriveRight] = -120;
	}
	Motor[DriveLeft]= 0;
	Motor[DriveRight]= 0;
	wait(2);
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] < 680) {
		motor[DriveRight] = -120;
	}
	Motor[DriveLeft] = 0;
	wait(0.5);
	motor[DriveLeft] = -120;
	motor[DriveRight] = -120;
	wait(0.5);
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad] = 0;
	while(SensorValue[leftQuad] > -1500) {
		motor[DriveLeft] = 127;
		motor[DriveRight] = 127;
	}
	startTask(resetEverything);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{

	while (true)
	{
		motor[DriveRight] = vexRT[Ch2];
		motor[DriveLeft] = vexRT[Ch3];

		if(vexRT[Btn5U] == 1)
		{
			motor[Flip] = 85;
		}
		else if(vexRT[Btn6U] == 1)
		{
			motor[Flip] = -50;
		}
		else if(vexRT[Btn6U] == 0)
		{
			motor[Flip] = 0;
		}
	}
}
