#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "posfixa.h"
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

void MainWindow::on_pushButton_clicked()
{
    std::string exp = ui->lineEdit->text().toStdString();
    posfixa pos;
    string valor  = pos.converte(exp);
   bool flag = pos.getflag();
   if(flag)
    ui->label_2->setText(QString('s').fromStdString(valor));
   else
       ui->label_2->setText("invalida");

}
