#ifndef LAZER_H
#define LAZER_H

#include <QGraphicsRectItem>
#include <QObject>

class Lazer : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Lazer();
public slots:
    void move();
};

#endif // LAZER_H
