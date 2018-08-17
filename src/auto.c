#include "main.h"
#include "global.h"
/*#define thresh 10
int i = 0;//Keeps track of time elapsed

int playback[] ={0,7,63 ,0,2,-63 ,1,7,67 ,1,2,-67 ,4,7,68 ,4,2,-68 ,5,7,69 ,5,2,-69 ,9,7,70 ,9,2,-70 ,11,7,72 ,11,2,-72 ,14,7,76 ,14,2,-76 ,21,7,75 ,21,2,-75 ,24,7,74 ,24,2,-74 ,30,7,72 ,30,2,-72 ,31,7,69 ,31,2,-69 ,34,7,67 ,34,2,-67 ,35,7,65 ,35,2,-65 ,37,7,57 ,37,2,-69 ,41,7,56 ,41,2,-68 ,46,7,55 ,46,2,-67 ,50,7,54 ,50,2,-66 ,51,7,52 ,51,2,-64 ,54,7,47 ,54,2,-65 ,56,7,42 ,56,2,-68 ,57,7,41 ,57,2,-69 ,61,7,43 ,61,2,-71 ,64,7,44 ,64,2,-70 ,72,7,43 ,72,2,-71 ,74,7,44 ,74,2,-70 ,76,7,43 ,76,2,-69 ,80,7,42 ,80,2,-68 ,90,7,50 ,90,2,-64 ,94,7,52 ,96,7,29 ,96,2,-41 ,97,7,0 ,97,2,0 ,116,8,-127 ,145,8,0,152,8,-127 ,162,8,0 ,179,7,16 ,179,2,16 ,181,7,27 ,181,2,27 ,182,7,35 ,182,2,35 ,185,7,39 ,185,2,39 ,194,7,41 ,194,2,41 ,195,7,53 ,195,2,53 ,197,7,71 ,197,2,71 ,199,7,80 ,199,2,80 ,204,7,78 ,204,2,78 ,205,7,65 ,205,2,65 ,231,7,62 ,231,2,62 ,234,7,54 ,234,2,54 ,235,7,45 ,235,2,45 ,241,7,44 ,241,2,44 ,244,7,42 ,244,2,42 ,246,7,38 ,246,2,38 ,247,7,32 ,247,2,32 ,250,7,0 ,250,2,0 ,266,7,19 ,266,2,-19 ,267,7,24 ,267,2,-24 ,270,7,23 ,270,2,-23 ,280,7,18 ,280,2,-18 ,282,7,17 ,282,2,-17 ,285,7,18 ,285,2,-18 ,286,7,22 ,286,2,-22 ,291,7,23 ,291,2,-23 ,297,7,22 ,297,2,-22 ,314,7,21 ,314,2,-21 ,316,7,16 ,316,2,-16 ,319,7,13 ,319,2,-13 ,320,7,11 ,320,2,-11 ,322,7,0 ,322,2,0 ,349,7,12 ,349,2,-12 ,350,7,14 ,350,2,-14 ,355,7,13 ,355,2,-13 ,359,7,0 ,359,2,0 ,375,7,12 ,375,2,-12 ,385,7,14 ,385,2,-14 ,387,7,15 ,387,2,-15 ,389,7,18 ,389,2,-18 ,392,7,25 ,392,2,-25 ,395,7,51 ,395,2,-51 ,397,7,56 ,397,2,-56 ,399,7,55 ,399,2,-55 ,401,7,33 ,401,2,-57 ,402,7,4 ,402,2,-74 ,405,7,-18 ,405,2,-90 ,407,7,-29 ,407,2,-99 ,409,7,-38 ,409,2,-108 ,411,7,-41 ,411,2,-111 ,412,7,-40 ,412,2,-112 ,415,7,-29 ,415,2,-101 ,417,7,-8 ,417,2,-82 ,419,7,31 ,419,2,-43 ,421,7,32 ,421,2,-42 ,425,7,37 ,425,2,-37 ,427,7,47 ,427,2,-27 ,429,7,61 ,429,2,-13 ,431,7,80 ,431,2,6 ,434,7,83 ,434,2,9 ,444,7,85 ,444,2,7 ,445,7,86 ,445,2,6 ,447,7,83 ,447,2,3 ,449,7,72 ,449,2,-8 ,451,7,57 ,451,2,-23 ,454,7,53 ,454,2,-27 ,455,7,50 ,455,2,-30 ,457,7,46 ,457,2,-34 ,461,7,40 ,461,2,-40 ,464,7,39 ,464,2,-39 ,465,7,32 ,465,2,-46 ,467,7,14 ,467,2,-64 ,468,7,-20 ,468,2,-98 ,471,7,-35 ,471,2,-113 ,474,7,1 ,474,2,-77 ,477,7,34 ,477,2,-44 ,491,7,35 ,491,2,-45 ,493,7,38 ,493,2,-48 ,504,7,39 ,504,2,-49 ,507,7,40 ,507,2,-50 ,509,7,41 ,509,2,-51 ,511,7,43 ,511,2,-53 ,513,7,50 ,513,2,-60 ,514,7,56 ,514,2,-66 ,521,7,57 ,521,2,-67 ,527,7,60 ,527,2,-70 ,529,7,79 ,529,2,-89 ,531,7,89 ,531,2,-99 ,533,7,90 ,533,2,-100 ,543,8,-127 ,546,7,92 ,546,2,-102 ,547,7,94 ,547,2,-104 ,549,7,100 ,549,2,-110 ,552,7,101 ,552,2,-111 ,553,7,90 ,553,2,-122 ,556,7,66 ,556,2,-146 ,557,7,51 ,557,2,-161 ,559,7,37 ,559,2,-175 ,562,7,26 ,562,2,-186 ,563,7,21 ,563,2,-191 ,566,7,7 ,566,2,-205 ,567,7,-13 ,567,2,-225 ,569,7,-21 ,569,2,-233 ,573,7,-22 ,573,2,-232 ,576,7,-23 ,576,2,-231 ,578,7,-24 ,578,2,-230 ,578,8,0 ,582,8,-127 ,586,7,-25 ,586,2,-229 ,586,8,0 ,588,7,48 ,588,2,-148 ,589,7,93 ,589,2,-93 ,592,7,90 ,592,2,-90,594,8,127 ,598,7,91 ,598,2,-91 ,602,7,92 ,602,2,-92 ,604,7,93 ,604,2,-93 ,608,7,87 ,608,2,-101 ,611,7,63 ,611,2,-125 ,612,7,20 ,612,2,-168 ,614,7,-24 ,614,2,-212 ,616,7,-33 ,616,2,-221 ,636,7,-32 ,636,2,-222 ,668,7,-31 ,668,2,-223 ,671,7,-29 ,671,2,-225 ,672,7,-27 ,672,2,-227 ,684,7,-28 ,684,2,-226 ,687,7,-27 ,687,2,-227 ,691,7,-26 ,691,2,-228 ,693,7,-24 ,693,2,-226 ,693,8,0 ,694,7,-20 ,694,2,-222 ,697,7,-19 ,697,2,-219 ,699,7,-20 ,699,2,-216 ,701,7,-21 ,701,2,-215 ,703,7,-17 ,703,2,-213 ,704,7,-4 ,704,2,-206 ,707,7,40 ,707,2,-190 ,708,7,119 ,708,2,-119 ,711,7,127 ,711,2,-127 ,721,7,122 ,721,2,-132 ,722,7,116 ,722,2,-138 ,723,7,107 ,723,2,-147 ,724,7,99 ,724,2,-155 ,726,7,93 ,726,2,-161 ,727,7,92 ,727,2,-162 ,728,7,88 ,728,2,-166 ,729,7,83 ,729,2,-171 ,731,7,77 ,731,2,-177 ,732,7,73 ,732,2,-181 ,733,7,58 ,733,2,-184 ,736,7,57 ,736,2,-187 ,738,7,58 ,738,2,-188 ,741,2,-180 ,742,7,40 ,742,2,-162 ,746,7,66 ,746,2,-176 ,748,7,69 ,748,2,-173 ,751,7,82 ,751,2,-162 ,752,7,114 ,752,2,-130 ,754,7,122 ,754,2,-122 ,756,7,123 ,756,2,-123 ,758,7,102 ,758,2,-102 ,761,7,0 ,761,2,0 ,768,7,-46 ,768,2,46 ,771,7,-120 ,771,2,120 ,772,7,-127 ,772,2,127 ,804,7,-124 ,804,2,124 ,805,7,0 ,805,2,0 };
void autonomous() {
	int scan  = 0;
	while (1) {
		while(i==playback[scan]){//playback[scan] represents the time the event happens in. This is a while loop because multiple events may take place in the same frame
			switch(playback[scan+1]){//playback[scan+1] is a motorport which is being modified
				case TL://controls left drive motors
					motorSet(BL, playback[scan+2]);
					motorSet(ML, playback[scan+2]);
					motorSet(TL, playback[scan+2]);
				case TR://controls right drive motors
					motorSet(TR, playback[scan+2]);
					motorSet(MR, playback[scan+2]);
					motorSet(BR, playback[scan+2]);
				//case ARMR: //controls lift motors
					//motorSet(ARML, -1 * playback[scan+2]);
					//motorSet(ARMR, playback[scan+2]);
				//case CLAWL://controls intake motors
					//motorSet(CLAWL,playback[scan+2]);
					//motorSet(CLAWR,-1 * playback[scan+2]);
				case MGR://controls mobile goal lift motors
					motorSet(MGR, playback[scan+2]);
			}
		scan+=3;//Go to the next set of 3 data points in the array
		}
		i++;//Move forward in time
		delay(20);//creates a constant interval between frames
	}
}
/*
/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#define TL 2
#define MR 3
#define BR 4
#define BL 5
#define ML 6
#define TR 7
#define MG 8
#define I 1
#define ARM 9

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */
 void driveDir(int dir) //1 is forward, -1 is backward
 {
   motorSet(TR, dir*127);
   motorSet(MR, dir*127);
   motorSet(BR, dir*127);
   motorSet(TL, -1*dir*127);
   motorSet(ML, -1*dir*127);
   motorSet(BL, -1*dir*127);
 }
 void turnDir(int dir) //1 is right, -1 is left
 {
   if(dir == 1)
   {
     motorSet(TR, 0);
     motorSet(MR, 0);
     motorSet(BR, 0);
     motorSet(TL, 95);
     motorSet(ML, 95);
     motorSet(BL, 95);
   }
   else {
   motorSet(TR, -95);
   motorSet(MR, -95);
   motorSet(BR, -95);
   motorSet(TL, 0);
   motorSet(ML, 0);
   motorSet(BL, 0);
   }
 }
 //The Following are all for arm, MoGo Lift, and Intake
 void armSet(int speed)
 {
   motorSet(ARM, speed);
 }
 void MGRun(int speed)
 {
   motorSet(MG, speed);
 }
 void IntakePickUp(int speed)
 {
   motorSet(I, speed);
 }
  void autonomous() {
 		 armSet(127);
 		 delay(1000);
      driveDir(1);
      delay(1000);
 		 MGRun(100);
 		 delay(2000);
 		 /*driveDir(-1);
      delay(1200);
      turnDir(1);
      delay(1150);
      driveDir(1);
      delay(1000);//rbot now in zones
      int x=0;
      while(x<10) //slides mogo lift hella times lifts off mmogo
      {
        MGRun(-127);
        delay(500);
        MGRun(127);
        delay(500);
        x++;
      }*/

    }
