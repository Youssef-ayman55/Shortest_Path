#include "add_city.h"
#include "ui_add_city.h"

add_city::add_city(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::add_city)
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

