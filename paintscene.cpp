#include "paintscene.h"
#include "paint.h"

/////////////////////////////////////////////////////////////// Constructor
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent)
{
CurrentInstrument = Off;
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
   CurrentInstrument = Pen;
}

void paintScene::change_rect_to_true()// switch on Rectangle method
{
    change_all_to_false();
    CurrentInstrument = Rectangle;
}

void paintScene::change_ellipse_to_true()// switch on Ellipse method
{
    change_all_to_false();
    CurrentInstrument = Ellipse;
}

void paintScene::change_line_to_true()
{
    CurrentInstrument = Line;
}

void paintScene::change_eraser_to_true()
{
    CurrentInstrument = Eraser;
}
void paintScene::change_all_to_false() // switch all instrument off method
{

    CurrentInstrument = Off;

}
///////////////////////////////////////////////////////////////
void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)//Start poing getting here!!!
{
    if(CurrentInstrument != Off) //if button is pressed and instrument is choisen, paint very small ellipse to fix the coordinates
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
    switch (CurrentInstrument)
    {
    case(Pen):// Pen drawing here!!!!!  Paint lines using previous coordinates from our small ellip
        width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
        br.setColor(colour);   //setting brush
        br.setStyle(Qt::SolidPattern);
        addLine(previousPoint.x(),
        previousPoint.y(),
        event->scenePos().x(),
        event->scenePos().y(),
    QPen(br,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();  //Update our coordinates
        break;
    case(Eraser):// Eraser here!!!!!  Paint lines using previous coordinates from our small ellip
        width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
        br.setColor(Qt::white);   //setting brush
        br.setStyle(Qt::SolidPattern);
        addLine(previousPoint.x(),
        previousPoint.y(),
        event->scenePos().x(),
        event->scenePos().y(),
    QPen(br,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();  //Update our coordinates
        break;
    case(Rectangle):  //Rectangle drawing here!!!!!
        if((event->scenePos().x() > StartPos.x())  &&  (event->scenePos().y() > StartPos.y()))
        {
            width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
            br.setColor(colour);   //setting brush
            br.setStyle(Qt::SolidPattern);
            removeItem(Currentrect);
            Saverect.setRect(StartPos.x(),StartPos.y(),(event->scenePos().x()-StartPos.x()),(event->scenePos().y()-StartPos.y()));
            Currentrect = addRect(StartPos.x(),StartPos.y(), (event->scenePos().x()-StartPos.x()), ( event->scenePos().y()-StartPos.y()),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
            previousPoint = event->scenePos();  //Update our coordinates
        }
        break;
    case(Ellipse): //Ellipse drawing here!!!!
        width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
        br.setColor(colour);   //setting brush
        br.setStyle(Qt::SolidPattern);
        removeItem(Currentellipse);
        Saveellipse.setRect(StartPos.x(),StartPos.y(),(event->scenePos().x()-StartPos.x()),(event->scenePos().y()-StartPos.y()));
        Currentellipse = addEllipse(StartPos.x(),StartPos.y(), (event->scenePos().x()-StartPos.x()), ( event->scenePos().y()-StartPos.y()),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();  //Update our coordinates
        break;
    case(Line):
        width=myComboBox->currentText().toUInt(); //taking current number in ComboBox
        br.setColor(colour);   //setting brush
        br.setStyle(Qt::SolidPattern);
        removeItem(CurrentLine);
        SaveLine.setLine(StartPos.x(),StartPos.y(),event->scenePos().x(),event->scenePos().y());
        CurrentLine = addLine(StartPos.x(),StartPos.y(),event->scenePos().x(),event->scenePos().y(),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();  //Update our coordinates
        break;
    }


}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    switch (CurrentInstrument)
    {
    case(Rectangle):
       addRect(Saverect,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        break;
    case(Ellipse):
        addEllipse(Saveellipse,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        break;
    case(Line):
        addLine(SaveLine,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        break;
    }
}
