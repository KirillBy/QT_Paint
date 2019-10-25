#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtWidgets>
class paintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = nullptr);
    ~paintScene();
    void change_all_to_false(); //switch off all instrument
    void change_pen_to_true(); //switch on Pen
    void change_rect_to_true();//switch on Rectangle
    void change_ellipse_to_true();//switch on Ellipse
    void change_line_to_true();//switch on line
    void change_colour(); //change colour
    QComboBox *myComboBox= new QComboBox; //Declarate ComboBox  with size of line
    void openfile();//open image file


private:
    QPointF     previousPoint;      // Coordinates of previuos point
    //bool Pen;       //Pen switch off/on
    //bool Rectangle; //Rectangle switch off/on
    //bool Ellipse; //Ellipse switch off/on
    enum TypeOfPaint  {Off, Pen, Rectangle, Ellipse, Line};
    TypeOfPaint CurrentInstrument;
    QColor colour; //colour of line
    QBrush br;  //brush for painting
    qreal width; // size of line
    QPointF StartPos;//Start point for ellipse, circle, rectangle
    QGraphicsRectItem *Currentrect = new QGraphicsRectItem; //for showing intermedia rectangle
    QGraphicsEllipseItem *Currentellipse = new QGraphicsEllipseItem; //for showing intermedia rectangle
    QGraphicsLineItem *CurrentLine = new QGraphicsLineItem; //for showing intermedia line
    QLineF SaveLine;
    QRectF Saverect;
    QRectF Saveellipse;


    // for painting we use mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
