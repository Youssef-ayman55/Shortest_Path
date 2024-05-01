#include "delete_city.h"
#include "ui_delete_city.h"

delete_city::delete_city(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::delete_city)
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

