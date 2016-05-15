#ifndef FACE_H
#define FACE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class FaceRed: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FaceRed(QGraphicsItem *parent=0);

public slots:
    void move();
};

#endif // FACE_H
