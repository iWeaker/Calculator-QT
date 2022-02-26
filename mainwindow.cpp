#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QObject>

float values[2] = {0, 0 };
bool vBool[2] = {false, false};
char calcType = NULL;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    //Numerical function
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
    //Calculation function
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

    val = buttonSender->text().toInt(&ok);
    if(ok){
        if(calcType == NULL){
           addValues(val, 0);
        }else{
           addValues(val, 1);
        }
    }
}

void MainWindow::addValues(int value, int theValue){

    if(vBool[theValue] == false){
        values[theValue] = value;
        vBool[theValue] = true;

    }else{
        values[theValue] *= 10;
        values[theValue] += value;
    }

    QString b;
    b.setNum(values[theValue]);
    ui->textEdit->setText(b);
}


void MainWindow::typeFunction(){
    if(vBool[0] == true && calcType != NULL){
        values[1] = 0;
        vBool[1]  = false;
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
    if(vBool[0]){
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



void MainWindow::on_clearBtn_clicked()
{
    values[0] = values[1] = 0;
    vBool[0] = vBool[1] = false;

    calcType = NULL;
    ui->textEdit->setText("");
}


void MainWindow::on_equalBtn_clicked()
{
    float total = 0;
    if(vBool[0] && vBool[1] && calcType != NULL){
        switch(calcType){
            case '+':
                total = (values[0] + values[1]);
                break;
            case '-':
                break;
            case '*':
                break;
            case '/':
                break;
        }
        ui->textEdit->setText(QString::number(total));
        values[0] = total;
    }
}

