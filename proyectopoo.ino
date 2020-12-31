#include <NewPing.h>
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
#include <Servo.h>                // Incluye la libreria Servo
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
Servo me;                    // Crea el objeto me con las caracteristicas de Servo
Servo an;
Servo co;
Servo in;
Servo pu;
int dato=0;
int dato2;
void setup() 
{ 
  Serial.begin(9600);
  me.attach(7,600,1500);    // Asocia el servo1 al pin 6, define el min y max del ancho del pulso  
  me.write(180);
  an.attach(5,600,1500);
  an.write(180);
  co.attach(4,600,1500);
  co.write(0);
  in.attach(3,600,1500);
  in.write(0);
  pu.attach(2,600,1500);
  pu.write(0);
}
  
void loop() 
{
  //delay(1000);
  // Obtener medicion de tiempo de viaje del sonido y guardar en variable uS
  int uS = sonar.ping_median();
  // Imprimir la distancia medida a la consola serial
  //Serial.print("Distancia: ");
  // Calcular la distancia con base en una constante
  dato2=uS / US_ROUNDTRIP_CM;
  Serial.println(dato2);
  //Serial.println("cm");

  
    if(Serial.available() >= 0){
    dato=Serial.read();
    delay(1000);
  }
  
  switch(dato){
    case '1':
    pulgar();
    break;
    case '2':
    indice();
    break;
    case '3':
    corazon();
    break;
    case '4':
    anillo();
    break;
    case '5':
    menique();
    break;
    case '0':
    agarrar();
    break;
    case '7':
    pistola();
    break;
    case'8':
    paz();
    break;
    case'9':
    diablo();
    break;
    default:
    break;
                        
  }

  } 
  void menique(){
    me.write(0);
    delay(2000);
    me.write(180);
  }
  void anillo(){
    an.write(0);
    delay(2000);
    an.write(180);
  }
  void corazon(){
    co.write(180);
    delay(2000);
    co.write(0);
  }
  void indice(){
    in.write(180);
    delay(2000);
    in.write(0);
  }
  void pulgar(){
    pu.write(180);
    delay(2000);
    pu.write(0);
  }
  void agarrar(){
    me.write(0);
    an.write(0);
    co.write(180);
    in.write(180);
    pu.write(180);
    delay(2000);
    me.write(180);
    an.write(180);
    co.write(0);
    in.write(0);
    pu.write(0);
  }
  void diablo(){
    an.write(0);
    co.write(180);
    delay(2000);
    an.write(180);
    co.write(0);
  }
  void paz(){
    me.write(0);
    an.write(0);
    pu.write(180);
    delay(2000);
    me.write(180);
    an.write(180);
    pu.write(0);
  }
  void pistola(){
    me.write(0);
    an.write(0);
    in.write(180);
    pu.write(180);
    delay(3000);
    me.write(180);
    an.write(180);
    in.write(0);
    pu.write(0);
  }

