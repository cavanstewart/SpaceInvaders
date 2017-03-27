#include "player.h"
#include "lazer.h"
#include<QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>


void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0){
        setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 40 < 800){
        setPos(x()+10,y());
        }
    }
    else if((event->key() == Qt::Key_Space) && !(Lazer::numLazers)){
        Lazer* lazer = new Lazer();
        lazer->setPos(x(),y());
        scene()->addItem(lazer);
    }
}
