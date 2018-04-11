#ifndef OBSERWOWANY_H
#define OBSERWOWANY_H


class Obserwator;

class Obserwowany {
public:
    virtual ~Obserwowany ();
    bool rejestrujObserwatora (Obserwator * obserwator);
    bool wyrejestrujObserwator (Obserwator * obserwator);
    void powiadom (double wartosc) const;
private:
    std::list<Obserwator * > s_obserwatorzy;
};


#endif // OBSERWOWANY_H
