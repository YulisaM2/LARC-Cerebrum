


#ifndef PID_Original_h
#define PID_Original_h
#define LIBRARY_VERSION 0.1.0

class PID
{
    
public:
    PID();
    PID(double*,double*,double*,double,double,double,int);
    bool Procesar();
    void Limites(double, double);
    void Constantes(double, double, double);
    void quitarIntegral();
    void quitarDerivada();
    void counterTrue();
    double obtenerKp();
    double obtenerKi();
    double obtenerKd();
    
private:
    double Kp,Ki,Kd;
    double *miOutput;    // Variables
    double *miInput;
    double *miSetPoint;
    double ultimoInput;
    
    unsigned long ultimoTiempo;
   
    double outputMinimo,outputMaximo; // Valores Máximos permitidos
    
    double error;
    double errorIntengral; // Suma de la Ki
    double errorDerivada; // Suma de la Kd
    
    int caso;
    bool counter;
    
};

#endif

