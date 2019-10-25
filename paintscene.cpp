#include "paintscene.h"
#include "paint.h"

/////////////////////////////////////////////////////////////// Constructor
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
Pen = false; // pen switched off by default
Rectangle = false; // rectangle switched off by default
colour = Qt::black; //black colour set by default
myComboBox->addItems({"1", "2", "3", "4", "5","6", "7", "8", "9", "10",
                     "11", "12", "13", "14", "15","16", "17", "18", "19", "20",
                     "21", "22", "23", "24", "25","26", "27", "28", "29", "30",
                      "35", "40", "45", "50"});  // values of line width
myComboBox->setCurrentText("10"); //default size of line 10

}
////////////////////////////////////////////////////////////////
paintScene::~paintScene()
{

}
///////////////////////////////////////////////////////////////
void paintScene::change_colour() //changing colour from colorDialog
{
    QColorDialog *colorDialog = new QColorDialog();
    colour = colorDialog->getColor();
}
////////////////////////////////////////////////////////////////
void paintScene::openfile()//open image file method
{
    QString filename = QFileDialog::getOpenFileName();
    if(!filename.isEmpty())
       {
           QImage image(filename);

           if(image.isNull())
           {
 auto Mbox = new QMessageBox();
 Mbox->setText("Error opening image file");
 Mbox->show();
               return;
           }
    this->addPixmap(QPixmap::fromImage(image));
    }
}
///////////////////////////////////////////////////////////////
void paintScene::change_pen_to_true() // switch on Pen method
{
    change_all_to_false();
    Pen = true;
}

void paintScene::change_rect_to_true()
{
    change_all_to_false();
    Rectangle = true;
}
void paintScene::change_all_to_false() // switch all instrument off method
{
    Rectangle = false;
    Pen = false;
}
///////////////////////////////////////////////////////////////
void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->Pen || this-Rectangle) //if button is pressed and instrument is choisen, paint very small ellipse to fix the coordinates
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
    StartPos = event->scenePos();

}
/////////////////////////////////////////////////////////////
void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

   // Pen drawing here!!!!!  Paint lines using previous coordinates from our small ellipse
    if(this->Pen)
    {
            width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
            br.setColor(colour);   //setting brush
            br.setStyle(Qt::SolidPattern);
            addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(br,width,Qt::SolidLine,Qt::RoundCap));

    previousPoint = event->scenePos();  //Update our coordinates
     }

    //Rectangle drawing here!!!!!
    if(this->Rectangle)
    {
        if((event->scenePos().x() > StartPos.x())  &&  (event->scenePos().y() > StartPos.y()))
        {
            width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
            br.setColor(colour);   //setting brush
            br.setStyle(Qt::SolidPattern);
            removeItem(Currentrect);

            {Saverect.setRect(StartPos.x(),StartPos.y(),(event->scenePos().x()-StartPos.x()),(event->scenePos().y()-StartPos.y()));}
            Currentrect = addRect(StartPos.x(),StartPos.y(), (event->scenePos().x()-StartPos.x()), ( event->scenePos().y()-StartPos.y()),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
            previousPoint = event->scenePos();  //Update our coordinates
        }
     }
    }

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(this->Rectangle)
    {
            addRect(Saverect,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
     }
}
