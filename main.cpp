#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Servo.h>
#include <Ultrasonic.h>
 
#define SSID "IFCE_Pesquisa01"
#define PASSWD "sobral@pesquisa"

unsigned long int last_time = millis();

const uint16_t port = 5000;
const char * host = " 192.168.70.105";
/*Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;*/
//Define os pinos trig e echo:
int pin_trig = 12; //recebe o retorno
int pin_echo = 13; //emite o som

//Cria-se o objeto:
Ultrasonic ultrasonic(pin_trig, pin_echo);


void setup(){
    Serial.begin(9600);
 
    WiFi.begin(SSID,PASSWD);
    while (WiFi.status() != WL_CONNECTED){delay(100);}
 
    Serial.print("IP do ESP32: ");
    Serial.println(WiFi.localIP());


    /*servo1.attach(13);
    servo2.attach(15);
    servo3.attach(2);
    servo4.attach(4);*/
}
 
void loop(){
    WiFiClient client;

 
    if (!client.connect(host, port)) 
    {
        Serial.println("Falha de conexao");
        delay(1000);
        return;
    }
 
    Serial.println("Conectado!");
 
    // client.print("Papel");

    client.print(ultrasonic.read(CM));
    delay(300);
    
    /*client.println(" Motor 1");
    for(int i=0;i<=179; i++)
    {
        servo1.write(i);
        client.println(i);
        delay(30);
    }

    for(int i=179; i>=0; i--)
    {
        servo1.write(i);
        client.println(i);
        delay(30);
    }
    client.println(" Motor 2");
    for(int i=0;i<=179; i++)
    {
        servo2.write(i);
        client.println(i);
        delay(30);
    }

    for(int i=179; i>=0; i--)
    {
        servo2.write(i);
        client.println(i);
        delay(30);
    }

    client.println(" Motor 3");
    for(int i=0;i<=179; i++)
    {
        servo3.write(i);
        client.println(i);
        delay(30);
    }

    for(int i=179; i>=0; i--)
    {
        servo3.write(i);
        client.println(i);
        delay(30);
    }

    client.println(" Motor 4");
    for(int i=0;i<=179; i++)
    {
        servo4.write(i);
        client.println(i);
        delay(30);
    }

    for(int i=179; i>=0; i--)
    {
        servo4.write(i);
        client.println(i);
        delay(30);
    }*/
 
    Serial.println("Desconectando...");
    client.stop();
 
    Serial.print("Aguardando 15 segundos para proximo envio:");
    while ((millis()-last_time) < 15000){delay(100);}
    last_time = millis();
}