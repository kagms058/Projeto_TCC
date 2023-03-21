#include <Arduino.h>
#include <WiFi.h>
 
#define SSID "IFCE_Pesquisa01"
#define PASSWD "sobral@pesquisa"

unsigned long int last_time = millis();

const uint16_t port = 5000;
const char * host = "192.168.70.101";
 
void setup(){
    Serial.begin(9600);
 
    WiFi.begin(SSID,PASSWD);
    while (WiFi.status() != WL_CONNECTED){delay(100);}5
 
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
}
 
void loop(){
    WiFiClient client;
 
    if (!client.connect(host, port)) {
        Serial.println("Falha de conexao");
        delay(1000);
        return;
    }
 
    Serial.println("Conectado!");
 
    client.print("Papel");
 
    Serial.println("Desconectando...");
    client.stop();
 
    Serial.print("Aguardando 15 segundos para proximo envio:");
    while ((millis()-last_time) < 15000){delay(100);}
    last_time = millis();
}