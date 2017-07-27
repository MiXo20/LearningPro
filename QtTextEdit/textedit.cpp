#include "textedit.h"
#include "exitmsg.h"
#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>

Window::Window(QWidget *parent): QWidget (parent)
{
    but_A= new QPushButton("A");
    but_B= new QPushButton("B");
    but_C= new QPushButton("C");
    clearB= new QPushButton("&Clear");

    clearB->setEnabled(false);

    exit= new QPushButton("&Exit");
    line= new QLineEdit;
    label= new QLabel("Push the button :)");

    QHBoxLayout *hLayoutUp=new QHBoxLayout;
    QHBoxLayout *hLayoutDown= new QHBoxLayout;
    QVBoxLayout *rightLayout=new QVBoxLayout;
    QVBoxLayout *leftLayout= new QVBoxLayout;
    QVBoxLayout *mainLayout=new QVBoxLayout;


    hLayoutDown->addLayout(leftLayout);
    hLayoutDown->addLayout(rightLayout);
    mainLayout->addLayout(hLayoutUp);
    mainLayout->addLayout(hLayoutDown);

    rightLayout->addWidget(clearB);
    rightLayout->addWidget(exit);

    leftLayout->addWidget(line);
    leftLayout->addWidget(but_A);
    leftLayout->addWidget(but_B);
    leftLayout->addWidget(but_C);

    hLayoutUp->addWidget(label);

    setLayout(mainLayout);
    setWindowTitle("HomeWork Qt1");
    clearB->setDefault(true);
    label->setFixedHeight(20);
    line->setReadOnly(true);

    connect(exit,SIGNAL(clicked(bool)),this,SLOT(ExitMsg()));
    connect(line,SIGNAL(textChanged(QString)),this,SLOT(TextEntered(QString)));
    connect(clearB,SIGNAL(clicked(bool)),line,SLOT(clear()));
    connect(but_A,SIGNAL(clicked(bool)),this,SLOT(SetA()));
    connect(but_B,SIGNAL(clicked(bool)),this,SLOT(SetB()));
    connect(but_C,SIGNAL(clicked(bool)),this,SLOT(SetC()));

}

void Window::TextEntered(QString str)
{
    clearB->setEnabled(!str.isEmpty());
}

void Window::SetA()
{

    line->insert("A");
}

void Window::SetB()
{

    line->insert("B");
}

void Window::SetC()
{

    line->insert("C");
}

void Window::ExitMsg()
{
    QMessageBox *a= new QMessageBox;
    a->setStandardButtons(QMessageBox::Yes|QMessageBox::Cancel);
    a->setDefaultButton(QMessageBox::Cancel);
    a->setWindowTitle("Exit");
    a->setText("Do You realy want to exit?");
    a->show();
    if(a->exec()==QMessageBox::Yes)
        QApplication::quit();
}
