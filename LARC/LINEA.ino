/*void leerMUX(){
 for(int i = 0;i<4;i++){
  for(int j = 0,count = 0;count<6;count++,j++){
    r0 = bitRead(count,0);    // use this with arduino 0013 (and newer versions)     

    r1 = bitRead(count,1);    // use this with arduino 0013 (and newer versions)     

    r2 = bitRead(count,2);    // use this with arduino 0013 (and newer versions)     

    digitalWrite(mux[i][0], r0);


    digitalWrite(mux[i][1], r1);

    digitalWrite(mux[i][2], r2);
    //Serial.print(" i:    ");
    //Serial.println(count);
    val = analogRead(muxAnalogo[i]);
    valoresMux[i][j] = val;


    }
  }
}
*/
void seguidorLinea(){
  leerMUX();
  linea(100);
  
}

void linea(int i){

  MUXLinea.valor(0);
  MUXLinea.valor(1);
  MUXLinea.valor(2);
  MUXLinea.valor(3);
  MUXLinea.valor(4);
  MUXLinea.valor(5);
  MUXLineaCentro.valor(1);


  Serial.println("Linea Nuevo");

  if (posRobot == 0){
  
  while (i>0){
  leerMUX();
  if (MUXLineaCentro.val[1]>valorMinNegro[6] && (millis()-contLinea)>2000 ){
    Serial.println(MUXLineaCentro.val[1]);
    Serial.println("i-- ");
    contLinea = millis();
    i--;
  }

  if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si ambos sensores tinen la linea centrada
    Thanos.avanzar(50);
    Serial.println("Avanzar");
  }else{
    if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0])&& (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si se esta yendo a la der, (METE FUERZA DERECHA)
        Serial.println("Más der // Abajo");
        Thanos.masDerecha(50,1);
    }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3]) ){ // Si se esta yendo a la izq, (METE FUERZA IZQUIERDA)
      Serial.println("Más izq // Abajo ");
      Thanos.masIzquierda(50,1);
    }else if((MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) ){ // Se esta yendo a la izq  . (DAR izquierda )
       Serial.println("Más izq // Arriba");
         Thanos.masIzquierda(50,1);
    }else if ((MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0])){ // Se esta yendo a la der (Dar derecha)
      Serial.println("Más der // Arriba");
      Thanos.masDerecha(50,1);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
      Serial.println("Mas der // Ambos");
      Thanos.masDerecha(50,1);
    }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
      Serial.println("Mas izq // Ambos");
        Thanos.masIzquierda(50,1);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
      Serial.println("Mas izq // Uno solo abajo");
      Thanos.masIzquierda(50,1);
    }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
      Serial.println("Mas der// Uno solo abajo");
        Thanos.masDerecha(50,1);
    }else if ((MUXLinea.val[4]<= valorMinNegro[2] && MUXLinea.val[5]>= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
      Serial.println("Mas der // Uno solo arriba");
      Thanos.masDerecha(50,1);
    }else if ((MUXLinea.val[4]>= valorMinNegro[2] && MUXLinea.val[5]<= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
      Serial.println("Mas izq // Uno solo arriba");
        Thanos.masIzquierda(50,1);
    }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
       if (valorMinNegro[0]-MUXLinea.val[0]>= valorMinNegro[3]- MUXLinea.val[5]){
          Serial.println("Mas der // caso raro1");
          Thanos.masDerecha(50,1);
       }else{
        Serial.println("Mas izq // caso raro1");
          Thanos.masIzquierda(50,1);
       }
      
    }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
      if(valorMinNegro[1]-MUXLinea.val[0][1]>= valorMinNegro[2]-MUXLinea.val[4]){
        Serial.println("Mas izq // caso raro2");
          Thanos.masIzquierda(50,1);
      }else{
        Serial.println("Mas der // caso raro2");
        Thanos.masDerecha(50,1);
      }

    }else{
      Serial.println("No detecta nada ");
      if (MUXLinea.val[2]>=valorMinNegro[4]){ // Esta pasado de verga, muy a la izquierda 
         //pidGirar(90);
         Thanos.detener();
         Serial.println("Acomodarse 1");
      }else if (MUXLinea.val[3]>=valorMinNegro[5]){// Esta pasado de verga, muy a la izquierda
        //pidGirar(90);
          Thanos.detener();
        Serial.println("Acomodarse 2");
      }else{
        Thanos.detener();
        Serial.println("A la chingada, esta en todo blanco fierro");
      }
    }
  }
 }

 if (i == 0){
  Serial.println("i == 0");
  Thanos.detener();
  delay(1000);
 }
}else{ //Si mira hacia el oeste


  while (i>0){
    leerMUX();
    if (MUXLineaCentro.val[1]>valorMinNegro[6] && (millis()-contLinea)>2000 ){
      Serial.println(MUXLineaCentro.val[1]);
      Serial.println("i-- ");
      contLinea = millis();
      i--;
    }

    if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si ambos sensores tinen la linea centrada
      Thanos.retroceder(50);
      Serial.println("Retrocede");
    }else{
      if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0])&& (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Si se esta yendo a la der, (METE FUERZA DERECHA)
        Serial.println("Más izq // Arriba");
        Thanos.masIzquierda(50,1);
      }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4] >=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3]) ){ // Si se esta yendo a la izq, (METE FUERZA IZQUIERDA)
        Serial.println("Más der // Arriba ");
        Thanos.masDerecha(50,1);
      }else if((MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) ){ // Se esta yendo a la izq  . (DAR izquierda )
        Serial.println("Más der // Abajo");
         Thanos.masDerecha(50,1);
      }else if ((MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])&&(MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0])){ // Se esta yendo a la der (Dar derecha)
        Serial.println("Más izq // Abajo");
        Thanos.masIzquierda(50,1);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
        Serial.println("Mas izq // Ambos");
        Thanos.masIzquierda(50,1);
      }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
        Serial.println("Mas der // Ambos");
        Thanos.masDerecha(50,1);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
        Serial.println("Mas der // Uno solo arriba");
        Thanos.masDerecha(50,1);
      }else if ((MUXLinea.val[1]<=valorMinNegro[1] && MUXLinea.val[0]>=valorMinNegro[0]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){
        Serial.println("Mas izq// Uno solo arriba");
        Thanos.masIzquierda(50,1);
      }else if ((MUXLinea.val[4]<= valorMinNegro[2] && MUXLinea.val[5]>= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
        Serial.println("Mas izq // Uno solo abajo");
        Thanos.masIzquierda(50,1);
      }else if ((MUXLinea.val[4]>= valorMinNegro[2] && MUXLinea.val[5]<= valorMinNegro[3])&&(MUXLinea.val[0]<=valorMinNegro[0] && MUXLinea.val[1] <= valorMinNegro[1])){
        Serial.println("Mas der // Uno solo abajo");
        Thanos.masDerecha(50,1);
      }else if ((MUXLinea.val[1]>=valorMinNegro[1] && MUXLinea.val[0]<=valorMinNegro[0]) && (MUXLinea.val[4]>=valorMinNegro[2] && MUXLinea.val[5]<=valorMinNegro[3])){ // Se esta yendo ambos a la derecha 
        if (valorMinNegro[0]-MUXLinea.val[0]>= valorMinNegro[3]-MUXLinea.val[5]){
          Serial.println("Mas izq // caso raro1");
          Thanos.masIzquierda(50,1);
        }else{
          Serial.println("Mas der // caso raro1");
          Thanos.masDerecha(50,1);
        }
      
      }else if ((MUXLinea.val[0]>=valorMinNegro[0] && MUXLinea.val[1]<=valorMinNegro[1]) && (MUXLinea.val[4]<=valorMinNegro[2] && MUXLinea.val[5]>=valorMinNegro[3])){ // Se esta yendo completamvnte a la izq
        if(valorMinNegro[1]-MUXLinea.val[1]>= valorMinNegro[2]-MUXLinea.val[4]){
          Serial.println("Mas der // caso raro2");
          Thanos.masDerecha(50,1);
      }else{
        Serial.println("Mas izq // caso raro2");
        Thanos.masIzquierda(50,1);
      }

      }else{
        Serial.println("No detecta nada ");
        if (MUXLinea.val[2]>=valorMinNegro[4]){ // Esta pasado de verga, muy a la izquierda 
          //pidGirar(90);
          Thanos.detener();
          Serial.println("Acomodarse 1");
        }else if (MUXLinea.val[3]>=valorMinNegro[5]){// Esta pasado de verga, muy a la izquierda
        //pidGirar(90);
          Thanos.detener();
          Serial.println("Acomodarse 2");
        }else{
          Thanos.detener();
          Serial.println("A la chingada, esta en todo blanco fierro");
        }
      }
    }
  }

  if (i == 0){
    Serial.println("i == 0");
    Thanos.detener();
    delay(1000);
  }
}
}

void  rectificarte(){
  leerMUX();
   
}

 
