#include <iostream>
#include <QApplication>
#include "DiceGameGUI.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DiceGameGUI *dialog = new DiceGameGUI;
    dialog->show();

    return app.exec();
}
