

void linea(int i){

  if (posRobot == 0){ // Si el robot esta viendo hacia el este (derecha)
  
  while (i>0){ 
    
  MUXLinea.valor(0);
  MUXLinea.valor(1);
  MUXLinea.valor(2);
  MUXLinea.valor(3);
  MUXLinea.valor(4);
  MUXLinea.valor(5);
  Serial.println("MUXCENTRO:");
   MUXLineaCentro.valor(1);
  if (MUXLineaCentro.val[1]>valorMinNegro[6] && (millis()-contLinea)>2000 ){ // Si detecha una linea y pasó mas de dos segundo la cuenta
    //Serial.println(MUXLineaCentro.val[1]);
   // Serial.println("i-- ");
    contLinea = millis();
    i--; // restas i, porque ya pasaste una linea 
  }

  if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si ambos sensores tinen la linea centrada
    ElBicho.avanzar(50);
    Serial.println("Avanzar");
  }else{
    if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0])&& (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si se esta yendo a la der, (METE FUERZA DERECHA)
        Serial.println("Más der // Abajo");
        ElBicho.masDerecha(50,10);
    }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3]) ){ // Si se esta yendo a la izq, (METE FUERZA IZQUIERDA)
      Serial.println("Más izq // Abajo ");
      ElBicho.masIzquierda(50,10);
    }else if((MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) ){ // Se esta yendo a la izq  . (DAR izquierda )
       Serial.println("Más izq // Arriba");
         ElBicho.masIzquierda(50,10);
    }else if ((MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0])){ // Se esta yendo a la der (Dar derecha)
      Serial.println("Más der // Arriba");
      ElBicho.masDerecha(50,10);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
      Serial.println("Mas der // Ambos");
      ElBicho.masDerecha(50,10);
    }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
      Serial.println("Mas izq // Ambos");
        ElBicho.masIzquierda(50,10);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
      Serial.println("Mas izq // Uno solo abajo");
      ElBicho.masIzquierda(50,10);
    }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
      Serial.println("Mas der// Uno solo abajo");
        ElBicho.masDerecha(50,10);
    }else if ((MUXLinea.val[4]<= valorMinNegro[2] && MUXLinea.val[5]>= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
      Serial.println("Mas der // Uno solo arriba");
      ElBicho.masDerecha(50,10);
    }else if ((MUXLinea.val[4]>= valorMinNegro[2] && MUXLinea.val[5]<= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
      Serial.println("Mas izq // Uno solo arriba");
        ElBicho.masIzquierda(50,10);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
       if (MUXLinea.val[1]-valorMinNegro[1]>= MUXLinea.val[4]- valorMinNegro[1]){
         Serial.println("Mas izq // caso raro1");
          ElBicho.masIzquierda(50,10);
       }else{
         Serial.println("Mas der // caso raro1");
          ElBicho.masDerecha(50,10);
        
       }
      
    }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
      if(MUXLinea.val[0]-valorMinNegro[0]>= MUXLinea.val[5]-valorMinNegro[3]){
        Serial.println("Mas der // caso raro2");
        ElBicho.masDerecha(50,10);
      }else{
        Serial.println("Mas izq // caso raro2");
          ElBicho.masIzquierda(50,10);
        
      }

    }else{
      Serial.println("No detecta nada ");
      if (MUXLinea.val[2]>=valorMinNegro[4]){ // Esta pasado de verga, muy a la izquierda 
        ElBicho.moverDer(40);

         Serial.println("Acomodarse 1");
      }else if (MUXLinea.val[3]>=valorMinNegro[5]){// Esta pasado de verga, muy a la derecha
         //Poner un timer en este pedo, para que no lo haga para siempre en ciertos casos 
        ElBicho.moverIzq(40);
        Serial.println("Acomodarse 2");
      }else{
          // Que avance un poco, y que retroceda un poco, así en algun momento tiene que tocar alguna línea

        Serial.println("A la chingada, esta en todo blanco fierro");
      }
    }
  }
 }

 if (i == 0){ // Cuando ya llegaste a la linea deseada te tienes que parar
  ElBicho.detener();
  delay(1000);
  fase = 2; // Entras en fase 2
 }
}else{ //Si mira hacia el oeste (Izquierda)


  while (i>0){
    
  MUXLinea.valor(0);
  MUXLinea.valor(1);
  MUXLinea.valor(2);
  MUXLinea.valor(3);
  MUXLinea.valor(4);
  MUXLinea.valor(5);
    MUXLineaCentro.valor(1);
    if (MUXLineaCentro.val[1]>valorMinNegro[6] && (millis()-contLinea)>2000 ){
      Serial.println(MUXLineaCentro.val[1]);
      Serial.println("i-- ");
      contLinea = millis();
      i--;
    }

    if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si ambos sensores tinen la linea centrada
      ElBicho.retroceder(50);
      Serial.println("Retrocede");
    }else{
      if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0])&& (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si se esta yendo a la der, (METE FUERZA DERECHA)
        Serial.println("Más izq // Arriba");
        ElBicho.masIzquierda(50,10);
      }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3]) ){ // Si se esta yendo a la izq, (METE FUERZA IZQUIERDA)
        Serial.println("Más der // Arriba ");
        ElBicho.masDerecha(50,10);
      }else if((MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) ){ // Se esta yendo a la izq  . (DAR izquierda )
        Serial.println("Más der // Abajo");
         ElBicho.masDerecha(50,10);
      }else if ((MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0])){ // Se esta yendo a la der (Dar derecha)
        Serial.println("Más izq // Abajo");
        ElBicho.masIzquierda(50,10);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
        Serial.println("Mas izq // Ambos");
        ElBicho.masIzquierda(50,10);
      }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
        Serial.println("Mas der // Ambos");
        ElBicho.masDerecha(50,10);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
        Serial.println("Mas der // Uno solo arriba");
        ElBicho.masDerecha(50,10);
      }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
        Serial.println("Mas izq// Uno solo arriba");
        ElBicho.masIzquierda(50,10);
      }else if ((MUXLinea.val[4]<= valorMinNegro[2] && MUXLinea.val[5]>= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
        Serial.println("Mas izq // Uno solo abajo");
        ElBicho.masIzquierda(50,10);
      }else if ((MUXLinea.val[4]>= valorMinNegro[2] && MUXLinea.val[5]<= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
        Serial.println("Mas der // Uno solo abajo");
        ElBicho.masDerecha(50,10);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
        if (valorMinNegro[0]-MUXLinea.val[0]>= valorMinNegro[3]-MUXLinea.val[5]){
          Serial.println("Mas izq // caso raro1");
          ElBicho.masIzquierda(50,10);
        }else{
          Serial.println("Mas der // caso raro1");
          ElBicho.masDerecha(50,10);
        }
      
      }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
        if(valorMinNegro[1]-MUXLinea.val[1]>= valorMinNegro[2]-MUXLinea.val[4]){
          Serial.println("Mas der // caso raro2");
          ElBicho.masDerecha(50,10);
      }else{
        Serial.println("Mas izq // caso raro2");
        ElBicho.masIzquierda(50,10);
      }

      }else{
        Serial.println("No detecta nada ");
        if (MUXLinea.val[2]>=valorMinNegro[4]){ // Esta pasado de verga, muy a la izquierda 
          //pidGirar(90);
          ElBicho.moverIzq();
          Serial.println("Acomodarse 1");
        }else if (MUXLinea.val[3]>=valorMinNegro[5]){// Esta pasado de verga, muy a la izquierda
        //pidGirar(90);
          ElBicho.moverDer();
          Serial.println("Acomodarse 2");
        }else{
          ElBicho.detener();
          Serial.println("A la chingada, esta en todo blanco fierro");
        }
      }
    }
  }

  if (i == 0){ // Cuando ya pasaste las lineas que tenías que pasar. Te detienes  
    ElBicho.detener();
    delay(1000);
    fase =2; // Entras en una nueva fase
  }
}
}



 
