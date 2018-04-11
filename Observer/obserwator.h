#ifndef OBSERWATOR_H
#define OBSERWATOR_H


class Obserwator {
public:
    virtual ~Obserwator () {}
    virtual void aktualizuj (double wartosc) = 0;
};

#endif // OBSERWATOR_H
