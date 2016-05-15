#include "faceblue.h"
#include "taiko.h"
#include <QTimer>
#include <QGraphicsScene>

FaceBlue::FaceBlue(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //draw graphics
    setPixmap(QPixmap("image/b2.png"));

    //make the face move
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //start the timer
    timer->start(10);
}

void FaceBlue::move(){
    //move face
    setPos(x()-2,y());
    //out of screen
    if(pos().x() < 88){
        scene()->removeItem(this);
        delete this;
    }
}
