#include<Wire.h>

//Endereço em hexadecimal do sensor MPU 6050
const int ENDERECO_SENSOR=0x68;  

int acelX, acelY, acelZ;

void setup()
{
  Serial.begin(9600);

  //Inicializa a biblioteca Wire
  Wire.begin();
  Wire.beginTransmission(ENDERECO_SENSOR);
  Wire.write(0x6B); 
   
  //Inicializa o sensor
  Wire.write(0); 
  Wire.endTransmission(true);
}
void loop()
{
  //Começa uma transmissão com o sensor
  Wire.beginTransmission(ENDERECO_SENSOR);

  //Enfilera os bytes a ser transmitidos para o sensor
  //Começando com o registor 0x3B
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)

  //Finaliza e transmite os dados para o sensor. O false fará com que seja enviado uma mensagem 
  //de restart e o barramento não será liberado
  Wire.endTransmission(false);
  
  //Solicita os dados do sensor, solicitando 14 bytes, o true fará com que o barramento seja liberado após a solicitação 
  //(o valor padrão deste parâmetro é true)
  Wire.requestFrom(ENDERECO_SENSOR, 14, true);  
  
  //Armazena o valor dos sensores nas variaveis correspondentes
  acelX = Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)  
  acelY = Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)  
  acelZ = Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)  

  //Printa o valor X do acelerômetro na serial
  Serial.print("Acelerômetro X = "); 
  Serial.print(acelX);
 
  //Printa o valor Y do acelerômetro na serial
  Serial.print(" \tY = "); 
  Serial.print(acelY);
   
  //Printa o valor Z do acelerômetro na serial
  Serial.print(" \tZ = "); 
  Serial.println(acelZ);   
  delay(200);
}
