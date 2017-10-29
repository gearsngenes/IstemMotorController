//-----------Listing all the directions.

void Counterclockwise(){ //BO1 on while BO2 off gives CounterClock
  digitalWrite(BO1, HIGH);
  digitalWrite(BO2, LOW);
  printval();
}
void Clockwise(){  //BO1 off while BO2 on gives Clock
  digitalWrite(BO1, LOW);
  digitalWrite(BO2, HIGH);
  printval();
}
void Stop(){
  digitalWrite(BO1, LOW);
  digitalWrite(BO2, LOW);
  printval();
}
//------------------------

void printval(){  //Print which input pin is on for the TB66 for future Debug test
  Serial.print("B1: "); Serial.println(digitalRead(BO1));
  Serial.print("B2: "); Serial.println(digitalRead(BO2));
}


//--------get and Set Speed ----
void getAndSetspeed(){
  speedval= map(yval,0,1023,0,255);//Converts yval from analog value to a PWM value (0-255)
  
  Serial.print("speedval:");Serial.println(speedval);
  
  analogWrite(pwmB, speedval);  //Sends speedval*3/255 V to PWMB on TB66, controls RPM of motor
}

// ----------Direction control
void setDirection() {
  if (xval > 700) {  //If forward on X-axis of joystick, turn Counterclocwise
    Counterclockwise();
  }
  else if (xval < 300) {  //If Backward on X-axis of joystick, turn Clocwise
    Clockwise();
  }
  else if (xval >= 300 && xval <= 700) {  //If in the middle of X-axis, stop
    Stop();
  }
}
//--------------------------------

// print direction
void printDirection(){
  if(xval>700){
    Serial.println("Counterclockwise");
  }
  else if(xval<300){
    Serial.println("Clockwise");
  }
}

