#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMainWindow>

class Window : public QWidget
{
    Q_OBJECT
public:
    Window (QWidget *parent=0);
private:
    QPushButton *but_A, *but_B, *but_C, *clearB, *exit;
    QLineEdit *line;
    QLabel *label;
private slots:
    void TextEntered(QString str);
    void SetA();
    void SetB();
    void SetC();
    void ExitMsg();
};

#endif // TEXTEDIT_H
