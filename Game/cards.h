#ifndef CARDS_H
#define CARDS_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QMouseEvent>

class MainWindow ;


class Cards : public QLabel
{
    Q_OBJECT
public:
    explicit Cards(QWidget *parent = nullptr);

    MainWindow *mainframe ;

    int mainImage ;

    QTimer *Timer ;

    int Number ;

    int ClickCounter_2 = 0 ;

    bool Clicked = false ;

signals:

public slots:


protected:

        void mousePressEvent(QMouseEvent *) ;

};

#endif // CARDS_H
