#include "obserwowany.h"
#include "obserwator.h"
#include <algorithm>

Obserwowany::~Obserwowany () {
}

bool Obserwowany::rejestrujObserwatora (Obserwator * obserwator) {
    if (std::find(s_obserwatorzy.begin(), s_obserwatorzy.end(), obserwator) == s_obserwatorzy.end()) {
        s_obserwatorzy.push_back(obserwator);
        return true;
    } else
        return false;
}

bool Obserwowany::wyrejestrujObserwator (Obserwator * obserwator) {
    std::list<Obserwator *>::iterator it;
    it = std::find(s_obserwatorzy.begin(), s_obserwatorzy.end(), obserwator);
    if (it != s_obserwatorzy.end()) {
        s_obserwatorzy.erase(it);
        return true;
    } else
        return false;
}

void Obserwowany::powiadom (double wartosc) const {
    std::list<Obserwator *>::const_iterator it = s_obserwatorzy.begin();
    for (; it != s_obserwatorzy.end(); ++it) {
        (*it)->aktualizuj(wartosc);
    }
}
