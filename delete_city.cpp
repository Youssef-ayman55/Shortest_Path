#include "delete_city.h"
#include "ui_delete_city.h"
#include <QString>
delete_city::delete_city(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delete_city)
{
    ui->setupUi(this);
}
delete_city::delete_city(graph * graph_w): graph_w(graph_w), QWidget(nullptr), ui(new Ui::delete_city)
{
    ui->setupUi(this);
}
delete_city::~delete_city()
{
    delete ui;
}

void delete_city::on_back_to_main_clicked()
{
    emit back();
    delete this;
}


void delete_city::on_delete_button_clicked()
{
    QString name = ui->delete_name->text();
    if(ui->delete_name->text() == ""){
        ui->delete_warning->setText("No Name Was Entered!");
    }
    else{
        if(!graph_w->exists(name)){
            ui->delete_warning->setText("No City with this name!");
        }
        else{
            graph_w->dcity(name);
            ui->delete_warning->setText("Deletion Succesfull!");
        }
    }
}


void delete_city::on_clear_clicked()
{
    graph_w->reset();
    ui->cleared->setText("Graph Cleared!");
}

