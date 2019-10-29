#ifndef PAINT_H
#define PAINT_H
#include <command.h>
#include <QtWidgets>
#include <QResizeEvent>
#include "paintscene.h"
#include <QMainWindow>
namespace Ui {
class Paint;
}

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    explicit Paint(QWidget *parent = nullptr);
    ~Paint();


private:
    Ui::Paint *ui;

    paintScene *scene;  // Declarate our graffic scene

private:
    void resizeEvent(QResizeEvent * event);

private slots:
    void on_actionPen_triggered();
    void on_actionColour_triggered();
    void on_actionOpen_triggered();
    void on_actionSave_as_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionLine_triggered();
    void on_actionClear_All_triggered();
    void on_actionEraser_triggered();
};

#endif // PAINT_H
