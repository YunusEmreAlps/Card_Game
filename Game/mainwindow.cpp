#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <time.h>
#include <QMouseEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Timer = new QTimer() ;

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
    Count++ ;

    ui->Result->setText("Move : "+QString::number(Count)) ; // Result

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
        card_1 = cardvalue ;
        Control = false ;
        Temp_1= index_2 ;
    }



    else if (ClickCounter == 2) {

        card_2 = cardvalue ;
        Temp_2 = index_2 ;
        Control = true ;
     }


    if((Control == true)&&(ClickCounter == 2))
    {

        if(card_1 != card_2)
         {
           QImage off_1(":/Logo/Brand/A.png") ;
           Brand[Temp_1]->setPixmap(QPixmap::fromImage(off_1)) ;
           Brand[Temp_2]->setPixmap(QPixmap::fromImage(off_1)) ;


            Brand[Temp_1]->Clicked = false ;
            Brand[Temp_2]->Clicked = false  ;
            ClickCounter = 0  ;
            Counter() ;
            Control = false ;

            show() ;
        }


        if(card_1 == card_2)
        {
          Brand[Temp_1]->setEnabled(false) ;
          Brand[Temp_2]->setEnabled(false) ;
          ClickCounter = 0  ;
          Control = false;

        }



    }

 }



