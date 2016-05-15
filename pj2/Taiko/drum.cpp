#include "drum.h"
#include "taiko.h"
#include "faceblue.h"
#include "facered.h"
#include "faceblueb.h"
#include "faceredb.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <typeinfo>

extern Taiko * game;

Drum::Drum(QGraphicsItem *parent):  QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap("image/circle.png"));
}

void Drum::keyPressEvent(QKeyEvent *event){
    QList<QGraphicsItem *> collidingItem = collidingItems();
    for (int i = 0, n = collidingItem.size(); i < n; ++i){
        if (event->key()==Qt::Key_J && typeid(*(collidingItem[i])) == typeid(FaceRed)){
            scene()->removeItem(collidingItem[i]);
            delete collidingItem[i];
            game->score->increase();
        }
        else if (event->key()==Qt::Key_J && typeid(*(collidingItem[i])) == typeid(FaceRedB)){
            scene()->removeItem(collidingItem[i]);
            delete collidingItem[i];
            game->score->increaseB();
        }
        else if (event->key()==Qt::Key_K && typeid(*(collidingItem[i])) == typeid(FaceBlue)){
            scene()->removeItem(collidingItem[i]);
            delete collidingItem[i];
            game->score->increase();
        }
        else if (event->key()==Qt::Key_K && typeid(*(collidingItem[i])) == typeid(FaceBlueB)){
            scene()->removeItem(collidingItem[i]);
            delete collidingItem[i];
            game->score->increaseB();
        }
    }
}
