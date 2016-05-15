#include "countdowntimer.h"
#include <QFont>
#include <QTimer>

CountdownTimer::CountdownTimer(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //initialize the timeValue to 30
    timeValue = 30;

    //draw the test
    setPlainText(QString("Time: ") + QString::number(timeValue));
    setDefaultTextColor(Qt::white);
    setFont(QFont("Segoe Print",18));

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

void CountdownTimer::update(){
    if(timeValue>0){
        timeValue--;
        setPlainText(QString("Time: ") + QString::number(timeValue));
    }
}

