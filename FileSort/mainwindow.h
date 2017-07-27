#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QString filename;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_Open_clicked();
    void on_Sort_By_Alpha_clicked();
    void on_Sort_By_Count_clicked();
    void on_Save_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
