
#include <Servo.h>
#include <Elevador.h>
#include <MUX.h>
#include <Motor.h>
#include <PID_Original.h>
#include <Robot.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
//MOTORES
Motor motorDF(9,8);
Motor motorIF(4,5);
Motor motorDA(6,7);
Motor motorIA(11,10);
//SERVO
Servo myserv;
//ELEVADOR
Elevador Lift(myserv);
//MUX
MUX MUXLinea(22,23,24,4); // LINEA NEGRA NORMAL.       // 0,1,2 frente 3,4,5 Atras  
MUX MUXLineaCentro(25,26,27,5); // LINEA PERPENDICULAR NEGRA // Solo 0,1,2
MUX MUXLineaAzul(28,29,39,6); // ACOMODARSE CON LINEA AZUL  // 0,1,2,3,4,5
MUX MUXContenedor(43,42,38,7); // SABER SI TIENE UN CONTENEDOR // FRENTE 0,1,2 ATRAS ,3,4,5
//ROBOT
Robot Thanos(motorIF,motorDF,motorDA,motorIA);
//BNO
Adafruit_BNO055 bno = Adafruit_BNO055(55);
//PID
double input[3] = {}, setPoint[3] = {}, output[3] = {};
double Kp[3] = {1.79,0.13,0}, Ki[3] = {0.05,0,0}, Kd[3] = {0.001,0,0};
//MOTORES 
int motores[8] = {9,8,4,5,6,7,11,10}; // 1-ARR IZQ- 2 ARR DER - ABAJO DER - ABAJO IZQ
int encoder[4] = {2,3,19,18};
//FOTOTRANSISTORES 
int valorMinVerde = 700;
int valorMinNegro[7] = {340,510,450,500,400,400,300};
//CONTADORES ENCODERS 
int sumaEncoders = 0;
int nuevaSuma;
//BNO055
double BNOSetPoint = 0;
//GIROS
int diferenciaX = 0;
//LINEA
int contador = 0;
int val;

int as;
int fase = 1;
//CONTADOR
int cont;
int actual;
int contLinea = 0;
//POSICION DEL ROBOT
int posRobot = 0;  // 0 frente Este /////// 1 frente Oeste
//STACKS
int contadorStack = 0;
bool flag; 









PID miPID[3] = {};


void setup(){
  Serial.begin(9600);
  //setPoint[1] = 600.0;
  inicializarMotores();
  inicializarEncoders();
  inicializarPID();
  inicializarMUX();
  inicializarBNO();
  Lift.inicializarServo(7,555,2325);

  cont = millis();
  contLinea = cont;

}

void loop(){
// YA QUEDO GIRO OTRA VEZ PTM

if (fase == 1){
  foto();

  
}else if (fase == 2){
  linea(2);
  
}else if (fase == 3){
  Thanos.detener();

}
 
}
