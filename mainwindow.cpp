#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QObject>

QList<float> values[2];
QList<bool> vBool[2];
char calcType;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    vBool->append(false);
    vBool->append(false);

    values->append(0);
    values->append(0);
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
           addValues(val, 0);
           ui->textEdit->setText(buttonSender->text());
        }else{
           addValues(val, 1);
           ui->textEdit->setText(buttonSender->text());
        }
    }

}

void MainWindow::addValues(float value, int theValue){

    if(vBool->value(theValue) == false){
        values->value(theValue, value);
    }else{
        values->value(theValue, (values->value(theValue) * 10) + value);
    }
}

void MainWindow::typeFunction(){
    if(vBool->value(0) == true && calcType == NULL){
        values->value(1, 0);
        vBool->value(1, false);
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
    if(vBool->value(0)){
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

