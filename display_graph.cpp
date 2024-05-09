#include "display_graph.h"
#include "ui_display_graph.h"
#include <vector>
#include <QQueue>
#include <QSet>
#include <QMap>
#include <QGraphicsLineItem>
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
    QSet<QString> displayed;
    std::vector<std::pair<int,QString>> temp;
    for(auto it = graph_w->my_graph.begin(); it != graph_w->my_graph.end(); it++){
        temp.push_back({it.value()->size(), it.key()});
    }
    std::sort(temp.begin(), temp.end());
    QQueue<QString> queue;
    QMap<QString, node_display *> parents;
    int currentx = 300;
    int currenty = 300;
    int global_counter = 0;
    for(int i = temp.size() - 1; i>= 0; i--){
        if(displayed.find(temp[i].second) == displayed.end()){
            queue.enqueue(temp[i].second);
            while(queue.size() > 0){
                node_display * current = new node_display(graph_w);
                scene->addItem(current);
                current->parent = parents[queue.front()];
                if(current->parent == nullptr){
                    current->setPos(currentx,currenty);
                    currentx += 100;
                    currenty += 100;
                }
                else{
                    current->phase = current->parent->phase + exp(7 * global_counter);
                    current->setPos(current->parent->x()+ current->parent->radius * cos(current->phase),current->parent->y()+ current->parent->radius * sin(current->phase));
                    global_counter++;
                    current->radius = current->parent->radius/2;
                }
                current->setText(queue.front());
                for(int i =0; i < vector->size(); i++){
                    QString tem = vector->at(i)->na;
                    if(graph_w->getweight(tem, current->na) != -1 && vector->at(i) != current->parent){
                        current->connections.push_back(vector->at(i));
                    }
                }
                vector->push_back(current);
                for(int j =0; j < vector->size() - 1; j++){
                    (*vector)[vector->size() - 1]->repel((*vector)[j]);
                }
                for(int j = 0; j< graph_w->my_graph[queue.front()]->size(); j++){
                    if(displayed.find(graph_w->my_graph[queue.front()]->at(j).first) == displayed.end()){
                        queue.enqueue(graph_w->my_graph[queue.front()]->at(j).first);
                        parents[graph_w->my_graph[queue.front()]->at(j).first] = current;
                        displayed.insert(graph_w->my_graph[queue.front()]->at(j).first);
                    }
                }
                displayed.insert(queue.front());
                queue.dequeue();
            }
        }
    }
}

display_graph::~display_graph()
{
    for(int i = 0; i < vector->size(); i++){
        delete vector->at(i);
    }
    delete ui;
    delete vector;
    delete layout;
    delete scene;
    delete view;
}

void display_graph::on_back_to_main_clicked()
{
    emit back();
    delete this;
}

