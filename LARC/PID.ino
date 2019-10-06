void dondeGirar(int anguloDes, int pwm){

  if (anguloDes > angulo()){
    diferenciaX = anguloDes - angulo();
    if(diferenciaX<180){

       /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      Thanos.girarDer(pwm);                // GIRO DERECHA    
    }
    else{
      Thanos.girarIzq(pwm);                 // GIRO IZQUIERDA

    }
  }else if(anguloDes< angulo()){
    diferenciaX = angulo()-anguloDes;
    if (diferenciaX<180){

     /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      Thanos.girarIzq(pwm);                 // GIRO IZQUIERDA 
      
    }else{

      Thanos.girarDer(pwm);               // GIRO DERECHA    
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
    if(angulo()>2 && angulo()<358){
  while(angulo()>2 && angulo()<358){
    pidGiro(0);
    Serial.println(angulo());

  }
  }else{
    Serial.println("a");
    Thanos.detener();
    }
  }else if (ang == 90 ){
 Serial.println(angulo());
    if(!(angulo()<92 && angulo()>88)){

  while(!(angulo()<92 && angulo()>88)){
    pidGiro(90);
  }
  }else{
    Thanos.detener();
    posRobot = 0;
    }
  }else if (ang == 180){
    if(!(angulo()<182 && angulo()>178)){
  while(!(angulo()<182 && angulo()>178)){
    pidGiro(180);
  }
  }else{
    Thanos.detener();
    }
  }else if (ang == 270){
   if(!(angulo()<272 && angulo()>268)){
  while(!(angulo()<272 && angulo()>268)){
    pidGiro(270);
  }
  }else{
    Thanos.detener();
    posRobot = 1;
    }
    
  }
}
