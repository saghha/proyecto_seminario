#ifndef JUGADOR_H
#define JUGADOR_H
#include "definicion.h"
#include <iostream>


class Jugador
{
    public:
        Jugador();
        Jugador(int saldo);
        virtual ~Jugador();
        void pedirCarta(carta a);
        float verProbabilidad();
        void iniciarJuego(carta a, carta b);
        int apostar(int apuesta);
        int contarPuntos();
        void verMano();
        void sumarGanancia(int ganacia);
        void verSaldo();

    protected:

    private:
        vector<carta>mano;
        int saldo;
};

#endif // JUGADOR_H
