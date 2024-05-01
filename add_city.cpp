#include "add_city.h"
#include "ui_add_city.h"
#include <QString>
add_city::add_city(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_city)
{
    ui->setupUi(this);
}
add_city::add_city(graph * graph_w): graph_w(graph_w), QWidget(nullptr), ui(new Ui::add_city)
{
    ui->setupUi(this);
}
add_city::~add_city()
{
    delete ui;
}

void add_city::on_back_to_main_clicked()
{
    emit back();
    delete this;
}


void add_city::on_add_clicked()
{
    QString name = ui->add_name->text();
    name.simplified().replace( " ", "" );
    if(ui->add_name->text() == ""){
        ui->add_warning->setText("No Name Was Entered!");
    }
    else{
        if(graph_w->exists(name)){
            ui->add_warning->setText("City Was Already Added!");
        }
        else{
            graph_w->addcity(name);
            ui->add_warning->setText("Addition Succesful!");
        }
    }
}


void add_city::on_connect_clicked()
{
    QString name1 = ui->city_1->text();
    QString name2 = ui->city_2->text();
    QString distanc = ui->distance->text();

    if(name1 == "" || name2 == ""||distanc ==""){
        ui->connect_warning->setText("One Of The Fields Is Empty!");
        return;
    }
    double distance = distanc.toDouble();
    if(!graph_w->exists(name1) || !graph_w->exists(name2)){
        ui->connect_warning->setText("One Of The Cities Was Not Added!");
    }
    else if(graph_w->getweight(name1, name2) == -1){
        graph_w->connectcities(name1, name2, distance);
        ui->connect_warning->setText("Connection Succesful!");
    }
    else{
        ui->connect_warning->setText("The Cities Are Already Connected!");
    }
}

