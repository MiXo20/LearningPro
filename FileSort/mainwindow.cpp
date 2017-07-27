#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QString>
#include <QTextStream>
#include <QMap>
#include <QMultiMap>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Open_clicked()
{
    QFileDialog *fileOpen= new QFileDialog;
    filename=fileOpen->getOpenFileName(this ,"Open File","","*.txt");
    QFile file(filename);
    QTextStream in(&file);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    ui->textBrowser->setText(in.readAll());
    ui->statusBar->showMessage(filename);
    file.close();
}


void MainWindow::on_Sort_By_Alpha_clicked()
{
    QFile file(filename);
    QTextStream in(&file);
    QString str;
    QMap<QString,size_t> map;
    auto it=map.begin();
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!in.atEnd())
        {
            in>>str;
            it=map.find(str);
            if(it!=map.end())
                map[str]+=1;
            else
                map[str]=1;
        }
        ui->textBrowser->setText(str="");
        for(it=map.begin();it!=map.end();it++)
        {
            ui->textBrowser->insertPlainText(it.key());
            ui->textBrowser->insertPlainText(": ");
            ui->textBrowser->insertPlainText(QString::number(it.value()));
            ui->textBrowser->insertPlainText("\n");
        }

    }
    file.close();
}



void MainWindow::on_Sort_By_Count_clicked()
{
    QFile file(filename);
    QTextStream in(&file);
    QString str;
    QMap<QString,size_t> map;
    QMultiMap<size_t,QString> multimap;
    auto it=map.begin();
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while(!in.atEnd())
        {
            in>>str;
            it=map.find(str);
            if(it!=map.end())
                map[str]+=1;
            else
                map[str]=1;
        }
        for(it=map.begin();it!=map.end();it++)
        {
            multimap.insert(it.value(),it.key());
        }
        ui->textBrowser->setText(str="");
        for(auto it_m=--multimap.end();it_m!=--multimap.begin();it_m--)
        {
            ui->textBrowser->insertPlainText(it_m.value());
            ui->textBrowser->insertPlainText(": ");
            ui->textBrowser->insertPlainText(QString::number(it_m.key()));
            ui->textBrowser->insertPlainText("\n");
        }
    }
}

void MainWindow::on_Save_clicked()
{
    QFileDialog *fileSave= new QFileDialog;
    QString filename=fileSave->getSaveFileName(this ,"Save File","","*.txt");
    QFile file(filename);
    QTextStream out(&file);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        out <<ui->textBrowser->document()->toPlainText();
    file.flush();
    file.close();
}
