#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QObject>
#include <QtMath>
#include <string.h>
#include <stdio.h>

float values[3] = {0, 0, 0};
bool vBool[3] = {false, false, false};
char calcType = NULL;
bool decimalType = false;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    //setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

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
         if(decimalType == false){
            values[theValue] = value;
         }else{
             values[theValue] += value / qPow(10, getDecimalCount(theValue) + 1);
         }
         vBool[theValue] = true;
    }else{
        if(decimalType == false){
            values[theValue] *= 10;
            values[theValue] += value;
        }else{
            values[theValue] += value / qPow(10, getDecimalCount(theValue) + 1);
        }
        vBool[theValue] = true;
    }

    QString b;
    b.setNum(values[theValue]);

    ui->label->setText(b);
}


void MainWindow::typeFunction(){
    decimalType = false;
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

            case 3:
                calcType = '/';
                break;
        }
    }
}

void MainWindow::on_clearBtn_clicked()
{
    values[0] = values[1] = values[2] = 0;
    vBool[0] = vBool[1] = vBool[2] = false;

    calcType = NULL;
    ui->label->setText("");
}

void MainWindow::on_decimalBtn_clicked()
{
    if(decimalType == false){
        decimalType = true;
        if(vBool[0] == false){
            ui->label->setText("0.");
        }else{
           QString s = ui->label->text();
           ui->label->setText(s+".");
        }
    }
}

int MainWindow::getDecimalCount(float value ){
    bool start = false;
    int count = 0;
    QString b;
    b.number(value);

    for(QString val :   b){
        if(val == "."){
            start = true;
        }else if(start){
            count++;
        }
    }
    return count;
}

int MainWindow::getDecimalPart(float number){
    return 0;
}

void MainWindow::on_backBtn_clicked()
{
    if(calcType == NULL || vBool[1] == false){
        evaluationBackFunction(0);
    }else{
        evaluationBackFunction(1);
    }

    vBool[2] = false;
    values[2] = 0;
}

void MainWindow::evaluationBackFunction(int temp){
    if(vBool[temp]){
        QString b;
        b.setNum(values[temp]);
        if(b.length() == 1){
            vBool[0] = vBool[1] = false;
            calcType = NULL;
            decimalType = false;
            ui->label->clear();

        }else if(b.length() > 1){
            if(decimalType == true){
                int d = getDecimalPart(values[temp]) / 10;
                int i = (int)values[temp];
                QString a;
                a.setNum(values[temp]);
                float f = i + (d / (qPow(10, a.length())));
                values[temp] = f;

                QString b;
                b.setNum(values[temp]);
                ui->label->setText(b);

                if(getDecimalPart(values[temp]) == 0){
                    decimalType = false;
                }
            }else{
                int i =  (int)values[temp];
                i /= 10;
                values[temp] = i;

                QString b;
                b.setNum(values[temp]);
                ui->label->setText(b);
            }
        }
    }
}

void MainWindow::on_equalBtn_clicked()
{
    float total = 0;
    if(vBool[1]){
        vBool[2] = true;
        values[2] = values[1];
    }
    if(vBool[0] && vBool[2] && calcType != NULL){
        switch(calcType){
            case '+':
                total = (values[0] + values[2]);
                break;
            case '-':
                total = (values[0] - values[2]);
                break;
            case '*':
                total = (values[0] * values[2]);
                break;
            case '/':
                total = (values[0] / values[2]);
                break;
        }
        ui->label->setText(QString::number(total));
        values[0] = total;
        vBool[1] = false;
    }
}






