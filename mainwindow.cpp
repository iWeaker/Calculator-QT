#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QObject>

float firstValue, secondValue;
char calcType;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect( ui->num0, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num1, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num2, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num3, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num4, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num5, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num6, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num7, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num8, SIGNAL( clicked() ), this, SLOT( setNum() ) );
    connect( ui->num9, SIGNAL( clicked() ), this, SLOT( setNum() ) );

    connect( ui->addBtn, SIGNAL( clicked() ), this, SLOT( typeFunction() ) );
    connect( ui->divBtn, SIGNAL( clicked() ), this, SLOT( typeFunction() ) );
    connect( ui->opMulti, SIGNAL( clicked() ), this, SLOT( typeFunction() ) );
    connect( ui->subBtn, SIGNAL( clicked() ), this, SLOT( typeFunction() ) );

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
            firstValue = addValues(val, firstValue);
        }else{
            secondValue = addValues(val, secondValue);
        }
    }
    ui->textEdit->setText(buttonSender->text());
}

float addValues(float value, float theValue){
    float t = theValue;
    if(t == NULL){
        t = value;
    }else{
        t *= 10;
        t += value;
    }
    return t;
}

void MainWindow::typeFunction(){
    if(firstValue != NULL && calcType == NULL){
        secondValue = NULL;
    }

    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QStringList myOptions;
    myOptions << "+" << "*" << "-" << "/";
    /*
     * + = 0
     * * = 1
     * - = 2
     * / = 3
     * */
    if(firstValue != NULL){
        switch(myOptions.indexOf(buttonSender->text())){
            case 0:
                calcType = '+';
                break;
            case 1:
                calcType = '*';
                break;
            case 2:
                calcType = '-';
                break;
                calcType = '/';
            case 3:
                break;
        }
    }
}

