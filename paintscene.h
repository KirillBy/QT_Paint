#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "user_choice.h"

class paintScene : public QGraphicsScene
{

    Q_OBJECT
    bool Pen;

public:
    explicit paintScene(QObject *parent = nullptr);
    ~paintScene();
    void change_all_to_false(); //switch off all instrument
     void change_pen_to_true(); //switch on Pen

private:
    QPointF     previousPoint;      // Coordinates of previuos point

private:
    // for painting we use mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


};

#endif // PAINTSCENE_H
