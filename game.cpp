#include "game.h"
#include "QGraphicsProxyWidget"

Game::Game(Title* window)
{
    //create a scene
    setSceneRect(0,0,800,600);
    setBackgroundBrush(*new QBrush(Qt::gray));

    //game over line
    addLine(0,480,800,480);

    //create item to put in scene
    player = new Player();
    player->setRect(0,0,40,40);
    player->setPos(400,550);
    player->setBrush(*new QBrush(Qt::darkBlue));
    //make player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    addItem(player);

    for(int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            enemy = new Enemy(i*80,j*80,window);
            addItem(enemy);
        }
    }

}

void Game::gameOver(){
    for (size_t i = 0, n = items().size(); i < n; i++){
            items()[i]->setEnabled(false);
        }

    QLabel* gameOverText = new QLabel("Game Over");
    gameOverText->setStyleSheet("QLabel {color : red; }");
    gameOverText->setGeometry(200,200,400,100);
    QFont titleFont("Times", 40, QFont::AllUppercase);
    gameOverText->setFont(titleFont);
    QGraphicsProxyWidget* proxyText = this->addWidget(gameOverText);


}
