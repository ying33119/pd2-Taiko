#ifndef COUNTDOWNTIMER_H
#define COUNTDOWNTIMER_H

#include <QGraphicsTextItem>

class CountdownTimer: public QGraphicsTextItem{
    Q_OBJECT
public:
    CountdownTimer(QGraphicsItem * parent=0);
    int timeValue;

public slots:
    void update();
};

#endif // COUNTDOWNTIMER_H
