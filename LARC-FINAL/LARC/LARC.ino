
#include <Servo.h>
#include <Elevador.h>
#include <MUX.h>
#include <Motor.h>
#include <PID_Original.h>
#include <Robot.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

//PINES GENERALES 

// Objetos de Motores 
Motor motorIF(9,8); 
Motor motorDF(4,5); 
Motor motorDA(6,7);
Motor motorIA(11,10); 
//SERVO
Servo myservo;
//Objetos de Elevador 
Elevador Halo(myservo);
//Objetos de MUX
MUX MUXLinea(22,23,24,4); // LINEA NEGRA NORMAL.       // 0,1,2 frente 3,4,5 Atras  
MUX MUXLineaCentro(25,26,27,5); // LINEA PERPENDICULAR NEGRA // Solo 0,1,2
MUX MUXLineaAzul(28,29,39,6); // ACOMODARSE CON LINEA AZUL  // 0,1,2,3,4,5
MUX MUXContenedor(43,42,38,7); // SABER SI TIENE UN CONTENEDOR // FRENTE 0,1,2 ATRAS ,3,4,5
//Objeto de Robot
Robot ElBicho(motorIF,motorDF,motorDA,motorIA);
//BNO
Adafruit_BNO055 bno = Adafruit_BNO055(55);
double BNOSetPoint = 0; 
//PID
double input[3] = {}, setPoint[3] = {}, output[3] = {};
double Kp[3] = {1.79,0.03,0}, Ki[3] = {0.05,0,0}, Kd[3] = {0.001,0,0};
//MOTORES 
int motores[8] = {9,8,4,5,6,7,11,10}; 
int encoder[4] = {2,3,19,18};
//FOTOTRANSISTORES 
int valorMinVerde = 500;
int valorMinNegro[7] = {170,580,350,550,400,400,300}; // valor de negro para ciertos fototransistores
//GIROS
int dif = 0;
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
//LINEA AZUL
int total = 0;
//INICIO
bool bandera2 = 0; //Inicio


void inicializarMotores();
void inicializarEncoders();
void inicializarPID();
void inicializarMUX();
void inicializarBNO();
void foto();
void avanzarEnStack(int);
void acomodarEnStack();
void avanzarPrincipio();
void deus(int,int,int, int);
void mrChampions();
void doEncoderIF();
void doEncoderIA();
void doEncoderDF();
void doEncoderDA();
void seguidorDeLinea();
void linea(int);
void rectificarte();
void dondeGirar(int,int);
void pidGiro(double);
void pidGirar(int);
void CR7();
int angulo();
int orientationStatus();

//Objetos para el PID
PID miPID[3] = {};


void setup(){
  
  Serial.begin(9600);
  
  //Inicializacion
  
  inicializarMotores();
  inicializarEncoders();
  inicializarImanes();
  inicializarPID();
  inicializarMUX();
  inicializarBNO();
  Halo.inicializarServo(12,500,2220);

  //Elevador lo pone en su 0
  
  myservo.write(0);
  Halo.setTiempo(0);

  //Contadores actualizados
  
  cont = millis();
  contLinea = cont;

  
  delay(300);
  Serial.println("Prendido");

}



void loop(){

  
// Imprimir MUX

   while (1){

  
    MUXLinea.val(0);s
    MUXLinea.val(1);
    MUXLinea.val(2);
    MUXLinea.val(3);
    MUXLinea.val(4);
    MUXLinea.val(5);
   }


   
if (fase == 1){

foto(); // Toma de fotos
   
  
}else if (fase == 2){
  ElBicho.detener();
  //linea(2);
  
}else if (fase == 3){
  ElBicho.detener();

}
 
}
