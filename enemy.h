#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsRectItem>

class Enemy : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy(int xpos = 0, int ypos = 0);
    int dir;
    QTimer* timer;

public slots:
    void move();
};

#endif // ENEMY_H
