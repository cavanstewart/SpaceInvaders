#ifndef TITLE_H
#define TITLE_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsScene>

class Title : public QMainWindow
{
    Q_OBJECT
public:
    explicit Title(QWidget *parent = 0);
    void hide_all();

private:
    QLabel *title;
    QPushButton *startButton;
    QGraphicsScene *gameScene;
    QGraphicsView *gameView;

private slots:
    void start();
};

#endif // TITLE_H
