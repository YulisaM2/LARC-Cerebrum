void imprimirMUX(){
  for(int i = 0 ;i<4; i+=3){
    for(int j  =0;j<6;j++){
      Serial.print(" i: ");
      Serial.print(i);
      Serial.print(" j: ");
      Serial.print(j);
      Serial.print(" Valor MUX:  ");
      Serial.println(valoresMux[i][j]);
        delay(200);

    }
  }
delay(3000);
}
