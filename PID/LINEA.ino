 void leerMUX(){
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

void seguidorLinea(){
  leerMUX();
  pidLinea(100);
  
}

void pidLinea(int lineasPasadas){      //Poner un contadora, para saber cuantas lineas edl medio hasz cruzado y asi saber cuando parar  // FALTA APLICARLE PID
                                    //Para asi saber cuando hacer el control del posocionamiento en el centro de los stacks
 /* if (valoresMux[0][1]>= valorMinNegro && valoresMux[1][1]> valorMinVerde){ //Si ambos sensores estan en el centro
    if (contador< lineasPasadas){
      mover(1,55);
     Serial.println("Avanzar");
    }else{
      // hacer control de posicion
    }
  }else if (valoresMux[0][1]<valorMinNegro){
   
    if (valoresMux[0][0]+10> valoresMux[0][2]){ // Inclinado Derecha
      input[1] = valoresMux[0][1];
      miPID[1].Procesar();
      mover(5,55);
        Serial.println("PID MAS DER");
    }else if(valoresMux[0][2]>valoresMux[0][0]){
      input[1] = valoresMux[0][1];
      miPID[1].Procesar();
      mover(6,55);
     Serial.println("PID MAS IZQ");

       
    }
  }*/

  if (valoresMux[0][1] >= valorMinNegro[0] && valoresMux[0][4]>= valorMinNegro[1]){ //Si ambos sensores estan correctos, avancas
     mover(1,50);
     Serial.println("Avanzar");
  }else if (valoresMux[0][1]<valorMinNegro[0] ){ // PARTE DE ATRAS ESTA DESFAZADA
    if (valoresMux[0][0]>valoresMux[0][2]+50){ // Claramente el valor esta pasado, y se le tinee que meter más potencia a los moteres de la izquierda.
      Serial.println("MÁS DER ABAJO");
     
      mover(5,50);
    }else if (valoresMux[0][2]>valoresMux[0][0]+50){ // MAS DERECHA 
      Serial.println("MAS IZQ ABAJO ");
      mover(6,50);
    }else{ // Cuando la diferencia entre los valores no es mayor, buscamos los sensores de arriba para ver que pedo ramirez.
        if (valoresMux[0][3]>valoresMux[0][5]+50){ // Tambien si hay una clara diferencia en que el valor de la izq sea mayor, Se le necesita meter mas derecha 
          Serial.println("MAS DERECHA ABAJO COMPARACION");
          mover(5,50);
        }else if (valoresMux[0][5]>valoresMux[0][3]+50){ // Diferencia con los sensores de arriba que se tiene que mover más a la derecha 
          Serial.println("MAS IZQUIERDA ABAJO COMPARACION");
          mover(6,50);
        }else{ // Si esta atorado y nada cambio FFFF
          Serial.println("ATORADO");
          mover(0,0);
        }
    }
  }else if (valoresMux[0][4]<valorMinNegro[1]){ // Sensor de arriba no esta bien posicionado
    if (valoresMux[0][5]>valoresMux[0][3]+50){ // Sensor de la derecha esta mas fuerte, por ende se debe de ir a la MAS IZQUIERDA
        Serial.println("MAS IZQUIERDA ARRIBA");
        mover(6,50);
    }else if (valoresMux[0][3]>valoresMux[0][5]+50){ // MAS DERECHA 
        Serial.println("MAS DERECHA ARRIBA"); 
        mover(5,50);
    }else{ // No hay valores arriba que te den un resultado, checas con el sensores de abajo aunque no tiene snetido, porque se supone que hubiera entrado en el primer if. FFF
      Serial.println("FFFF");
    }
  }
}


void acomodarCentro(){
  // Son 38.5 Cm el cuadro negro  // 1.591566 Vueltas debe de dar las llantas // 1910 debe ser los encoders
  while(valoresMux[2][3]<valorMinNegro[0]){
    x = false;
    mover(2,pwm);
  }
  mover(0,pwm);
  limpiarEncoders();
  
  while(valoresMux[2][3]<valorMinNegro[0] || x == false){
    if (valoresMux[2][3]<valorMinNegro[0]){
      x = true;
    }
    mover(1,pwm);
  }
  mover(0,pwm);
  sumaEncoders = (contadorIzq+ contadorDer)/2;

  while(nuevaSuma<sumaEncoders){
    mover(2,pwm);
    nuevaSuma = (contadorIzq + contadorDer)/2;
  }
  mover(0,pwm);

  if (nuevaSuma<3720 || nuevaSuma>3920){
    acomodarCentro(); 
  }
}


void  rectificarte(){
  leerMUX();
   
}

 
