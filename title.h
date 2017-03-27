#ifndef TITLE_H
#define TITLE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsScene>
#include <QKeyEvent>

class Button : public QPushButton {
public:
    Button(const QString &dtext, QWidget *dparent = Q_NULLPTR) : QPushButton(dtext,dparent){};
    void keyPressEvent(QKeyEvent* event);
};


class Title : public QMainWindow
{
    Q_OBJECT
public:
    explicit Title(QWidget *parent = 0);
    void hide_all();
    QGraphicsScene* get_gameScene(){return gameScene;}

private:
    QLabel *title;
    Button *startButton;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;

private slots:
    void start();
};


#endif // TITLE_H
