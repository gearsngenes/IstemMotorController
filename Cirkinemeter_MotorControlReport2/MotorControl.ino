// Listing all the directions.

void right(){
  digitalWrite(AO1, HIGH);
  digitalWrite(AO2, LOW);
  printval();
}
void left(){
  digitalWrite(AO1, LOW);
  digitalWrite(AO2, HIGH);
  printval();
}
void Stop(){
  digitalWrite(AO1, LOW);
  digitalWrite(AO2, LOW);
  printval();
}
void printval(){
  Serial.print("A1: "); Serial.println(digitalRead(AO1));
  Serial.print("A2: "); Serial.println(digitalRead(AO2));
}


//--------get and Set Speed ----

void getAndSetspeed(){
  speedval= map(yval,0,1023,0,255);
  Serial.print("speedval:");Serial.println(speedval);
  analogWrite(pwmB, speedval);
}

// ----------

void setDirection() {
  if (xval > 700) {
    right();
  }
  else if (xval < 300) {
    left();
  }
  else if (xval >= 300 && xval <= 700) {

    Stop();
  }
}

// print direction

void printDirection(){
  if(xval>700){
    Serial.println("right");
  }
  else if(xval<300){
    Serial.println("left");
  }
}

