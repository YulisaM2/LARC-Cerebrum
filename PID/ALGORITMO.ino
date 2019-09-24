void iniciar(){

    actual = millis()-cont;
  while(!(valoresMux[3][4]>valorMinVerde) || actual<8000 ){ // Avanza hasta llegar a la linea verde
    
  actual = millis()-cont;
  leerMUX();
  Serial.print("  Valor Mux: ");
  Serial.println(valoresMux[3][4]);
  Serial.print("Actual");
  Serial.println(actual);
  if (anguloActual()>358 || anguloActual()<2){
    
  //Serial.println("Ho2")
    mover(1,60);
  }else{
    
 Serial.println("Ho1");
    pidGirar();
  }
  }
  
 Serial.println("DETENER");
 
  mover(1,0); // Se detiene  
  limpiarEncoders();
  movimientoEncoders(500,1,60); // Tiene que avanzar un poc
  pidGiro(90);
  //rectificarte();
  fase = 2;
  
}
