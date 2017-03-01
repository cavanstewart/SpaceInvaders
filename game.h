#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"

class Game : public QGraphicsView {
public:
    Game(QWidget* parent = 0);

    Player* player;
    Enemy* enemy;
    QGraphicsScene* scene;
};

#endif // GAME_H
