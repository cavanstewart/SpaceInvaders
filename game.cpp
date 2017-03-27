#include "game.h"

Game::Game(Title* window)
{
    //create a scene
    setSceneRect(0,0,800,600);




    //create item to put in scene
    player = new Player();
    player->setRect(0,0,40,40);
    player->setPos(400,500);
    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    addItem(player);

    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            enemy = new Enemy(i*80,j*80);
            addItem(enemy);
        }
    }
}
