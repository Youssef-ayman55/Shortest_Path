#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graph_w = new graph;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete graph_w;
}

void MainWindow::reset()
{
    ui->setupUi(this);
}

void MainWindow::on_add_city_clicked()
{
    add_city_w = new add_city(graph_w);
    setCentralWidget(add_city_w);
    QObject::connect(add_city_w,&add_city::back,this,&MainWindow::reset);
}



void MainWindow::on_delete_city_clicked()
{
    delete_city_w = new delete_city(graph_w);
    setCentralWidget(delete_city_w);
    QObject::connect(delete_city_w,&delete_city::back,this,&MainWindow::reset);
}


void MainWindow::on_display_graph_clicked()
{
    display_graph_w = new display_graph(graph_w);
    setCentralWidget(display_graph_w);
    QObject::connect(display_graph_w,&display_graph::back,this,&MainWindow::reset);
}


void MainWindow::on_find_path_clicked()
{
    find_path_w = new find_path(graph_w);
    setCentralWidget(find_path_w);
    QObject::connect(find_path_w,&find_path::back,this,&MainWindow::reset);
}

