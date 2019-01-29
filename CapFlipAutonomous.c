#pragma config(Sensor, dgtl1,  rightQuad,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftQuad,       sensorQuadEncoder)
#pragma config(Motor,  port2,           DriveRight,    tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           DriveLeft,     tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           Flip,          tmotorVex393_MC29, openLoop)

task main()
{
	motor[Flip] = -35;
	wait(0.30);
	SensorValue[rightQuad] = 0;
	SensorValue[leftQuad} = 0;
	while(SensorValue[leftQuad] > -420) {
		motor[DriveLeft] = 120;
		motor[DriveRight] = 120;
	}
	wait(0.25);
	motor[Flip] = 80;
	wait(0.35);
}
