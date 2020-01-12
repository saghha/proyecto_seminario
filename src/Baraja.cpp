#include "Baraja.h"
#include <iostream>

using namespace std;

Baraja::Baraja()
{
    carta a;
    for(int i=0; i<4;i++){
        a.pinta = "Pica";
        switch(i){
            case 0: a.pinta = "Pica";
            break;
            case 1: a.pinta = "Corazon";
            break;
            case 2: a.pinta = "Diamante";
            break;
            case 3: a.pinta = "Trebol";
            break;
        }
        for(int j=0; j<13;j++){
            switch(j){
                case 0: {
                    a.carta = "A";
                    cartas.push_back(a);
                }
                break;
                case 1: {
                    a.carta = "2";
                    cartas.push_back(a);
                }
                break;
                case 2: {
                    a.carta = "3";
                    cartas.push_back(a);
                }
                break;
                case 3: {
                    a.carta = "4";
                    cartas.push_back(a);
                }
                break;
                case 4: {
                    a.carta = "5";
                    cartas.push_back(a);
                }
                break;
                case 5: {
                    a.carta = "6";
                    cartas.push_back(a);
                }
                break;
                case 6: {
                    a.carta = "7";
                    cartas.push_back(a);
                }
                break;
                case 7: {
                    a.carta = "8";
                    cartas.push_back(a);
                }
                break;
                case 8: {
                    a.carta = "9";
                    cartas.push_back(a);
                }
                break;
                case 9: {
                    a.carta = "10";
                    cartas.push_back(a);
                }
                break;
                case 10: {
                    a.carta = "J";
                    cartas.push_back(a);
                }
                break;
                case 11: {
                    a.carta = "Q";
                    cartas.push_back(a);
                }
                break;
                case 12: {
                    a.carta = "K";
                    cartas.push_back(a);
                }
                break;
            }
        }
    }
}

Baraja::~Baraja()
{
    this->cartas.clear();
}

void Baraja::verBaraja(){
    vector<carta>::iterator it;

    for(it = this->cartas.begin(); it != this->cartas.end(); ++it){
        cout<<"pinta: "<<(*it).pinta<<", carta: "<<(*it).carta<<endl;
    }
}

carta Baraja::sacarCarta(){
    int card;
    carta a;
    if(this->cartas.size() > 0){
        card = rand()%this->cartas.size();
        //cout<<"carta numero "<<card<<" del mazo"<<endl;
        a = this->cartas[card];
        //cout<<"pinta: "<<a.pinta<<", carta: "<<a.carta<<endl;
        this->cartas.erase(this->cartas.begin()+card);
        //a = this->cartas[card];
        //cout<<"Carta 2 => pinta: "<<a.pinta<<", carta: "<<a.carta<<endl;
        //cout<<"total de cartas restantes "<<this->cartas.size()<<endl;
        return a;
    }
    else{
        a.pinta = "blanco";
        a.carta = "none";
        return a;
    }

}

int Baraja::cartasRestantes(){
    return this->cartas.size();
}
