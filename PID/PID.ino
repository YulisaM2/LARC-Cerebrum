#include <PID_Original.h>
#include <Servo.h>

#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>

//PID
double input[3] = {}, setPoint[3] = {}, output[3] = {};
//CONSTANTES
double Kp[3] = {1.79,0.13,0}, Ki[3] = {0.05,0,0}, Kd[3] = {0.001,0,0};
//MOTORES
int motores[8] = {4,5,9,8,6,7,11,10}; // 1-ARR IZQ- 2 ARR DER - ABAJO DER - ABAJO IZQ
int encoder[4] = {2,3,19,18};
int pwm = 100;
int pwmCero = 0;
int direccion;
//MUX
int mux[4][3] = {{22,23,24},{25,26,27},{28,29,39},{43,42,38}};  // 0:    VERDE   1:  NEGRO      2:x
int r0,r1,r2;
int count = 0;
int muxAnalogo[4] = {4,5,6,7};
int valoresMux[4][6] = {0}; 
//FOTOTRANSISTORES 
int valorMinVerde = 750;
int valorMinNegro[2] = {600,550};
//CONTADORES ENCODERS 
 int contadorIzq = 0;
 int contadorDer = 0;
int sumaEncoders = 0;
bool x = false;
int nuevaSuma;
//BNO055
Adafruit_BNO055 bno = Adafruit_BNO055(55);
double BNOSetPoint = 0;
//GIROS
int diferenciaX = 0;
//LINEA
int contador = 0;
int val;
//CONTENEDORES 
int contenedores[4][6] = {{1,1,1,1,1,1},    //1,1,//1,1,//1,1
                        {1,1,1,1,1,1},    //1,1,//1,1,//1,1
                        {1,1,1,1,1,1},    //1,1,//1,1,//1,1
                        {1,1,1,1,1,1}};   //1,1,//1,1,//1,1

int as;
int fase = 0;
//CONTADOR
int cont;
int actual;

Servo servo[2];
PID miPID[3] = {};
//INICIALIZACIONES 

void inicializarPID();
void inicializarMotores();
void inicializarEncoderes();
void inicializarServo();
void inicializarBNO();
void leerMUX();
void movimientoEncoders(int ,int,int );
void iniciar();
int anguloActual();
void imprimirMUX();
void dondeGirar(int,int);
void pidGiro(double);
void pidGirar();
void doEncoderIF();
void doEncoderIA();
void doEncoderDF();
void doEncoderDA();
void seguidorLinea();
void pidLinea(int);
void acomodarCentro();
void rectificarte();
void mover(int,int);
void limpiarEncoders();


void setup() {
  inicializarPID();
  inicializarMotores();
  inicializarEncoderes();
  inicializarServo();
  inicializarBNO();
  inicializarMUX();
  Serial.begin(9600);
  setPoint[1] = 600.0;
  delay(500);
  
  cont = millis();
}

void loop() {

  //CODIGO FINAL

  /*if (fase == 1){
    iniciar();
  }else if (fase == 2 ){
    
  }*/
  /* if (anguloActual()<88 || anguloActual()>92){
    pidGiro(90);
    Serial.print(anguloActual());
    Serial.print(" ");
    Serial.println(output[0]);
  }else{
    mover(0,0);
    miPID[0].counterTrue();
  }*/
   

 //leerMUX();
  //imprimirMUX();
  //iniciar();
   
  //seguidorLinea();
 analogWrite(motores[4],90);
    analogWrite(motores[5],0);
   // analogWrite(motores[2],90);
   // analogWrite(motores[3],0);
    Serial.print("Contador 1:      ");
Serial.println(contadorIzq);
Serial.print("Contador 2:      ");
Serial.println(contadorDer);






}
