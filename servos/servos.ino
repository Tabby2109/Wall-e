#include <Servo.h>

Servo servo1;  //servo de giro de base
Servo servo2;   //servo de giro de brazo
Servo servo3;   //servo de giro de antebrazo

//Ajustar valores de servos de posición cero
int home_servo1=0;
int home_servo2=0;
int home_servo3=180;

//Definicion de variables de la cinematica inversa

const float pi=3.1415;
float x;  //coordenadas de la pinza del robot
float y;
float z;

float l1=12.8;  //longitud de brazo
float l2=13.7;  //longitud de antebrazo
float H=11.3;  //altura de base

float Axis1;  //Giro de la base en RAD
float Axis2;  //Giro del brazo en RAD
float Axis3;  //Giro del antebrazo en RAD

float Axis1Grados;   //Giro de la base en Grados
float Axis2Grados;   //Giro del brazo en Grados
float Axis3Grados;   //Giro del antebrazo en Grados

void setup() {
Serial.begin(9600);

// asignacion de servos a pines y centrar servos
servo1.attach(5);
servo1.write(home_servo1);
servo2.attach(6);
servo2.write(home_servo2);
servo3.attach(7);
servo3.write(home_servo3);

}
void PosicionCero()
{
servo1.write(home_servo1);
servo2.write(home_servo2*0.6);
servo3.write(home_servo3);
}

void Coordenada(float x, float y, float z)
{
float M;
Axis1=atan2(y,x);  
M=(pow(x,2)+pow(y,2)+pow(z-H,2)-pow(l1,2)-pow(l2,2))/(2*l1*l2);
Axis3=atan2(sqrt(1-pow(M,2)),M);
Axis2=atan2(z-H,sqrt(pow(x,2)+pow(y,2)))-atan2(l2*sin(Axis3*180/pi),l1+l2*cos(Axis3*180/pi));
Axis1Grados=Axis1*180/pi;   //Giro de la base en Grados
Axis2Grados=90-Axis2*180/pi;   //Giro del brazo en Grados + conversion a angulos catia/servos
Axis3Grados=180-Axis3*180/pi;   //Giro del antebrazo en Grados + conversion a angulos catia/servos
servo1.write((home_servo1+Axis1Grados));
servo2.write((home_servo2+Axis2Grados)*0.6);
servo3.write(home_servo3+Axis3Grados);
Serial.println("Coordenada: ");
Serial.print("Axis1 en grados: ");
Serial.println(Axis1Grados);
Serial.print("Axis2 en grados: ");
Serial.println(Axis2Grados);
Serial.print("Axis3 en grados: ");
Serial.println(Axis3Grados);
delay(3000);
}
void loop() 
{
  
  
  Coordenada(0, 26.5, 10);

  delay(100);

  
}