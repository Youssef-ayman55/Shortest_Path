#include "graph.h"
#include <QString>
#include <QVector>
#include <QMap>
#include <QPair>
graph::graph() {}
bool graph::exists(QString name){
    if(my_graph.find(name)==my_graph.end()){
        return false;
    }
    return true;
}
void graph::addcity(QString name){
    if(!exists(name)){
        my_graph[name]=new QVector<QPair<QString,double>>;
    }
}
void graph::dcity(QString name){
    if(exists(name)){
        my_graph.erase(my_graph.find(name));
    }
}
void graph::connectcities(QString name1, QString name2, double weight){
    if(!exists(name1) || !exists(name2)){
        //
        return;
    }
    my_graph[name1]->push_back(std::make_pair(name2,weight));
    my_graph[name2]->push_back(std::make_pair(name1,weight));
}
QVector<QString>* graph::findpath(QString src, QString des){
    if(exists(src) && exists(des)){
        QVector<QString>* answer=new QVector<QString>;
        answer->push_back(src);
        //implement
        //dijkstra
        //algorithm
        //here
        return answer;
    }
    else return nullptr;
}
double graph::getweight(QString name1, QString name2)
{
    double distance = -1;
    if(my_graph[name1]->size() > my_graph[name2]->size()){
        for(int i = 0; i< my_graph[name2]->size(); i++){
            if(my_graph[name2]->at(i).first == name1){
                distance = my_graph[name2]->at(i).second;
                break;
            }
        }
    }
    else{
        for(int i = 0; i< my_graph[name1]->size(); i++){
            if(my_graph[name1]->at(i).first == name2){
                distance = my_graph[name1]->at(i).second;
                break;
            }
        }
    }
    return distance;
}
