/*
  Teste incial de comunicação com sensores
    - Identificar os tipos de Materiais usando a lógica pelos sensores 
    - Usar sensores como Botões
    - Lógica para implementar: 
        Identificar primeiro se é metal, se não for, testar o segundo sensor para identicicar o vidro, e se não for,
        testar o terceiro sensor para identificar o plástico
    - SEN1 : Metal
    - SEN2 : Vidro
    - SEN3 : Plástico
*/

/*Bibliotecas*/
#include <Arduino.h>

/*Definiçõ dos pinos do ESP32*/
#define SEN0 GPIO_NUM_5
#define SEN1 GPIO_NUM_12
#define SEN2 GPIO_NUM_13
#define SEN3 GPIO_NUM_14


void setup() 
{
  pinMode(SEN0, INPUT);
  pinMode(SEN1, INPUT);
  pinMode(SEN2, INPUT);
  pinMode(SEN3, INPUT);

  Serial.begin(9600);
  
}

void loop() 
{
  Serial.println("Aguardando material...");
  delay(1000);
  while (1)
  { 
    //if (digitalRead(SEN0) == HIGH)
    //{
     // Serial.println ("Identificando Material...");
      //delay(1000);

      if (digitalRead(SEN1) == HIGH)
      {
        Serial.println ("Material Detectado: METAL");
        delay(1000);
      }
      else
      {
        if (digitalRead(SEN2) == HIGH)
        {
          Serial.println("Material Detectado: VIDRO");
          delay(1000);
        }
        else
        {
          if (digitalRead(SEN3) == HIGH)
          {
            Serial.println ("Material Detectado: PLÁSTICO");
            delay(1000);
          }
          else
          {
            Serial.println("Material não identificado");
            delay(1000);
          }
        }
      }
    //}
  }
}

