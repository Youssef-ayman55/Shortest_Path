#include "display_graph.h"
#include "ui_display_graph.h"
#include <vector>
#include <cstdlib>
#include <ctime>
display_graph::display_graph(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::display_graph)
{
    ui->setupUi(this);
}
display_graph::display_graph(graph * graph_w): graph_w(graph_w), QWidget(nullptr), ui(new Ui::display_graph)
{
    ui->setupUi(this);
    layout = new QGridLayout(this);
    view = new QGraphicsView;
    scene = new QGraphicsScene;
    //scene->setSceneRect(100,250,800,400);
    view->setScene(scene);
    view->setFixedSize(800,500);
    view->setStyleSheet("background:rgb(238,237,235);");
    layout->setRowMinimumHeight(0, 80);
    layout->addWidget(view, 1 , 0);
    vector = new QVector<node_display*>;
    std::vector<std::pair<int,QString>> temp;
    for(auto it = graph_w->my_graph.begin(); it != graph_w->my_graph.end(); it++){
        temp.push_back({it.value()->size(), it.key()});
    }
    std::sort(temp.begin(), temp.end());
    for(int i = 0; i < temp.size(); i++){
        node_display* t = new node_display;
        vector->push_back(t);
        srand(time(0));
        (*vector)[i]->setPos(300+ 50 * cos(exp(7 * i)), 300 +50 *sin(exp(7 * i)));
        (*vector)[0]->setPos(300, 300);
        scene->addItem((*vector)[i]);
        (*vector)[i]->setText(temp[i].second);
        for(int j = 0; j < i; j++){
            (*vector)[i]->connect((*vector)[j]);
        }
    }

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

