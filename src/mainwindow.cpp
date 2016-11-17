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

    ui->original_h->setText(QString("%1 px").arg(ui->original->height()));
    ui->original_w->setText(QString("%1 px").arg(ui->original->width()));

    ui->new_h->setMaximum(ui->original->height());
    ui->new_h->setValue(ui->original->height());
    ui->new_w->setMaximum(ui->original->width());
    ui->new_w->setValue(ui->original->width());	
}



void MainWindow::on_pushButton_clicked()
{
    image->resize(ui->new_w->value(), ui->new_h->value());
    QPixmap p = QPixmap::fromImage(image->toQImage());
    ui->resized->setPixmap(p.scaled(ui->original->size(), Qt::KeepAspectRatio));
}
