#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include_all.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE




class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *mytimer;
    void UpdateTemp(void);
    void init_temp(void);
private:
    Ui::MainWindow *ui;
   // QTimer *mytimer;// = new QTimer(this);
};
#endif // MAINWINDOW_H
