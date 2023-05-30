#ifndef Sensores_h
#define Sensores_h
#include <Alerta.h>
#include <DHTesp.h>

class Sensor{

    public:
        Sensor(int8_t pin);
        int getTemp();
        bool verificarConexao();
        TempAndHumidity fazerLeitura();
        int getIntervaloLeitura();
    
};

#endif