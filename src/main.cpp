#include <Arduino.h>
#include <Alerta.h>
#include <Sensores.h>
#include <DHTesp.h>

const int DHT_PIN = 15; //definido pino D15 no dispositivo
Sensor sen;

int parametrosAlerta[3] = {  //parametros para alerta, hardcoded para facilitar
1,  // Operador: 1 == > || 2 == < || 3 == =
27, // Valor para comparação
1   // Temperatura ou Humidade: 1 == Temperatura || 2 == Humidade
};

unsigned long msComeco = 0;         //valores necessário para o multitasking
unsigned long msUltimaLeitura = 0;
unsigned long intervaloSensor = 0;

void setup() {
  Sensor sen = Sensor(15);
  Serial.begin(115200);
  intervaloSensor=sen.getIntervaloLeitura(); //intervalo minimo entre leituras no sensor escolhido
}

void loop() {
  msComeco = millis();
  if(msComeco - msUltimaLeitura > intervaloSensor){ //configurando multitasking, nesse caso não obrigatório por usar somente um sensor
    msUltimaLeitura = msComeco;
    TempAndHumidity leitura = sen.fazerLeitura();
    verificarAlerta(parametrosAlerta, leitura);
  }

}