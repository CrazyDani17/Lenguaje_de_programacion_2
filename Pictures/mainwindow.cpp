#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pict img1("Verde","/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga.jpg");
    //img1.add_tag("Paisaje");
    //img1.add_tag("Verde");
    pict img2("Ciudad","/media/crazydani17/3CC4EEECC4EEA6FC//Users/danie/OneDrive/Documentos/Pictures/pictures/descarga2.jpg");
    //img2.add_tag("Ciudad");
    //img2.add_tag("Paisaje");
    pict img3("Arte","/media/crazydani17/3CC4EEECC4EEA6FC//Users/danie/OneDrive/Documentos/Pictures/pictures/descarga3.jpg");
    //img3.add_tag("Arte");
    pict img4("Arcoiris","/media/crazydani17/3CC4EEECC4EEA6FC//Users/danie/OneDrive/Documentos/Pictures/pictures/descarga4.jpg");
    //img4.add_tag("Arcoiris");
    pictures.push_back(img1);
    pictures.push_back(img2);
    pictures.push_back(img3);
    pictures.push_back(img4);
    it=pictures.begin();
    text=(*it).show_all();

    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);

    it=pictures.begin();
    string txt=(*it).show_file();
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

    ++it;
    if(it!=pictures.end()){

    }
    else{
        it=pictures.begin();
    }
    text=(*it).show_all();
    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    string txt=(*it).show_file();
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
    text=(*it).show_all();
    a=new char[text.size()];
    a[text.size()]=0;
    for(size_t i=0;i<text.size();i++){
        a[i]=text[i];
    }
    ui->label_txt->setText(a);
    string txt=(*it).show_file();
    a=new char[txt.size()];
    a[txt.size()]=0;
    for(size_t i=0;i<txt.size();i++){
        a[i]=txt[i];
    }
    pix={a};
    ui->label_picture->setPixmap(pix);
}
