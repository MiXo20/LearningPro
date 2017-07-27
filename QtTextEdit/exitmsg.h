#ifndef EXITMSG_H
#define EXITMSG_H
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>

class MsgBox: public QWidget
{

    Q_OBJECT
private:
    QPushButton *yes,*no;
    QVBoxLayout *l1;
    QHBoxLayout *l2;
    QLabel *label;
public:
    MsgBox()
    {
        yes=new QPushButton("&Yes");
        no=new QPushButton("&No");
        l2=new QHBoxLayout;
        label= new QLabel("Do you want to exit?");
        l2->addWidget(yes);
        l2->addWidget(no);
        l1= new  QVBoxLayout;
        l1->addWidget(label);
        l1->addLayout(l2);
        setLayout(l1);
        setWindowTitle("Exit?");

        connect(no,SIGNAL(clicked(bool)),this,SLOT(close()));
        connect(yes,SIGNAL(clicked(bool)),qApp,SLOT(quit()));

    }
};


#endif // EXITMSG_H
