#include "mainwindow.h"
#include "alarm.h"
#include "proces.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    {
        Alarm * alarm = new Alarm (10);
        Proces * proces = new Proces (4, 0.1, 20, 0.1);
        proces->rejestrujObserwatora(alarm);

        for (unsigned int i = 0; i < 5; ++i)
            proces->symuluj(5);

        for (unsigned int i = 0; i < 10; ++i)
            proces->symuluj(15);

        delete proces;
        delete alarm;

        return 0;
    }

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
