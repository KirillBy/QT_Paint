#include "paintscene.h"
#include "paint.h"
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
Pen = false; // pen switched off by default
colour = Qt::black; //black colour set by default
}

paintScene::~paintScene()
{

}
void paintScene::change_colour() //changing colour from colorDialog
{
    QColorDialog *colorDialog = new QColorDialog();
    colour = colorDialog->getColor();
}
void paintScene::change_pen_to_true() // switch on Pen method
{
    Pen = true;
}
void paintScene::change_all_to_false() // switch all instrument off method
{
    Pen = false;
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->Pen) //if button is pressed and instrument is choisen, paint very small ellipse to fix the coordinates
    {
    addEllipse(event->scenePos().x() - 1,
               event->scenePos().y() - 1,
               1,
               1,
               QPen(Qt::NoPen),
               QBrush(Qt::red));

    // Saving points of coordinates after making a very small ellipse
    previousPoint = event->scenePos();
    }
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   // Pen drawing here!!!!!  Paint lines using previous coordinates from our small ellipse
    if(this->Pen)
    {

            br.setColor(colour);
            br.setStyle(Qt::SolidPattern);
            addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(br,10,Qt::SolidLine,Qt::RoundCap));

    previousPoint = event->scenePos();  //Update our coordinates
     }
}

