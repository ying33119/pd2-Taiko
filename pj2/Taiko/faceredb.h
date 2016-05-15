#ifndef FACEREDB_H
#define FACEREDB_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class FaceRedB: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FaceRedB(QGraphicsItem *parent=0);

public slots:
    void move();
};


#endif // FACEREDB_H
