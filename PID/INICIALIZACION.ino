void inicializarMotores(){
  for(int i= 0;i<8;i++){
    pinMode(motores[i],OUTPUT);
  }
}

void inicializarEncoderes(){
  for(int j = 0;j<4;j++){
    pinMode(encoder[j], INPUT_PULLUP);
  }
attachInterrupt(digitalPinToInterrupt(encoder[0]),doEncoderIF,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[1]),doEncoderIA,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[2]),doEncoderDF,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[3]),doEncoderDA,CHANGE);
}


void inicializarPID(){

  for(int i = 0;i<3;i++){
    
    miPID[i] = PID(&input[i],&setPoint[i],&output[i],Kp[i],Ki[i],Kd[i],i);
  }
     miPID[0].Limites(90,230);     // GIROS
     miPID[1].Limites(0, 13);    //LINEA   
}

void inicializarMUX(){
  for(int i =0;i<4;i++){
    for(int j = 0;j<3;j++){
      pinMode(mux[i][j],OUTPUT);
    }
  }
}

void inicializarServo(){
  for(int i = 0;i<2;i++){
    servo[i].attach((i+2));
  }
}

void inicializarBNO(){

   Serial.println("Orientation Sensor Test"); Serial.println("");
  
  /* Initialise the sensor */
 if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  delay(1000);
    
  bno.setExtCrystalUse(true);
 sensors_event_t event;
  bno.getEvent(&event);
 BNOSetPoint = event.orientation.x;
}

void doEncoderIF() {

  // look for a low-to-high on channel A
  if (digitalRead(encoder[0]) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[1]) == LOW) {
      contadorIzq--;         // CW
    }
    else {
      contadorIzq++;         // CCW
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[1]) == HIGH) {
      contadorIzq--;          // CW
    }
    else {
      contadorIzq++;       // CCW
    }
  }
  //Serial.println (contadorIzq, DEC);
  // use for debugging - remember to comment out
}
void doEncoderIA() {


  // look for a low-to-high on channel B
  if (digitalRead(encoder[1]) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder[0]) == HIGH) {
      contadorIzq--;         // CCW
    }
    else {
      contadorIzq++;         // CW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[0]) == LOW) {
      contadorIzq--;          // CCW
    }
    else {
      contadorIzq++;          // CW
    }
  }
}
void doEncoderDF() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder[2]) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[3]) == LOW) {
      contadorDer--;         // CCW
    }
    else {
      contadorDer++;         // CW
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[3]) == HIGH) {
      contadorDer--;          // CW
    }
    else {
      contadorDer++;       // CCW
    }
  }
  //Serial.println (contadorDer, DEC);
  // use for debugging - remember to comment out
}
void doEncoderDA() {

  // look for a low-to-high on channel B
  if (digitalRead(encoder[3]) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder[2]) == HIGH) {
      contadorDer--;         // CW
    }
    else {
      contadorDer++;         // CCW
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[2]) == LOW) {
      contadorDer--;          // CW
    }
    else {
      contadorDer++;          // CCW
    }
  }
}
