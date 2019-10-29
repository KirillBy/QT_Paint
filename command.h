#ifndef COMMAND_H
#define COMMAND_H
#include "paintscene.h"

//////
class Command
{
protected:
    paintScene *PS;
    QBrush br;  //brush for painting
    qreal width; // size of line
    QPointF StartPos;//Start point for ellipse, circle, rectangle
    QGraphicsRectItem *Currentrect = new QGraphicsRectItem; //for showing intermedia rectangle
    QGraphicsEllipseItem *Currentellipse = new QGraphicsEllipseItem; //for showing intermedia rectangle
    QGraphicsLineItem *CurrentLine = new QGraphicsLineItem; //for showing intermedia line
    QLineF SaveLine;
    QRectF Saverect;
    QRectF Saveellipse;
    QPointF     previousPoint;      // Coordinates of previuos point
public:
      QColor C;
      Command(paintScene *ps);
      virtual ~Command() {}
      virtual void execute(QGraphicsSceneMouseEvent * event) = 0;
      virtual void save() = 0;
      void startpoint(QGraphicsSceneMouseEvent *event);

};

//////
class DrawPenCommand: public Command
{
  public:
    DrawPenCommand(paintScene *ps);
    void execute(QGraphicsSceneMouseEvent * event) override;
    void save() override;

};

//////
class DrawRectangleCommand: public Command
{
  public:
    DrawRectangleCommand(paintScene *ps);
    void execute(QGraphicsSceneMouseEvent * event) override;
    void save() override;

};

//////
class DrawEraseCommand: public Command
{
  public:
    DrawEraseCommand(paintScene *ps);
    void execute(QGraphicsSceneMouseEvent * event) override;
    void save() override;

};

//////
class DrawEllipseCommand: public Command
{
  public:
    DrawEllipseCommand(paintScene *ps);
    void execute(QGraphicsSceneMouseEvent * event) override;
    void save() override;

};

//////
class DrawLineCommand: public Command
{
  public:
    DrawLineCommand(paintScene *ps);
    void execute(QGraphicsSceneMouseEvent * event) override;
    void save() override;

};
#endif // COMMAND_H
