#ifndef FACEBLUE_H
#define FACEBLUE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class FaceBlue: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FaceBlue(QGraphicsItem *parent=0);

public slots:
    void move();
};

#endif // FACEBLUE_H
