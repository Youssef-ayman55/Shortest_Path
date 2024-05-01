#include "find_path.h"
#include "ui_find_path.h"

find_path::find_path(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::find_path)
{
    ui->setupUi(this);
}

find_path::~find_path()
{
    delete ui;
}

void find_path::on_back_to_main_clicked()
{
    emit back();
    delete this;
}

