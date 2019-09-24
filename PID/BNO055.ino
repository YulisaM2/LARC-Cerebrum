int anguloActual(){
  int angulo = 0;
  sensors_event_t event; 
  bno.getEvent(&event);
  angulo = int(event.orientation.x);
  angulo -= BNOSetPoint;
  if (angulo <0){
    angulo +=  360;
  }
  return angulo;
}
