#include <iostream>
#include "Baraja.h"
#include "Jugador.h"
#include <sstream>

using namespace std;

vector<Baraja> barajas;
vector<def_carta>puntos;
vector<carta>mesa;
int num_barajas;

void crearCartas();
carta sacarCarta();
void mostarMesa();
int contarPuntosMesa();
int llenarMesa();

int main()
{
    crearCartas();
    return 0;
}

void crearCartas(){
    carta x,y;
    int seguir_jugando = 1;
    Jugador player = Jugador(1000);
    int apuesta = 0, def_apuesta;
    Baraja a = Baraja();
    string opcion;
    int condMesa, ganaste;

    cout<<"Con cuantas barajas va a jugar? ";
    cin >> num_barajas;
    for(int i = 0; i < num_barajas; i++){
        barajas.push_back(a);
    }
    cout<<"se crearon "<<barajas.size()<<" barajas"<<endl;
    x = sacarCarta();
    y = sacarCarta();
    mesa.push_back(sacarCarta());
    cout<<"Ingrese cuanto quiere apostar: ";
    cin>>def_apuesta;
    if(player.apostar(def_apuesta)){
        apuesta += def_apuesta;
    }
    player.iniciarJuego(x,y);
    while(seguir_jugando){
        player.verMano();
        mostarMesa();
        cout<<"Puntos en mano: "<<player.contarPuntos()<<endl;
        cout<<"probabilidad de pasarse de 21: "<<player.verProbabilidad()<<endl;
        cout<<"apostado: "<<apuesta<<endl;
        if(player.contarPuntos() > 21){
            seguir_jugando = 0;
        }
        else{
            cout<<"Quieres pedir otra carta?(si/no): ";
            cin>>opcion;
            if(opcion == "si"){
                x = sacarCarta();
                player.pedirCarta(x);
            }
            else{
                seguir_jugando = 0;
                condMesa = llenarMesa();
                if(condMesa){
                    if(player.contarPuntos() == 21){
                        cout<<"Empatados"<<endl;
                        player.sumarGanancia(apuesta);
                    }
                    else{
                        cout<<"Perdiste"<<endl;
                    }
                }
                else{
                    cout<<"Ganaste"<<endl;
                    player.sumarGanancia(apuesta*2);
                }
            }
        }
    }
    player.verSaldo();
}

carta sacarCarta(){
    int random;
    carta x;
    do{
        random = rand()%num_barajas;
        x = barajas[random].sacarCarta();
    }while(x.carta == "none");
    return x;
}

void mostarMesa(){
    vector<carta>::iterator it;

    cout<<"cartas en mesa: ";
    for(it = mesa.begin(); it != mesa.end(); ++it){
        cout<<(*it).carta<<" ";
    }
    cout<<endl;
}

int contarPuntosMesa(){
    vector<carta>::iterator it;
    int a;
    int condAs = 0;
    int suma = 0;

    for(it = mesa.begin(); it != mesa.end(); ++it){
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

int llenarMesa(){
    carta a;
    int puntos;

    puntos = contarPuntosMesa();
    while(contarPuntosMesa() < 21){
        a = sacarCarta();
        mesa.push_back(a);
        mostarMesa();
    }
    if(contarPuntosMesa() == 21){
        cout<<"puntos de mesa "<<contarPuntosMesa()<<endl;
        return 1;
    }
    else{
        cout<<"La mesa pierde"<<endl;
        return 0;
    }


}
