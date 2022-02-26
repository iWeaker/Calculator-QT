#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void setNum();
    void typeFunction();
    void on_clearBtn_clicked();
    void on_equalBtn_clicked();
    void on_decimalBtn_clicked();
    void on_backBtn_clicked();

private:
    Ui::MainWindow *ui;
    QPoint startPos;
    void addValues(int, int);
    int getDecimalCount(float);
    void evaluationBackFunction(int);
    int getDecimalPart(float);
protected:
    //MouseEvents
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
