void dondeGirar(int anguloDes, int pwm){

  if (anguloDes > angulo()){
    dif = anguloDes - angulo();
    if(diferenciaX<180){

       /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      ElBicho.girarDer(pwm);                // GIRO DERECHA    
    }
    else{
      ElBicho.girarIzq(pwm);                 // GIRO IZQUIERDA

    }
  }else if(anguloDes< angulo()){
    diferenciaX = angulo()-anguloDes;
    if (diferenciaX<180){

     /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      ElBicho.girarIzq(pwm);                 // GIRO IZQUIERDA 
      
    }else{

      ElBicho.girarDer(pwm);               // GIRO DERECHA    
    }
  }
}

void pidGiro(double ang){
  setPoint[0] = ang;
  input[0] = double(angulo());

  miPID[0].Procesar();
  Serial.print(input[0]),
  Serial.print(" ");
  Serial.println(output[0]);
  dondeGirar(setPoint[0],output[0]);
}

void pidGirar(int ang ){
  Serial.println("PID");
  if (ang == 0){
    
  while(angulo()>2 && angulo()<358){
    pidGiro(0);
    Serial.println(angulo());

  }
  
    Serial.println("a");
    ElBicho.detener();
    delay(600);
    
  }else if (ang == 90 ){
 Serial.println(angulo());
   

  while(!(angulo()<92 && angulo()>88)){
    pidGiro(90);
  
  }
    ElBicho.detener();
    delay(600);

    posRobot = 0;
    
  }else if (ang == 180){
    
  while(!(angulo()<182 && angulo()>178)){
    pidGiro(180);
  }
  
    ElBicho.detener();
    delay(600);
    
  }else if (ang == 270){
   
  while(!(angulo()<272 && angulo()>268)){
    pidGiro(270);
  }
  
    ElBicho.detener();
    delay(600);
    
   
    
  }
}
