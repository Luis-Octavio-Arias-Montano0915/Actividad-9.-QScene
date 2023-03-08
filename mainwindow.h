#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPen>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_Captura_clicked();

    void on_actionAbrir_triggered();

    void on_actionGuardar_triggered();

    void on_actionOpne_triggered();

    void on_actionSave_triggered();

    void on_tableWidget_cellActivated(int row, int column);

    void on_pushButton_clicked();

    void on_Dibujar_clicked();

    void on_Limpiar_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene escena;
};
#endif // MAINWINDOW_H
