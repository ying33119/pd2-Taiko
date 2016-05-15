#ifndef FACEBLUEB_H
#define FACEBLUEB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class FaceBlueB: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FaceBlueB(QGraphicsItem *parent=0);

public slots:
    void move();
};

#endif // FACEBLUEB_H
