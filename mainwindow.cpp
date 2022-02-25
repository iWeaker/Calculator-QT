#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QObject>

char calcType;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect( ui->num0, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num1, SIGNAL( clicked() ), this, SLOT( setNum() ) );

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::setNum()
{
    float val;
    bool ok;
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());

    if(buttonSender->text().toFloat(&ok)  == true){
        if(calcType == NULL){

        }else{

        }
    }
    QMessageBox::information(this, "Hola",buttonSender->text());
}

void addValues(float value, float theValue){

    return;
}

