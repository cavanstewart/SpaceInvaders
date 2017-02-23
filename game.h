#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

class Game : public QGraphicsView {
public:
    Game(QWidget* parent = 0);

    void start();

    QGraphicsScene* scene;
};

#endif // GAME_H
