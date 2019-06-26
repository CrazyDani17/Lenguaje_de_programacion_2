#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file="hola";
    name="mundo";
    tags="<p>hola</p><p>mundo</p>";
    text= "File: " + file + "<p>Name:" + name + "</p>" + "Tags: " + tags;
    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    pictures.push_back("C:/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga.jpg");
    pictures.push_back("C:/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga2.jpg");
    pictures.push_back("C:/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga3.jpg");
    pictures.push_back("C:/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga4.jpg");
    it=pictures.begin();
    string txt=*it;
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete a;
}

void MainWindow::on_pushButton_2_clicked()
{
    /*file="hola";
    name="mundo";
    tags="<p>hola</p><p>mundo</p>";
    text= "File: " + file + "<p>Name:" + name + "</p>" + "Tags: " + tags;

    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    */
    ++it;
    if(it!=pictures.end()){

    }
    else{
        it=pictures.begin();
    }
    string txt=*it;
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);

}

void MainWindow::on_pushButton_clicked()
{
    if(it!=pictures.begin()){
        --it;
    }
    else{
        it=pictures.last();
    }
    string txt=*it;
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);
}
