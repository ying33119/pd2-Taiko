#ifndef DRUM_H
#define DRUM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>

class Drum: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drum(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent *event);
};

#endif // FACE_H
