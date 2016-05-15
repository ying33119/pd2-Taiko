#ifndef TAIKO_H
#define TAIKO_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "facered.h"
#include "faceblue.h"
#include "faceredb.h"
#include "faceblueb.h"
#include "score.h"
#include "countdowntimer.h"
#include "drum.h"

class Taiko: public QGraphicsView{
    Q_OBJECT
public:
    Taiko(QWidget * parent=0);

    void displayMainMenu();
    void displayRestartMenu();

    QGraphicsScene * scene;
    FaceRed * faceRed;
    FaceBlue * faceBlue;
    FaceRedB * faceRedB;
    FaceBlueB * faceBlueB;
    Score * score;
    CountdownTimer * timer;
    Drum * drum;

public slots:
    void start();
    void createFace();

private:
    int faceNo;
    int timeSpace;
    int point;
};

#endif // TAIKO_H
