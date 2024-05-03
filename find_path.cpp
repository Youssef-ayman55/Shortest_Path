#include "find_path.h"
#include "ui_find_path.h"

find_path::find_path(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::find_path)
{
    ui->setupUi(this);
}
find_path::find_path(graph * graph_w): graph_w(graph_w), QWidget(nullptr), ui(new Ui::find_path)
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


void find_path::on_find_clicked()
{
    QString src=ui->city_1->text();
    QString des=ui->city_2->text();
    QVector<QString>* answer= graph_w->findpath(src,des);
    if(answer==nullptr){
        ui->find_warn->setText("There is no way to reach this city.");
    }else{
        /*
        double distance=0;
        QVector<QString>* answer= graph_w->findpath(src,des);
        auto it =answer->begin();
        while(1){
            if(it+1==answer->end())break;
            distance+=graph_w->getweight(*it,*(it+1));
        }
        ui->dist->setText(QString::number(distance));
        */
    }
}

