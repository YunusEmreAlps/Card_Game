#include "cards.h"
#include "mainwindow.h"
#include <QTime>
#include <QMessageBox>

Cards::Cards(QWidget *parent) : QLabel(parent)
{
        QImage off(":/Logo/Brand/A.png") ;
        setScaledContents(true) ;
        setPixmap(QPixmap::fromImage(off)) ;
        Clicked = false ;

}

void Cards::mousePressEvent(QMouseEvent *)
{
     if(!Clicked)
   {

            QImage Image(":/Logo/Brand/"+QString::number(mainImage)+".png") ;
            setPixmap(QPixmap::fromImage(Image));

           // Clicked = true ;

            mainframe->cardvalue = mainImage ;
            mainframe->index_2 = Number ;
            mainframe ->Process() ;

    }

}




