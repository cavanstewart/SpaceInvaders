#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include <cmath>

int Enemy::xdistance = 440;
bool Enemy::yhit = false;

Enemy::Enemy(int xpos, int ypos, Title *window) : QObject(), QGraphicsRectItem()
{
    mainWindow=window;
    setBrush(*new QBrush(Qt::darkGreen));
    dx = 1;
    dy = 0;
    xdir = 1;
    speed = 1;
    initx = xpos;
    inity = ypos;
    setRect(0,0,40,40);
    setPos(xpos,ypos);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(initSpeed);
}

void Enemy::gameOver()
{
    for (size_t i = 0, n = mainWindow->get_gameScene()->items().size(); i < n; i++){
            mainWindow->get_gameScene()->items()[i]->setEnabled(false);
        }
    QLabel* gameOverText = new QLabel("Game Over");
    gameOverText->setStyleSheet("QLabel {color : red; }");
    gameOverText->setGeometry(200,200,400,100);
    QFont titleFont("Times", 40, QFont::AllUppercase);
    gameOverText->setFont(titleFont);
    QGraphicsProxyWidget* proxyText = mainWindow->get_gameScene()->addWidget(gameOverText);
}


void Enemy::move()
{
    setPos(x()+(40 * dx * xdir),y()+ (40 * dy));

    if (pos().y() == 480){
        yhit=true;
    }

    if(yhit == true){
        timer->stop();
        gameOver();
        //Game::gameOver();
    }

    if(pos().x() == (initx + xdistance) && dx !=0){
        dy = 1;
        xdir = -1;
        dx = 0;
        speed++;
        timer->start(initSpeed / speed);
    }
    else if(pos().x()== initx && dx !=0){
        dy = 1;
        xdir = 1;
        dx = 0;
        speed++;
        timer->start(initSpeed / speed);
    }
        else {
        dx = 1;
        dy = 0;
    }


}
