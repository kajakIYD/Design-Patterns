#include "proces.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Proces::Proces (double zmianaJedn, double sinAmp, int sinOkres, double maxLos)
    : s_zmianaJedn(zmianaJedn), s_sinAmp(sinAmp), s_sinOkres(sinOkres), s_maxLos(maxLos), s_skladnikLiniowy(0), s_t(0)
{
    std::srand(static_cast<unsigned int> (std::time(0)));
}

double Proces::symuluj (double wej) {
    if (s_skladnikLiniowy < wej)
        s_skladnikLiniowy = (s_skladnikLiniowy + s_zmianaJedn > wej) ? wej : (s_skladnikLiniowy + s_zmianaJedn);
    else if (s_skladnikLiniowy > wej)
        s_skladnikLiniowy = (s_skladnikLiniowy - s_zmianaJedn < wej) ? wej : (s_skladnikLiniowy - s_zmianaJedn);

    double skladnikSinusoidalny = s_sinAmp*std::sin((static_cast<double>(s_t % s_sinOkres) / s_sinOkres) * 6.28);
    double skladnikLosowy = (((std::rand() % 1000) / 500.0) - 1.0) * s_maxLos;
    double wyj = s_skladnikLiniowy + skladnikSinusoidalny + skladnikLosowy;

    std::clog << "Symulujacja procesu, wej: " << wej << ", wyj: " << wyj << std::endl;

    powiadom (wyj);

    ++s_t;
    return wyj;
}
