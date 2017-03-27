#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include "title.h"

class Game : public QGraphicsScene {
    Q_OBJECT
public:
    Game(Title* window = 0);
    void gameOver();

private:
    Player* player;
    Enemy* enemy;

};

#endif // GAME_H
