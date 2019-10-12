void inicializarImanes(){
  pinMode(35,OUTPUT);
  pinMode(36,OUTPUT);
}
void inicializarMotores(){
  for(int i= 0;i<8;i++){
    pinMode(motores[i],OUTPUT);
  }
}
void inicializarEncoders(){
  for(int j = 0;j<4;j++){
    pinMode(encoder[j], INPUT_PULLUP);
  }
attachInterrupt(digitalPinToInterrupt(encoder[0]),doEncoderIF,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[1]),doEncoderIA,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[2]),doEncoderDF,CHANGE);
attachInterrupt(digitalPinToInterrupt(encoder[3]),doEncoderDA,CHANGE);
}

void doEncoderIF() {

  // look for a low-to-high on channel A
  if (digitalRead(encoder[0]) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[1]) == LOW) {
      motorDA.contador--;         // CW
      motorDF.contador--;
    }
    else {
      motorDA.contador++;         // CCW
      motorDF.contador++;
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[1]) == HIGH) {
      motorDA.contador--;          // CW
      motorDF.contador--;
    }
    else {
      motorDA.contador++;       // CCW
      motorDF.contador++;
    }
  }
  //Serial.println (motorIA.contador, DEC);
  // use for debugging - remember to comment out
}

void doEncoderIA() {


  // look for a low-to-high on channel B
  if (digitalRead(encoder[1]) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder[0]) == HIGH) {
      motorDA.contador--;         // CCW
      motorDF.contador--;
    }
    else {
      motorDA.contador++;         // CW
      motorDF.contador++;
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[0]) == LOW) {
      motorDA.contador--;          // CCW
      motorDF.contador--;
    }
    else {
      motorDA.contador++;          // CW
      motorDF.contador++;
    }
  }
}

void doEncoderDF() {
  // look for a low-to-high on channel A
  if (digitalRead(encoder[2]) == HIGH) {

    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[3]) == LOW) {
      motorIA.contador--;         // CCW
      motorIF.contador--; 
    }
    else {
      motorIA.contador++;         // CW
      motorIF.contador++; 
    }
  }

  else   // must be a high-to-low edge on channel A
  {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[3]) == HIGH) {
      motorIA.contador--;          // CW
      motorIF.contador--; 
    }
    else {
      motorIA.contador++;       // CCW
      motorIF.contador++; 
    }
  }
  //Serial.println (motorDA.contador, DEC);
  // use for debugging - remember to comment out
}

void doEncoderDA() {

  // look for a low-to-high on channel B
  if (digitalRead(encoder[3]) == HIGH) {

    // check channel A to see which way encoder is turning
    if (digitalRead(encoder[2]) == HIGH) {
      motorIA.contador--;         // CW
      motorIF.contador--; 
    }
    else {
      motorIA.contador++;         // CCW
      motorIF.contador++; 
    }
  }

  // Look for a high-to-low on channel B

  else {
    // check channel B to see which way encoder is turning
    if (digitalRead(encoder[2]) == LOW) {
      motorIA.contador--;          // CW
      motorIF.contador--; 
    }
    else {
      motorIA.contador++;          // CCW
      motorIF.contador++; 
    }
  }
}

void inicializarPID(){

  for(int i = 0;i<3;i++){
    
    miPID[i] = PID(&input[i],&setPoint[i],&output[i],Kp[i],Ki[i],Kd[i],i);
  }
     miPID[0].Limites(70,230);     // GIROS
     miPID[1].Limites(0, 15);    //LINEA   
}


void inicializarMUX(){
  MUXLinea.inicializarMUX();
  MUXLineaCentro.inicializarMUX();
  MUXLineaAzul.inicializarMUX();
  MUXContenedor.inicializarMUX();
}

void inicializarBNO(){

   Serial.println("Orientation Sensor Test"); 
   Serial.println("");
  
  /* Initialise the sensor */
 if(!bno.begin())
  {
    /* There was a problem detecting the BNO055 ... check your connections */
    Serial.print("Ooops, no BNO055 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  /*
 while(orientationStatus() != 3)
  {
    Serial.println("NCal");
  }
    Serial.print("SCal");
*/

 
  sensors_event_t event;
  bno.getEvent(&event);
  BNOSetPoint = event.orientation.x;
  delay(1000);
  

}
