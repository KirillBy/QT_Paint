#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtWidgets>
class Command;
class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = nullptr);
    ~paintScene();
    void change_colour(); //change colour
    void openfile();//open image file
    QColor returncolour();//return colour
private:
    QColor  colour; //colour of line
    // for painting we use mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
public:
    QVector<Command*> draw;// vector of drawing command
    QComboBox *myComboBox= new QComboBox; //Declarate ComboBox  with size of line
};

#endif // PAINTSCENE_H
