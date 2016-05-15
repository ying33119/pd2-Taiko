#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //initialize the score to 0
    score = 0;

    //draw the test
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Segoe Print",18));
}

void Score::increase(){
    score+=10;
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increaseB(){
    score+=5;
    setPlainText(QString("Score: ") + QString::number(score));
}



