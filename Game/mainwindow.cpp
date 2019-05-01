#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>
#include <QMouseEvent>
#include <QMessageBox>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Timer = new QTimer() ;
    //Timer->start(100) ;
    connect(Timer,SIGNAL(timeout()),this,SLOT(Process())) ;


   srand(time(nullptr)) ; // Random Number
   Creator() ;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Counter()
{
    if(card_1 != card_2)
    {
        Count++ ;

        ui->Result->setText("Move : "+QString::number(Count)) ; // Result
    }

    if(FinishCounter == 12)
    {
        QMessageBox::information(this,"Congratulations","Your Score :"+QString::number(Count)+"") ;
    }

}

void MainWindow:: Creator()
{
       Count = 0 ;

       int X=100 , Y=100 ; // 100 - 970  |100|10|100|10|100|10|100|10|100|10|100|10|100|10|100|

        for( int i=0 ; i<3 ; i++) // 100 - 320
         {
           for(int j=0 ; j<8 ; j++)
           {
               Cards *card = new Cards(this) ;
               Brand.push_back(card);
               card->setGeometry(X,Y,100,100) ;

               Random_1= rand()%12+1 ;
               Num[index] = Random_1 ;

               int Count_2 = 0 ;

               while(1)
               {
                   for(int k=0 ; k<index+1 ; k++ )
                   {
                      if(Num[k] == Random_1)
                      {
                          Count_2++ ;
                      }
                   }

                   if(Count_2 <= 2)
                   {
                       break ;
                   }

                   else{

                       Random_1= rand()%12+1 ;
                       Num[index] = Random_1 ;
                       Count_2 = 0  ;

                   }

               }


               card->mainframe = this ;
               card->mainImage = Random_1 ;
               card->Number=index ;


               index++ ;



               card->show();

               X+=110 ;
           }

          Y+=110 ;

          X=100 ;
   }

}



void MainWindow::Process(){

    ClickCounter++ ;

    if(ClickCounter == 1 )
    {

           card_1 = cardvalue  ;
           Control = false ;
           Temp_1= index_2 ;


        if(card_1 == 1 ){ui->Card_1->setText("Card_1 : Adobe") ; }
        else if(card_1 == 2 ){ui->Card_1->setText("Card_1 : Amazon"); }
        else if(card_1 == 3 ){ui->Card_1->setText("Card_1 : Dell") ; }
        else if(card_1 == 4 ){ui->Card_1->setText("Card_1 : Disney"); }
        else if(card_1 == 5 ){ui->Card_1->setText("Card_1 : Dropbox") ; }
        else if(card_1 == 6 ){ui->Card_1->setText("Card_1 : Facebook"); }
        else if(card_1 == 7 ){ui->Card_1->setText("Card_1 : Google") ; }
        else if(card_1 == 8 ){ui->Card_1->setText("Card_1 : Linkedin"); }
        else if(card_1 == 9 ){ui->Card_1->setText("Card_1 : Windows") ; }
        else if(card_1 == 10 ){ui->Card_1->setText("Card_1 : Netflix"); }
        else if(card_1 == 11 ){ui->Card_1->setText("Card_1 : Tesla") ; }
        else if(card_1 == 12 ){ui->Card_1->setText("Card_1 : intel"); }

    }


    if (ClickCounter == 2) {

        card_2 = cardvalue ;
        Temp_2 = index_2 ;
        Control = true ;

        QApplication::processEvents() ;
        QThread::msleep(250) ;

        if(card_2 == 1 ){ui->Card_2->setText("Card_2 : Adobe") ; }
        else if(card_2 == 2 ){ui->Card_2->setText("Card_2 : Amazon"); }
        else if(card_2 == 3 ){ui->Card_2->setText("Card_2 : Dell") ; }
        else if(card_2 == 4 ){ui->Card_2->setText("Card_2 : Disney"); }
        else if(card_2 == 5 ){ui->Card_2->setText("Card_2 : Dropbox") ; }
        else if(card_2 == 6 ){ui->Card_2->setText("Card_2 : Facebook"); }
        else if(card_2 == 7 ){ui->Card_2->setText("Card_2 : Google") ; }
        else if( card_2 == 8 ){ui->Card_2->setText("Card_2 : Linkedin"); }
        else if(card_2 == 9 ){ui->Card_2->setText("Card_2 : Windows") ; }
        else if(card_2 == 10 ){ui->Card_2->setText("Card_2 : Netflix"); }
        else if(card_2 == 11 ){ui->Card_2->setText("Card_2 :Tesla") ; }
        else if(card_2 == 12 ){ui->Card_2->setText("Card_2 :intel"); }
     }


 if((Control == true)&&(ClickCounter == 2))
    {

        if(card_1 != card_2)
         {
           QImage off_1(":/Logo/Brand/A.png") ;
           Brand[Temp_1]->setPixmap(QPixmap::fromImage(off_1)) ;
           Brand[Temp_2]->setPixmap(QPixmap::fromImage(off_1)) ;

           Brand[Temp_1]->Clicked = false ;
           Brand[Temp_2]->Clicked = false ;
           ClickCounter = 0  ;

            Counter() ;
            Control = false ;

            show() ;

        }

        if(card_1 == card_2)
        {
          Brand[Temp_1]->setEnabled(false) ;
          Brand[Temp_2]->setEnabled(false) ;
          FinishCounter++ ;
          Counter() ;
          ClickCounter = 0  ;
          Control = false;

        }


    }

}

