void foto(){
  avanzarPrincipio(); 
  Thanos.avanzarEncoder(450,60);  
  Thanos.detener();
  delay(200); // Tiene que avanzar un poc
  pidGirar(90);
  linea(2);
  //Tomas FOTO
  posRobot = 1;
  linea(1);
  //Tomas FOTO
  linea(1);
  //Tomas FOTO
  linea(1);
  //Tomas FOTO
  //rectificarte();
  fase = 2;
}






void avanzarEnStack(int pos){
  while(contadorStack<pos){
      Thanos.avanzar(60);
      if (MUXContenedor.val[1]>400 &&  flag == true){
        contadorStack++;
        flag =false;
      }
      else if (MUXLinea.valor(1)<100){
        flag =true;
      }
  }
  Thanos.detener();
  delay(200);
  acomodarEnStack();
}

void acomodarEnStack(){
  while(MUXLinea.valor(0)>100){// valor de arriba
    Thanos.avanzar(40); // Super lento
  }
  Thanos.detener();
  while(MUXLinea.valor(0)<200){
    Thanos.retroceder(40); //Se acomoda un poco más exacto
  }
  if (MUXLinea.valor(4)>150){ // si el que esta en medio de dos stacks tiene algo en frente

  }
}

void avanzarPrincipio(){
  actual = millis()-cont;
  while(!(valoresMux[3][4]>valorMinVerde) || actual<4000 ){ // Avanza hasta llegar a la linea verde
    
    actual = millis()-cont;
    leerMUX();
    Serial.print("  Valor Mux: ");
    Serial.println(valoresMux[3][4]);
    Serial.print("Actual");
    Serial.println(actual);
    if (!(angulo()>2 && angulo()<358)){
    
      Thanos.avanzar(60);
    }else{
    
      Serial.print("angulo: ");
      Serial.println(angulo());
      pidGirar(0);
    }
  }
  
  Serial.println("DETENER");
  Thanos.detener();
  delay(200);
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
    Thanos.avanzar(50);
    if (// Valor del mux salido){
    vertical--;
  }
  }
}*/

void deus(int lineas,int vert, int stack, int lado){
  linea(lineas);
  //entrar(vert, lado);


}
