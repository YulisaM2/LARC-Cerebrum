void foto(){ //Algoritmo para tomas las fotos
  
// Avanzar hasta la linea negra
  inicio(); 
  pidGirar(90);
// Avanza a la derecha dos lineas
  linea(2);
  //Tomas FOTO

// Cambia su direccion para avanzar hacia la izquierda
  posRobot = 1;

// Recorre las lineas hasta el final
  linea(1);
  //Tomas FOTO
  linea(1);
  //Tomas FOTO
  linea(1);
  //Tomas FOTO

  
//EMPIEZA CODIGO BIEN
  
}

// Movimiento inicial del robot
void inicio(){ 

  MUXLinea.valor(0);
  MUXLinea.valor(1);
  actual = millis()-cont;
  
// Cuando hayan pasado 4 segundos y detecte una linea negra se detendra 
  while(!(MUXLinea.val[0]>valorMinNegro)||actual<4000 && bandera2 == false){
    MUXLinea.valor(0);
    actual = millis()-cont;
    
    Serial.print("  Valor Mux: ");
    Serial.println(MUXLinea.val[0]);
    Serial.print("Actual");
    Serial.println(actual);

// Si se desvía del 0, se ajusta con PID, para que no se mueva chueco
    if (!(angulo()>2 && angulo()<358)){ 
      ElBicho.avanzar(70);
    }else{
      pidGirar(0);
    }

  }
  
// Para que no entre al primer while
  bandera2 = true;

// Valor del medio de la fototransistor
  MUXLinea.valor(1); 

// Si esta en blanco, avanzar hasta que entre al rango
  if (MUXLinea.val[1]<valorMinNegro-300){ 

// Avanza lento hasta que tambien detecte algo de negro
    ElBicho.avanzar(50); 
  }else{
// Si ahora el val[1] esta en negro pero el val[0] se pasó y esta en blanco
    if (MUXLinea.val[0]<valorMinNegro-300){ 
      ElBicho.retroceder(50);
    }
  }

  ElBicho.detener();
  delay(500);
  
}




// Avanzar o retroceder en stack
void stack(int pos, bool x){
  
//Si esta en el 0 del BNO
while (!(angulo()>2 && angulo()<358)){
  
// Avanzar en el stack
  if (x == true){  
    
// Cuando el fototransistor de atras detecte contenedor
  MUXContenedor.valor(4); 
  contadorStack = 1;

// Pasar cierta cantidad de stacks
  while(contadorStack<pos){
    MUXContenedor.valor(4);
      ElBicho.avanzar(60);
      
// Cuando detecta un contenedor por primera vez, suma uno la contadorStack
      if (MUXContenedor.val[4]>400 &&  flag == true){
        contadorStack++;
        flag =false;
      }
      else if (MUXContenedor.val[4]<100){
        flag =true;
      }
  }
  
  ElBicho.detener();
  delay(200);
  
// Cuando esta en el stack que debe de estar, se acomoda en el centro
  acomodarEnStack();

// Retroceder en el stack 
}else{ 

// Retrocede hasta que pase el ultimo stack
    while(pos>1){
      MUXContenedor.valor(0);
      ElBicho.retroceder(60);
      if (MUXContenedor.val[0]>400 && flag  == true){
        flag = false;

// Cuando detecta un espacio en blanco le resta a pos que es la coordenada que envia el codigo de Yulissa
      }else if (MUXContenedor.val[0]<100){
        pos--; 
        flag = true;
      }
    }
    ElBicho.detener();
    delay(200);
    }
  }

// Si no esta en su 0, gira a su 0
  pidGirar(0);
}


void acomodarEnStack(){
  MUXContenedor.valor(0);
  MUXContenedor.valor(4);

// Fototransistor de la izquierda detecha algo avanza hasta no detectar nada
  while(MUXContenedor.val[0]>100){
    ElBicho.avanzar(40); // Super lento
  }
  ElBicho.detener();

// Se acomoda un poco más exacto
  while(MUXContenedor.val[0]<200){
    ElBicho.retroceder(40); 
  }
  // Se puede agregar con el otro sensor 
}


/*
void entrar(int vertical, int lado){ // 0 STACK IZQ // 1 STACK DERECHA 
  if (lado == 0){
    pidGirar(270);
  }else if (lado == 1){
    pidGirar(90);
  }
  while(vertical>0){
    leerMUX();
    ElBicho.avanzar(50);
    if (// Valor del mux salido){
    vertical--;
  }
  }
}*/


void mrChampions(){ 
  MUXLineaAzul.valor(1);
 //
  while (MUXLineaAzul.val[1]<400){
      MUXLineaAzul.valor(1);
    if(!(angulo()<272 && angulo()>268)){
      
        pidGirar(270);
      }else{
      ElBicho.avanzar(60);
    }
  }

  ElBicho.detener();
  delay(1000);
  CR7();

}

void CR7(){ //Acomodarse en línea azul
  
  MUXLineaAzul.valor(1);
  MUXLineaAzul.valor(5);
  while(MUXLineaAzul.val[1]>400){
      MUXLineaAzul.valor(1);
      ElBicho.retroceder(40);
  }
  ElBicho.detener();
  ElBicho.avanzarEncoder(100,40);
  ElBicho.detener();
  delay(1000);

  while (MUXLineaAzul.val[5]>300){
    motorIA.limpiarEncoder();
    motorDA.limpiarEncoder();
    MUXLineaAzul.valor(5);
    ElBicho.moverDer(40);
  }
  total += abs(motorIA.contador);
  total += abs(motorDA.contador);
  ElBicho.detener();
  delay(1000);
  MUXLineaAzul.valor(0);
  while(MUXLineaAzul.val[0]>300){
    motorIA.limpiarEncoder();
    motorDA.limpiarEncoder();
    MUXLineaAzul.valor(0);
    ElBicho.moverIzq(40);
  }
  ElBicho.detener();
  delay(500);
  total += abs(motorIA.contador);
  total += abs(motorDA.contador);
  motorIA.limpiarEncoder();
  motorDA.limpiarEncoder();
  while(total>0){
    ElBicho.moverDer(40);
    total -= abs(motorDA.contador);
    total -= abs(motorIA.contador);
  }

  ElBicho.detener();
  delay(1000);
  //MOVER ELEVADOR

  //Se puede hacer otra funcion para acomodarse con los fototransistores, ya que estas centrado

}


void deus(int lineas,int vert, int stack, int lado){
  linea(lineas);
  //entrar(vert, lado);

}

void avanzarAMitad(){
  ElBicho.avanzarEncoder(1000,60);
  ElBicho.detener();
  pidGirar(90);
}

void avanzarALinea(){
  MUXLinea.valor(1);
  while(MUXLinea.val[1]<500){ //Hasta que detecte una linea negra
      ElBicho.avanzar(60);
  }
  ElBicho.detener();
}

void coordenada(int x, int y, int i, int j){ // i,j  son las coordenadas a donde tengo que ir 

  //Preguntar a yulissa, cuando saber si vas a un stack en donde tienes  que girar 180 grados

if (j == 0 ){ //Tiene que ir a los barcos
  

  stack(y,0); // Retrocede de los stacks 

  if (i>x){ // Si a donde tengo que ir es a la derecha{
    posRobot = 0;
    linea((i-x)/2); // va a tener que recorred una cierta cantidad de lineas
  }else{ // Si el robot tiene que ir a la izquierda
    posRobot = 1;
    linea((x-i)/2); // El robot va a ir a la izquierda recorriedno una cierta cantidad de lineas.
  }


avanzarAMitad(); // avanzar a la mitad de las lineas, para acomodarte a "la mitad" de los barcos 
pidGirar(90); // Gira el elevador hacia los barcos
mrChampions(); // función que pone stacks 
//Poner stacks, ploxxxxxxxx 




}else{ // Tiene que ir a los stacks de los barcos

  pidGirar(0); // Gira hacia su 0
  avanzarALinea(); // Avanza a la linea

  if (i>x){ // Tienes que ir a la derecha
    posRobot = 0; 
    linea((i-x)/2);
  }else{ // Tiene que ir a la izquierda
    posRobot = 1;
    linea((x-i)/2);
  }

  //Una vez que eta posicionado, tiene que avanzar dentro del stack

  stack(j,1); // Avanza a la posición del stack al que tiene que ir
  //Agarra stack, y procede con lo de arriba de poner stack

}
   


}
