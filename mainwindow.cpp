#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <qfiledialog.h> //Metodos que ayudan a retornar la direcicon para abrir o guardar el archivo
#include <QDebug>
#include <QTableWidgetItem>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Neuronas");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Captura_clicked()
{
    qDebug() << "ID: \n";
    ui->res->setText(QString::number(ui->Id->value()));
    qDebug() << "Voltaje: \n";
    ui->res->setText(QString::number(ui->Voltaje->value()));
    qDebug() << "Posicion X: \n";
    ui->res->setText(QString::number(ui->Posicionx->value()));
    qDebug() << "Posicion Y: \n";
    ui->res->setText(QString::number(ui->PosicionY->value()));
    qDebug() << "RED: \n";
    ui->res->setText(QString::number(ui->red->value()));
    qDebug() << "GREEN: \n";
    ui->res->setText(QString::number(ui->green->value()));
    qDebug() << "BLUE: \n";
    ui->res->setText(QString::number(ui->blue->value()));
}

//on_action  Crear el slot de abrir y guardar con la funcion trigered
//void mianwindow::on_actionAbrir_triggered()
//poner std "abrir" "guardar"
//despues de std "abrir":
//QString Filename= QFileDialog::getOpenFileName(this,"Abrir archivo" , ".", "imagenes (*.jpg)", ); //en el . , poner la direccion del archivo, extension del archivo
//crear un string debajo del QString
//string file=Filename.toStdString();
//std::cout<<file<<std::endl; //Muestra la direccion donde se abrio el archivo


void MainWindow::on_actionAbrir_triggered()
{
    std::cout<<"Abrir"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Abrir archivo", ".", "imagenes (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;
}


void MainWindow::on_actionGuardar_triggered()
{
    std::cout<<"Guardar"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Guardar archivo", ".", "imagenes (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;
}


void MainWindow::on_actionOpne_triggered()
{
    std::cout<<"Open"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Open Data", ".", "images (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;

}


void MainWindow::on_actionSave_triggered()
{
    std::cout<<"Save Data"<<std::endl;
    QString Filename= QFileDialog::getOpenFileName(this, "Save Data", ".", "images (*.jpg)");
    std::string file= Filename.toStdString();
    std::cout<<file<<std::endl;
}


void MainWindow::on_tableWidget_cellActivated(int row, int column)
{

}


void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setColumnCount(7);
    QStringList headers = {"Id", "Voltaje", "PosicionX", "PosicionY", "Red", "Green", "Blue" }; //R G B
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(10);
    QTableWidgetItem *id = new QTableWidgetItem("1");  //Muestra el Id
    QTableWidgetItem *V = new QTableWidgetItem("-69"); //Muestra el voltaje
    QTableWidgetItem *X = new QTableWidgetItem("32");   //Muestra posicion x
    QTableWidgetItem *Y = new QTableWidgetItem("12");   //Muestra posicion y
    QTableWidgetItem *R = new QTableWidgetItem("5");    //Muestra RED
    QTableWidgetItem *B = new QTableWidgetItem("7");    //Muestra Blue
    QTableWidgetItem *G = new QTableWidgetItem("8");    //Muestra Green

    ui->tableWidget->setItem(0,1,id);
    ui->tableWidget->setItem(0,1,V);
    ui->tableWidget->setItem(0,2,X);
    ui->tableWidget->setItem(0,3,Y);
    ui->tableWidget->setItem(0,4,R);
    ui->tableWidget->setItem(0,5,G);
    ui->tableWidget->setItem(0,6,B);
}

//void in_dibujar_button_clicked
//{
//  QPen pen;
//  pen.setWitdh(5); //Contorno
//  QColor color(20, 200, 50); //Valor rgb, se ponen los atributos de las neuronas, se pone la posicion
// pen.setColor(color);
//  escena.addElipse(100,100, 50,50, pen); //recibe la posicion y lo ancho, 50 50 es el voltaje
// escena.addElipse(50, -10, 50, 50, pen);
// escena.addElipse(30, 52, 5, 5, pen);
//  escena.addElipse(150, 70, 5, 5, pen);
//  ui->graphicsView.setScene(&escena); //Referencia del objeto escena, a escena hay que darle algo
// }

// void in_onLimpiar
// {
// escena.clear();
// }

void MainWindow::on_Dibujar_clicked()
{
    QPen pen;
    pen.setWidth(5);
    QColor color(20, 200, 50); //R , G , B
    pen.setColor(color);
    escena.addEllipse(100, 100, 50, 50, pen); //Posicion, ancho, voltaje, voltaje, Contorno
    escena.addEllipse(50, 20, 50, 50, pen);
    escena.addEllipse(30, 52, 25, 25, pen);
    escena.addEllipse(150, 70, 5, 5, pen);
    escena.addEllipse(200, 35, 15, 15, pen);
    ui->graphicsView->setScene(&escena);;
}


void MainWindow::on_Limpiar_clicked()
{
    escena.clear();
}

