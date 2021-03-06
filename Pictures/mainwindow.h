#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include "linked_list.h"
#include "pict.h"
#include "bst.h"
#include <fstream>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QPixmap pix;
    linked_list<pict>pictures;
    linked_list<pict>::iterator it;
    bst<string,linked_list<pict>::iterator>bst_pictures;
    char*a;
    char*b;
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_Import_clicked();

private:
    Ui::MainWindow *ui;
    string text;
};

#endif // MAINWINDOW_H
