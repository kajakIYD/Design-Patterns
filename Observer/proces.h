#ifndef PROCES_H
#define PROCES_H
#include "obserwowany.h"

class Proces : public Obserwowany {
public:
    Proces (double zmianaJedn, double sinAmp, int sinOkres, double maxLos);
    double symuluj (double wej);
private:
    double s_zmianaJedn;
    double s_sinAmp;
    int s_sinOkres;
    double s_maxLos;

    double s_skladnikLiniowy;
    int s_t;
};

#endif // PROCES_H
