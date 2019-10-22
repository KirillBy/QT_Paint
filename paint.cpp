#include "paint.h"
#include "./ui_paint.h"

Paint::Paint(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Paint)

{
    ui->setupUi(this);
    scene = new paintScene();       // Inicialize graffic scene
    ui->graphicsView->setScene(scene);  // Set graffic scene
}

Paint::~Paint()
{
    delete ui;
}



void Paint::resizeEvent(QResizeEvent *event)   // Making correct size of scene.
{
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
    QWidget::resizeEvent(event);  // correct resizing our graffic scene
}

void Paint::on_actionPen_triggered() // switch on Pen instrument, by choising it from menu bar
{
scene->change_all_to_false(); //first we need to switch off all instruments
scene->change_pen_to_true(); //then switch on Pen
}

void Paint::on_actionSwitchOFF_triggered()// turn off all instrument, by choising it from menu bar
{
scene->change_all_to_false();
}
