#include <AFMotor.h>


//INCLUINDO BIBLIOTECAS 

//#include <Ultrasonic.h>
//#include <AFMotor.h>

//PINOS MOTOR 
//AF_DCMotor motor1(1); //Seleção do Motor 1
//AF_DCMotor motor2(2); //Seleção do Motor 2
AF_DCMotor motor3(2); //Seleção do Motor 1
AF_DCMotor motor4(4); //Seleção do Motor 2
//PINOS IR 
int sIR[] = {52, 51, 49, 50,53};


int setpoint = 1024;  
/*Posições do Vetor:

    [0] = Direita 
    [1] = Esquerda 
    [2] = Frente
    [3] = Tras
    [4] = Centro
*/

const int Centro = A12;
const int Curva_Esq = A13;
const int Curva_Dir = A7;
const int V_Esq = A11;
const int SL_Esq = A10;
const int SL_Dir = A8;
const int V_Dir = A10;

// Pino digital conectado ao sensor HSRO4
//Ultrasonic ultrasonic(37, 39); //Frente Baixo

void setup() {
//DECLARANDO O SENSOR IR COMO INPUT
    for (int i = 0; i <= 4; i++) {
   pinMode(sIR[i], INPUT);
   }

//PINOS LED PORTA ANALOGICA
      /
     
      pinMode(A9, OUTPUT); //VerdeEsquerda
      pinMode(A10, OUTPUT); //SLEsquerda
      pinMode(A8, OUTPUT); //SLDireita
      pinMode(A12, OUTPUT); //VerdeDireita 
      pinMode(A7, OUTPUT); //90Direita  

      Serial.begin(9600);// Setup Serial Monitor
      digitalWrite(Centro, HIGH);
} 
void loop(){
  
  acele();
  
}


