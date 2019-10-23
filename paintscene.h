#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include "user_choice.h"
#include <QtWidgets>
class paintScene : public QGraphicsScene
{

    Q_OBJECT
    bool Pen;       //Pen switch off/on
    QColor colour; //colour of line
    QBrush br;  //brush for painting
    qreal width; // size of line
   QComboBox *myComboBox; //Declarate ComboBox  with size of line
public:
    explicit paintScene(QObject *parent = nullptr);
    ~paintScene();
    void change_all_to_false(); //switch off all instrument
    void change_pen_to_true(); //switch on Pen
    void change_colour(); //change colour
    void set_line_width(); //change line width

private:
    QPointF     previousPoint;      // Coordinates of previuos point

private:
    // for painting we use mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


};

#endif // PAINTSCENE_H
