#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete image;
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    image = new Image(QFileDialog::getOpenFileName(this,"Select image",".","Image Files (*.png *.jpg *.bmp)"));
    QPixmap p = QPixmap::fromImage(image->toQImage());

    ui->original->setPixmap(p.scaled(ui->original->size(), Qt::KeepAspectRatio));
}


