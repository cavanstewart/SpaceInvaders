#include "title.h"
#include "game.h"

Title::Title(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(800,600);
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(background);

    title = new QLabel("Space Invaders", this);
    title->setStyleSheet("QLabel {color : green; }");
    title->setGeometry(100,100,600,100);
    QFont titleFont("Times", 40, QFont::AllUppercase);
    title->setFont(titleFont);

    startButton = new Button("Start",this);
    startButton->setStyleSheet("background-color:green;");
    QFont buttonFont("Times", 40, QFont::AllUppercase);
    startButton-> setFont(buttonFont);
    startButton-> setGeometry(300,300,200,100);
    connect(startButton,SIGNAL(released()),this,SLOT(start()));

}

void Title::start()
{
    hide_all();
    gameScene = new Game(this);
    gameView = new QGraphicsView(this);
    gameView->setScene(gameScene);
    this->setCentralWidget(gameView);
    gameView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void Title::hide_all(){
    title-> setVisible(false);
    startButton-> setVisible(false);
}

void Button::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space)
        return;
    else
        QPushButton::keyPressEvent(event);
}
