#include "display_graph.h"
#include "ui_display_graph.h"

display_graph::display_graph(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::display_graph)
{
    ui->setupUi(this);
}

display_graph::~display_graph()
{
    delete ui;
}

void display_graph::on_back_to_main_clicked()
{
    emit back();
    delete this;
}

