#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>
#include "title.h"

class Enemy : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(int xpos = 0, int ypos = 0,Title* window = 0);
    int initSpeed = 600;
    int initx;
    int inity;
    int xdir;
    int dy;
    int dx;
    int speed;
    static int xdistance;
    static bool yhit;
    QTimer* timer;
    Title* mainWindow;
    void gameOver();

public slots:
    void move();
};

#endif // ENEMY_H
