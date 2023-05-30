#include <Sensores.h>


class Sensor
{
private:
    DHTesp dhtsensor;

public:
    Sensor(int8_t pin){ //inicializa o sensor configurando pinagem e definindo tipo de sensor
        dhtsensor.setup(pin, DHTesp::DHT22);
    }

    int getTemp(){ // utilizada para verificar se o sensor está recebendo dados.
        return this->dhtsensor.getTemperature();
    }

    bool verificarConexao(){ //verifica se o sensor está conectado ao pin certo.
        return(String(getTemp()) != "nan");
    }

    TempAndHumidity fazerLeitura(){ //Retorna um objeto com dados de temperatura e humidade.
        return this->dhtsensor.getTempAndHumidity();
    }
    int getIntervaloLeitura(){
        this->dhtsensor.getMinimumSamplingPeriod();
    }


};

    