#include "paint.h"
#include "./ui_paint.h"

Paint::Paint(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Paint)

{

    ui->setupUi(this);
    scene = new paintScene();       // Inicialize graffic scene
    ui->graphicsView->setScene(scene);  // Set graffic scene
    ui->toolBar->addWidget(scene->myComboBox); //Set LineWidth box

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

void Paint::on_actionColour_triggered()// change the colour by using QColorDialog
{
scene->change_colour();
}

void Paint::on_actionOpen_triggered()//open image file
{
    scene->openfile();
}

void Paint::on_actionSave_as_triggered()//saving image file
{
    QString fileName= QFileDialog::getSaveFileName();
        if (!fileName.isNull())
        {
            QPixmap pixMap = this->ui->graphicsView->grab();
            pixMap.save(fileName);

        }


}

void Paint::on_actionRectangle_triggered()
{
scene->change_rect_to_true();
}

void Paint::on_actionEllipse_triggered()
{
scene->change_ellipse_to_true();
}
