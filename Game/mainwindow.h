#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QTimer>
#include "cards.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() ;

    void Counter() ;

    void Creator() ;

    void Process() ;

    QList<Cards*>Brand;

    QTimer *Timer ;

    int card_1 = 0 , card_2 = 0 ;

    int cardvalue;

    int Num[24] ; // Same 2 image

    int Random_1 ; // Random number

    int index = 0 ;

    int Count = 0  ; // use Counter function

    int ClickCounter = 0 ;

    int FinishCounter = 0 ;

    int index_2 ;

    int Temp_1 , Temp_2 ;

    bool Control = false ;

private slots:


private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
