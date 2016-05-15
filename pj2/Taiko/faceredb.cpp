#include "faceredb.h"
#include "taiko.h"
#include <QTimer>
#include <QGraphicsScene>

FaceRedB::FaceRedB(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //draw graphics
    setPixmap(QPixmap("image/r3.png"));

    //make the face move
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //start the timer
    timer->start(10);
}

void FaceRedB::move(){
    //move face
    setPos(x()-2,y());
    //out of screen
    if(pos().x() < 88){
        scene()->removeItem(this);
        delete this;
    }
}

