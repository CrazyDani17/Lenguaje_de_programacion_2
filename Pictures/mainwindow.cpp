#include "mainwindow.h"
#include "ui_mainwindow.h"

void save_list(linked_list<pict >&vt,const char * file)
{
    /*ofstream of(file,ios::binary);
    size_t size_v;
    for(linked_list<pict>::iterator i=vt.begin();i!=vt.end();++i){
        size_v=(*i).show_name().size();
        of.write((char*)&size_v,sizeof(size_t));
        of.write((*i).show_name().c_str(),size_v);
    }*/
    ofstream archivo;
    archivo.open(file,ios::out);
    archivo.clear();
    for(linked_list<pict >::iterator it=vt.begin();it!=vt.end();++it){
        archivo<<(*it).show_name()<<endl;
        archivo<<(*it).show_file()<<endl;
    }
    archivo.close();
}

void load_list(linked_list<pict >&vt,const char * file)
{


    /*ifstream ifs(file,ios:: binary);
    pict s;
    char * vt_b;
    size_t size_v;
    while(ifs.read((char*)&size_v, sizeof(int))){
        vt_b=new char[size_v + 1];
        ifs.read(vt_b,size_v);
        vt_b[size_v]=0;
        s.show_name()=vt_b;
        vt.push_back(s);
    }*/
    ifstream ifs;
    ifs.open(file,ios::in);
    pict a;
    string s;
    getline(ifs,s);
    while(s!=""){
        a.add_name(s);
        getline(ifs,s);
        a.add_file(s);
        vt.push_back(a);
        getline(ifs,s);
    }
    ifs.close();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pict img1("Verde","/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga.jpg");
    //img1.add_tag("Paisaje");
    //img1.add_tag("Verde");
    //pict img2("Ciudad","/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga2.jpg");
    //img2.add_tag("Ciudad");
    //img2.add_tag("Paisaje");
    //pict img3("Arte","/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga3.jpg");
    //img3.add_tag("Arte");
    //pict img4("Arcoiris","/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/descarga4.jpg");
    //img4.add_tag("Arcoiris");
    load_list(pictures,"/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/file.txt");
    /*
    pictures.push_back(img1);
    pictures.push_back(img2);
    pictures.push_back(img3);
    pictures.push_back(img4);
    */
    it=pictures.begin();
    bst_pictures.insert((*it).show_name(),it);++it;
    bst_pictures.insert((*it).show_name(),it);++it;
    bst_pictures.insert((*it).show_name(),it);++it;
    bst_pictures.insert((*it).show_name(),it);

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
    save_list(pictures,"/media/crazydani17/3CC4EEECC4EEA6FC/Users/danie/OneDrive/Documentos/Pictures/pictures/file.txt");
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(it!=pictures.last()){
        ++it;
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

void MainWindow::on_pushButton_3_clicked()
{
    QString new_name=ui->textEdit_name->toPlainText();
    QString new_file=ui->textEdit_file->toPlainText();
    string  nn = new_name.toStdString();
    string  nf = new_file.toStdString();
    a=new char[nn.size()];
    a[nn.size()]=0;
    for(size_t i=0;i<nn.size();i++){
        a[i]=nn[i];
    }
    b=new char[nf.size()];
    b[nf.size()]=0;
    for(size_t i=0;i<nf.size();i++){
        b[i]=nf[i];
    }
    pict new_img(a,b);
    pictures.push_back(new_img);
    bst_pictures.insert(new_img.show_name(),pictures.last());
}

void MainWindow::on_pushButton_4_clicked()
{
    if(it!=pictures.last()){
        ++it;
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
    if(it!=pictures.begin()){
        --it;
    }
    else{
        it=pictures.last();
    }
    //bst_pictures.remove((*it).show_name());
    pictures.remove(it);

}

void MainWindow::on_pushButton_5_clicked()
{
    QString searcherd_name=ui->textEdit_search->toPlainText();
    string  sn = searcherd_name.toStdString();
    if(bst_pictures.find(sn)){
        it=bst_pictures[sn];
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
    else{
        ui->label_picture->setText("no find");
        ui->label_txt->setText("");
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    QString new_name=ui->textEdit_name->toPlainText();
    string  nn = new_name.toStdString();
    a=new char[nn.size()];
    a[nn.size()]=0;
    for(size_t i=0;i<nn.size();i++){
        a[i]=nn[i];
    }
    bst_pictures.rename((*it).show_name(),nn);
    (*it).add_name(a);
}

void MainWindow::on_Import_clicked()
{
    QString image_file = QFileDialog::getOpenFileName(this,"Open Image","/home/crazydani17","All File(*.*)");
    string file= image_file.toStdString();
    a=new char[file.size()];
    a[file.size()]=0;
    for(size_t i=0;i<file.size();i++){
        a[i]=file[i];
    }
    ui->textEdit_file->setText(a);
}
