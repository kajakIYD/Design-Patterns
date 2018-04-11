#ifndef ALARM_H
#define ALARM_H
#include "obserwator.h"

class Alarm : public Obserwator {
public:
    Alarm (double wartGraniczna);
    virtual void aktualizuj (double wartosc);
    void sprawdz (double wartosc) const;
private:
    double s_wartGraniczna;
};

#endif // ALARM_H
