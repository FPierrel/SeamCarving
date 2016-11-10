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
    delete ui;
}

void MainWindow::on_actionLoad_triggered()
{
    this->loadFile(QFileDialog::getOpenFileName(this,"Select image",".","Image Files (*.png *.jpg *.bmp)"));
}

void MainWindow::loadFile(string filename)
{

}
