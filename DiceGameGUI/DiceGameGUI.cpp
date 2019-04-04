#include "DiceGameGUI.h"


DiceGameGUI::DiceGameGUI(QWidget *parent) :
    QDialog(parent)
{
    Title = new QLabel(tr("Three Dice Poker"));
    myFont = QFont("Arial", 36);
    Title->setFont(myFont);
    Instructions = new QLabel(tr("Click roll to begin"));
    scoreLabel = new QLabel(tr("score : "));
    rollButton = new QPushButton(tr("&Roll"));
    Instructions->setBuddy(rollButton);
    diceButton[0] = new QPushButton(tr("?"));
    diceButton[1] = new QPushButton(tr("?"));
    diceButton[2] = new QPushButton(tr("?"));
    scoreDisplay = new QLineEdit("0");
    scoreLabel->setBuddy(scoreDisplay);


    QVBoxLayout *bottomLeft = new QVBoxLayout;
    bottomLeft->addWidget(Instructions);
    bottomLeft->addWidget(rollButton);

    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->addLayout(bottomLeft);
    bottomLayout->addWidget(scoreLabel);
    bottomLayout->addWidget(scoreDisplay);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(diceButton[0]);
    topLayout->addWidget(diceButton[1]);
    topLayout->addWidget(diceButton[2]);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(Title);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

    setWindowTitle(tr("Three Dice Poker"));
    setFixedHeight(sizeHint().height());
}
