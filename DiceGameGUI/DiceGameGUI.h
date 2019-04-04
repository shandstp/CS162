#ifndef DICEGAMEGUI_H
#define DICEGAMEGUI_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QAbstractSpinBox>
#include <QtWidgets>
#include <QBoxLayout>
#include "ThreeDicePoker.h"

class DiceGameGUI : public QDialog
{
    Q_OBJECT

public:
    explicit DiceGameGUI(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *Title;
    QFont myFont;
    QLabel *Instructions;
    QLabel *scoreLabel;
    QPushButton *rollButton;
    QPushButton *diceButton[3];
    QLineEdit *scoreDisplay;

};

#endif // DICEGAMEGUI_H
