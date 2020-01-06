#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tc = new tempconverter(this);

    QObject::connect(ui->dialCelsius, SIGNAL(valueChanged(int)), tc, SLOT(setTempCelsius(int)));
    QObject::connect(tc, SIGNAL(tempCelsiusChanged(int)), ui->dialCelsius, SLOT(setValue(int)));
    QObject::connect(ui->dialFahrenheith, SIGNAL(valueChanged(int)), tc, SLOT(setTempFahrenheit(int)));
    QObject::connect(tc, SIGNAL(tempFahrenheitChanged(int)), ui->dialFahrenheith, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
