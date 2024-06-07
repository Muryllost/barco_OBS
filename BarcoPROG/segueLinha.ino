
  /*Posições do Vetor:

      [0] = Direita 
      [1] = Esquerda 
      [2] = frente  
      [3] = tras
      [4] = centro

  */

  //ATENÇÃO 0 = PRETO E 1 = BRANCO 
  void acele()
  {   

      //SE O SENSOR DA ESQUERDA ESTIVER DESLIGADO
      if (digitalRead(acD[1]) == 1) {

        //Enquanto seu valor estiver desligado, ele gira para a direita
          while (digitalRead(acD[0]) > 20) {
            Serial.println("Virar esq");
            robot_right(130);
            robot_left(70);
            delay(50);
          }
      }

      //SE O SENSOR DA DIREITA ESTIVER DESLIGADO
        if (digitalRead(sIR[1]) == 1) {

        //Enquanto seu valor estiver desligado, ele gira para a esquerda
        while (digitalRead(sIR[0]) > 20) {
          Serial.println("Virar Dir");
          robot_left(130);
          robot_rigt(70);
          delay(30);
        }
      }

        if (digitalRead(sIR[2]) == 1) {
          //enquanto seu valor estiver desligado, ele gira 
          while (digitalRead(sI[2]) > 20){
            Serial.println("desacelera");
            robot_left(50);
            robot_right(50);
            delay(30)
          }
        } 



  // EM CASO DO ROBÔ ESTAR PERFEITAMENTE ALINHADO, OU NO BRANCO
      if(digitalRead(sIR[2]) == 1) { 
        Serial.println("Segue reto");
        robot_forward(100);
        delay(20);
      }
  }
