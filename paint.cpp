#include "paint.h"
#include "./ui_paint.h"

Paint::Paint(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Paint)

{

    ui->setupUi(this);

    scene = new paintScene();       // Inicialize graffic scene
    ui->graphicsView->setScene(scene);  // Set graffic scene

    ui->toolBar->addWidget(scene->myComboBox); //Set LineWidth box
   ui->graphicsView->QAbstractScrollArea::scrollBarWidgets(Qt::AlignRight);
   ui->graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scene-> setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());


}

Paint::~Paint()
{
    delete ui;
}


void Paint::resizeEvent(QResizeEvent *event)   // Making correct size of scene.
{

   QWidget::resizeEvent(event);  // correct resizing our graffic scene
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
void Paint::on_actionPen_triggered() // switch on Pen instrument, by choising it from menu bar
{
    scene->draw.push_back(new DrawPenCommand(scene));
}

void Paint::on_actionRectangle_triggered()
{
        scene->draw.push_back(new DrawRectangleCommand(scene));
}

void Paint::on_actionEllipse_triggered()
{
        scene->draw.push_back(new DrawEllipseCommand(scene));
}

void Paint::on_actionLine_triggered()
{
        scene->draw.push_back(new DrawLineCommand(scene));
}

void Paint::on_actionClear_All_triggered()
{
       scene->clear();
}
void Paint::on_actionEraser_triggered()
{
       scene->draw.push_back(new DrawEraseCommand(scene));
}
