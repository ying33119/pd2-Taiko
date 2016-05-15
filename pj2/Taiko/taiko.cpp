#include "taiko.h"
#include "button.h"
#include "score.h"
#include <QGraphicsTextItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QBrush>
#include <QImage>
#include <stdlib.h>
#include <QTimer>
#include <QFont>

Taiko::Taiko(QWidget * parent){    
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(512, 384);

    //create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 512, 384);

    //visualize the newly created scene
    setScene(scene);
}

void Taiko::displayMainMenu(){    
    //set background
    scene->setBackgroundBrush(QBrush(QImage("image/start.jpg")));

    //create the start button
    Button* startButton = new Button(QString("START"));
    startButton->setPos(110,340);
    connect(startButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(startButton);

    //create the exit button
    Button* exitButton = new Button(QString("EXIT"));
    exitButton->setPos(220,340);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exitButton);
}

void Taiko::displayRestartMenu(){
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage("image/restart.jpg")));

    // create the score text
    QGraphicsTextItem* scoreText = new QGraphicsTextItem(QString("Score:")+ QString::number(point));
    QFont textFont("Segoe Print",35);
    scoreText->setFont(textFont);
    scoreText->setPos(12,15);
    scene->addItem(scoreText);

    //create the restart button
    Button* restartButton = new Button(QString("RESTART"));
    restartButton->setPos(355,265);
    connect(restartButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(restartButton);

    //create the exit button
    Button* exitButton = new Button(QString("EXIT"));
    exitButton->setPos(355,305);
    connect(exitButton, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(exitButton);
}

void Taiko::start(){
    //clear the screen and set background
    scene->clear();
    scene->setBackgroundBrush(QBrush(QImage("image/bg.png")));

    //create the drum
    drum = new Drum();
    drum->setPos(115,115);
    scene->addItem(drum);
    drum->setFlag(QGraphicsItem::ItemIsFocusable);
    drum->setFocus();

    //create the score
    score = new Score();
    score->setPos(345,160);
    scene->addItem(score);

    //countdown timer
    timer = new CountdownTimer();
    timer->setPos(195,160);
    scene->addItem(timer);

    //random create face
    createFace();
}

void Taiko::createFace(){
    if(timer->timeValue==0){
        point =  score->score;
        displayRestartMenu();
        return;
    }
    timeSpace = rand() % 500 + 300;
    faceNo = rand () % 4;

    switch(faceNo){
    case 0:
        faceRed = new FaceRed();
        faceRed->setPos(550,120);
        scene->addItem(faceRed);
        break;
    case 1:
        faceBlue = new FaceBlue();
        faceBlue->setPos(550,120);
        scene->addItem(faceBlue);
        break;
    case 2:
        faceRedB = new FaceRedB();
        faceRedB->setPos(550,111);
        scene->addItem(faceRedB);
        break;
    case 3:
        faceBlueB = new FaceBlueB();
        faceBlueB->setPos(550,111);
        scene->addItem(faceBlueB);
        break;
    }

    QTimer::singleShot(timeSpace, this, SLOT(createFace()));
}
