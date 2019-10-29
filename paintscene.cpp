#include "paintscene.h"
#include "paint.h"
#include "command.h"
/////////////////////////////////////////////////////////////// Constructor
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
    colour = Qt::black;
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
////////////////////////////////////////////////////////////////
QColor paintScene::returncolour()
{
   return colour;
}
///////////////////////////////////////////////////////////////
void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)//Start poing getting here!!!
{
    if(!draw.empty()) //if button is pressed and instrument is choisen, paint very small ellipse to fix the coordinates
    {
        draw.last()->startpoint(event);
    }

}
/////////////////////////////////////////////////////////////
void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(!draw.empty())
        draw.last()->execute(event);
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(!draw.empty())
        draw.last()->save();
}
