#include <Alerta.h>
#include <Sensores.cpp>
#include <DHTesp.h>


//verifica o valor de leitura em relação ao valor definido pelo usuário
void verificarAlerta(int params[3], TempAndHumidity data){ //parametros: params[0] == operador, params[1] == valorDefinido, params[2] == usar temperatura ou humidade,

    switch(params[2]){
        case 1: //usar temperatura
            if(tratarOperacao(params[0], data.temperature, params[1])){
                alertar();
            }
            break;
        case 2: //usar humidade
            if(tratarOperacao(params[0], data.temperature, params[1])){
                alertar();
            }
            break;

        default:
            break;
    }
}

// trata o operador e retorna um booleano com o resultado da operação 
bool tratarOperacao(int operador, int atual, int definido){
    switch(operador){
        case 1:
            return(atual > definido);
        case 2:
            return(atual < definido);
        case 3:
            return(atual == definido);
        default:
            return(0);
    }
}


void alertar(){ // abstração do sistema de alerta
    Serial.println("ALERTA");
}