#include "at91sam3x8.h"
#include "system_sam3x.h"
#include "exceptions.h"



double diff=0;
int angle=0;
void rotateServo(double one , double two) {

  // calculate the difference between the sensor values
   diff = (two - one);

  // adjust the servo position based on the calculated difference
  if (diff >= 0.14) {
    turnServo(180);
    angle = 180;
  } else if (diff >= 0.12) {
   turnServo(170);
   angle =170;
  } else if (diff >= 0.1) {
   turnServo(160);
   angle = 160;
  } else if (diff >= 0.08) {
    turnServo(150);
    angle =150;
  } else if (diff >= 0.06) {
   turnServo(140);
   angle =140;
  } else if (diff >= 0.04) {
    turnServo(130);
    angle =130;
  } else if (diff >= 0.02) {
    turnServo(120);
    angle =120;
  } else if (diff >= 0) {
    turnServo(110);
    angle =110;
  } else if (diff >= -0.02) {
    turnServo(100);
    angle =100;
  } else if (diff >= -0.04) {
    turnServo(90);
    angle =90;
  } else if (diff >= -0.06) {
    turnServo(80);
    angle =80;
  } else if (diff >= -0.08) {
    turnServo(70);
    angle =70;
  } else if (diff >= -0.1) {
    turnServo(60);
    angle =60;
  } else if (diff >= -0.12) {
    turnServo(50);
    angle =50;
  } else if (diff >= -0.14) {
    turnServo(40);
    angle =40;
  } else if (diff >= -0.16) {
    turnServo(30);
    angle =30;
  } else if (diff >= -0.18) {
    turnServo(20);
    angle =20;
  } else if (diff >= -0.2) {
    turnServo(10);
    angle =10;
  } else {
    turnServo(0);
    angle =0;
  }
 
}