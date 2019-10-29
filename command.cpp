#include "command.h"
#include "paintscene.h"
Command::Command(paintScene *ps)
{

    PS = ps;
    br.setStyle(Qt::SolidPattern);

}
void Command::startpoint(QGraphicsSceneMouseEvent *event)
{
    PS->addEllipse(event->scenePos().x() - 1,
               event->scenePos().y() - 1, 1, 1,
               QPen(Qt::NoPen),  QBrush(Qt::red));

    // Saving points of coordinates after making a very small ellipse
    previousPoint = event->scenePos();
    StartPos = event->scenePos();
}


/////////Pen
DrawPenCommand::DrawPenCommand(paintScene *ps):Command(ps) {Command::PS = ps;}
void DrawPenCommand::execute(QGraphicsSceneMouseEvent * event)
{

    width=PS->myComboBox->currentText().toUInt(); //taking current number in ComboBox
    br.setColor(PS->returncolour());   //setting brush
    PS->addLine(previousPoint.x(),
    previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                    QPen(br,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
void DrawPenCommand::save() {}




////////Rectangle
DrawRectangleCommand::DrawRectangleCommand(paintScene *ps):Command(ps) {Command::PS = ps;}
void DrawRectangleCommand::execute(QGraphicsSceneMouseEvent *event)
{
    width=PS->myComboBox->currentText().toUInt(); //taking current number in ComboBox
    br.setColor(PS->returncolour());   //setting brush
    if((event->scenePos().x() > StartPos.x())  &&  (event->scenePos().y() > StartPos.y()))
    {
        PS->removeItem(Currentrect);
        Saverect.setRect(StartPos.x(),StartPos.y(),(event->scenePos().x()-StartPos.x()),(event->scenePos().y()-StartPos.y()));
        Currentrect = PS->addRect(StartPos.x(),StartPos.y(), (event->scenePos().x()-StartPos.x()), ( event->scenePos().y()-StartPos.y()),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->scenePos();  //Update our coordinates
    }
}
void DrawRectangleCommand::save()
{
    PS->addRect(Saverect,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
}



/////////Erase
DrawEraseCommand::DrawEraseCommand(paintScene *ps):Command(ps) {Command::PS = ps;}
void DrawEraseCommand::execute(QGraphicsSceneMouseEvent * event)
{
    width=PS->myComboBox->currentText().toUInt(); //taking current number in ComboBox
    br.setColor(PS->returncolour());   //setting brush

    PS->addLine(previousPoint.x(),
    previousPoint.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                    QPen(Qt::white,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();
}
void DrawEraseCommand::save() {}



////////Ellipse
DrawEllipseCommand::DrawEllipseCommand(paintScene *ps):Command(ps) {Command::PS = ps;}
void DrawEllipseCommand::execute(QGraphicsSceneMouseEvent *event)
{
    width=PS->myComboBox->currentText().toUInt(); //taking current number in ComboBox
    br.setColor(PS->returncolour());   //setting brush
    PS->removeItem(Currentellipse);
    Saveellipse.setRect(StartPos.x(),StartPos.y(),(event->scenePos().x()-StartPos.x()),(event->scenePos().y()-StartPos.y()));
    Currentellipse = PS->addEllipse(StartPos.x(),StartPos.y(), (event->scenePos().x()-StartPos.x()), ( event->scenePos().y()-StartPos.y()),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();  //Update our coordinates
}
void DrawEllipseCommand::save()
{
    PS->addEllipse(Saveellipse,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
}



//////Line
DrawLineCommand::DrawLineCommand(paintScene *ps):Command(ps) {Command::PS = ps;}
void DrawLineCommand::execute(QGraphicsSceneMouseEvent *event)
{
    width=PS->myComboBox->currentText().toUInt(); //taking current number in ComboBox
    br.setColor(PS->returncolour());   //setting brush
    PS->removeItem(CurrentLine);
    SaveLine.setLine(StartPos.x(),StartPos.y(),event->scenePos().x(),event->scenePos().y());
    CurrentLine = PS->addLine(StartPos.x(),StartPos.y(),event->scenePos().x(),event->scenePos().y(),QPen(br,width,Qt::SolidLine,Qt::RoundCap));
    previousPoint = event->scenePos();  //Update our coordinates
}
void DrawLineCommand::save()
{
    PS->addLine(SaveLine,QPen(br,width,Qt::SolidLine,Qt::RoundCap));
}
