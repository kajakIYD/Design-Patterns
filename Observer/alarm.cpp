#include "alarm.h"
#include <cstdlib>
#include <iostream>

Alarm::Alarm (double wartGraniczna)
    : s_wartGraniczna(wartGraniczna)
{
}

void Alarm::aktualizuj (double wartosc) {
    sprawdz (wartosc);
}

void Alarm::sprawdz (double wartosc) const {
    if (std::abs(wartosc) > std::abs(s_wartGraniczna))
        std::clog << " ALARM! - przekroczono wartosc graniczna |" << s_wartGraniczna << "|" << std::endl;
}
