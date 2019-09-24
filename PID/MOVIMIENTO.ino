
void mover(int direccion,int pwm) 
{
  
  switch (direccion)
  {

    case 0:                                   // DETENER
    direccion = 0;
      for(int i = 0; i<8;i++){
        analogWrite(motores[i],pwmCero);
      }
      
    break;
  
  
    case 1:                                  // FRENTE
    
      direccion = 1;
      for(int i = 0; i < 8; i++){
        if(i==0 ||i==2 || i==4 || i==6)
          analogWrite(motores[i],pwm);
        else
          analogWrite(motores[i],pwmCero);         
        } 
        
    break;
    
    case 2:                                  // ATRAS 
    
      direccion = 2;
      for(int i = 0; i < 8; i++){
        if(i==0 || i==2 || i==4 || i==6)
          analogWrite(motores[i], pwmCero);
        else
          analogWrite(motores[i], pwm);         
      }
      
    break;
        
    case 3:                                  // GIRAR DERECHA
    
      direccion = 3;
      for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==5||i==6)
          analogWrite(motores[i], pwm);
        else
          analogWrite(motores[i], pwmCero);         
      }
      
    break;
    
    case 4:                                   // GIRAR IZQUIERDA
    
      direccion = 4;
      for(int i = 0; i < 8; i++){
        if(i ==0||i==3||i==5||i==6)
          analogWrite(motores[i], pwmCero);
        else
          analogWrite(motores[i], pwm);         
      }
      
    break; 

   case 6:                                  // MAS IZQ
    
      direccion = 5;
      for(int i = 0; i < 8; i++){
        if(i==0 ||i==2 || i==4 || i==6)
          analogWrite(motores[i],pwm);
        else
          analogWrite(motores[i],pwmCero);         
         
        if (i==2 ||i==4){
          analogWrite(motores[i],70 /*output[1]*/);         
        }
  }
    break;
    
   case 5:                                  // MAS DER
    
      direccion = 6;
      for(int i = 0; i < 8; i++){
        if(i==0 ||i==2 || i==4 || i==6)
          analogWrite(motores[i],pwm);
        else
          analogWrite(motores[i],pwmCero);         
        if (i==0 || i==6){
          analogWrite(motores[i],70/*output[1]*/);         
        }
      }
    break;
    
     
  }
}

/*
void movimientoEncoders(int val, int i, int pwm ){
  while(contadorIzq<val){
    mover(i,pwm);
    Serial.print(" ENCODER: ");
    Serial.println(contadorIzq);
  }
}*/




void limpiarEncoders(){
  contadorIzq = 0;
  contadorDer = 0;
  
}
