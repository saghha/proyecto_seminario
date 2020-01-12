#ifndef BARAJA_H
#define BARAJA_H
#include "definicion.h"

class Baraja
{
    public:
        Baraja();
        virtual ~Baraja();
        void verBaraja();
        carta sacarCarta();
        int cartasRestantes();
    protected:

    private:
        vector<carta>cartas;
};

#endif // BARAJA_H
