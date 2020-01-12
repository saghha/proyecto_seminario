#include "Jugador.h"

Jugador::Jugador()
{
    this->saldo = 0;
}

Jugador::Jugador(int saldo){
    this->saldo = saldo;
}

Jugador::~Jugador()
{
    this->mano.clear();
}

void Jugador::pedirCarta(carta a){
    this->mano.push_back(a);
    return;
}

int Jugador::contarPuntos(){
    int condAs = 0;
    int a;
    int suma = 0;
    vector<carta>::iterator it;

    for(it = this->mano.begin(); it != this->mano.end(); ++it){
        if((*it).carta == "A"){
            condAs = 1;
            suma += 11;
        }
        else if((*it).carta == "J" || (*it).carta == "Q" || (*it).carta == "K"){
            suma += 10;
        }
        else{
            istringstream((*it).carta)>>a;
            suma += a;
        }
    }
    if(condAs == 1 && suma > 21){
        suma -= 10;
    }
    return suma;
}

float Jugador::verProbabilidad(){
    int puntos = this->contarPuntos();
    int fallo = 0;
    int valorAs, temp;
    float prob;

    if(puntos > 10){
        valorAs = 1;
    }
    else{
        valorAs = 11;
    }
    for(int i = 1; i <= 10; i++){
        if(i == 1){
            temp = puntos + valorAs;
            if(temp > 21){
                fallo ++;
            }
        }
        else if(i == 10){
            temp = puntos + i;
            if(temp > 21){
                fallo += 4;
            }
        }
        else{
            temp = puntos + i;
            if(temp > 21){
                fallo ++;
            }
        }
    }
    prob = (float)fallo/13.0;
    return prob;
}

void Jugador::iniciarJuego(carta a,carta b){
    this->mano.push_back(a);
    this->mano.push_back(b);

    return;
}

void Jugador::verMano(){
    vector<carta>::iterator it;

    for(it = this->mano.begin(); it != this->mano.end(); ++it){
        cout<<"Carta: "<<(*it).carta<<endl;
    }
}

int Jugador::apostar(int apuesta){
    if(apuesta < this->saldo){
        this->saldo -= apuesta;
        return 1;
    }
    else{
        cout<<"no tiene suficiente saldo"<<endl;
        return 0;
    }
}

void Jugador::sumarGanancia(int ganancia){
    this->saldo += ganancia;
}

void Jugador::verSaldo(){
    cout<<"El balance final es de: "<<this->saldo<<endl;
}
