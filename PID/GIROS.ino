void dondeGirar(int anguloDes, int pwm){

  if (anguloDes > anguloActual()){
    diferenciaX = anguloDes - anguloActual();
    if(diferenciaX<180){

       /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      mover(4,pwm);                 // GIRO DERECHA    
    }
    else{
      mover(3,pwm);                 // GIRO IZQUIERDA

    }
  }else if(anguloDes< anguloActual()){
    diferenciaX = anguloActual()-anguloDes;
    if (diferenciaX<180){

     /*if (pwm== 250 && diferenciaX<=5){
        output = 100;
     }*/
      mover(3,pwm);                 // GIRO IZQUIERDA 
      
    }else{

      mover(4,pwm);                 // GIRO DERECHA    
    }
  }
}

void pidGiro(double angulo){
  setPoint[0] = angulo;
  input[0] = double(anguloActual());

  miPID[0].Procesar();
  dondeGirar(setPoint[0],output[0]);
}

void pidGirar(){
  while(anguloActual()>2 && anguloActual()<358){
    pidGiro(0);
  }
}
