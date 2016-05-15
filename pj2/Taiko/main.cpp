#include <QApplication>
#include "taiko.h"

Taiko * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Taiko();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
