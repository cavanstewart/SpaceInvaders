#include "game.h"

Game::Game(QWidget* parent)
{
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    //create item to put in scene
    player = new Player();
    player->setRect(0,0,40,40);
    player->setPos(400,500);
    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    enemy = new Enemy();
    scene->addItem(enemy);

    show();
}
