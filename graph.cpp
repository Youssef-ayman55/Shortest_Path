#include "graph.h"
#include <QString>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QPair>
#include <QQueue>
#include <algorithm>
#include <iostream>
graph::graph() {
    QFile nodesfile(":/files/nodes.txt");
    if (nodesfile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&nodesfile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            addcity(line);
        }
        nodesfile.close();
    }
    QFile connectfile(":/files/connections.txt");
    if(connectfile.open(QIODevice::ReadOnly)){
        QTextStream in(&connectfile);
        while (!in.atEnd())
        {
            QString node1;
            QString node2;
            QString weight;
            in>>node1;
            in>>node2;
            in>>weight;
            double w= weight.toDouble();
            connectcities(node1,node2,w);
        }
        connectfile.close();
    }
}
graph::~graph() {
    //write the code of nodes and connections here.
}
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
        for(int i=0; i<my_graph[name]->size(); i++){
            QString temp= my_graph[name]->at(i).first;
            for(int j=0; j<my_graph[temp]->size(); j++){
                if(my_graph[temp]->at(j).first==name){
                    my_graph[temp]->erase(my_graph[temp]->begin()+j);
                    break;
                }
            }
        }
        delete my_graph[name];
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
        QMap<QString, QPair<double, QString>> temp;
        QMap<QString, bool> visited;
        QQueue<QString> toVisit;
        auto it = my_graph.begin();
        while(it != my_graph.end()){
            QPair<double, QString> tempPair(-1, src);
            visited[it.key()] = false;
            if(it.key() == src){
                tempPair.first = 0;
            }
            temp[it.key()] = tempPair;
            it++;
        }
        toVisit.append(src);
        while(!toVisit.isEmpty()){
            if(visited[toVisit.front()]){
                toVisit.pop_front();
                continue;
            }
            for(int i = 0; i < my_graph[toVisit.front()]->size(); i++){
                toVisit.append(my_graph[toVisit.front()]->at(i).first);
                double distance = my_graph[toVisit.front()]->at(i).second
                    + temp[toVisit.front()].first;
                if(temp[my_graph[toVisit.front()]->at(i).first].first == -1||distance < temp[my_graph[toVisit.front()]->at(i).first].first){
                    temp[my_graph[toVisit.front()]->at(i).first].first = distance;
                    temp[my_graph[toVisit.front()]->at(i).first].second = toVisit.front();
                }
            }
            visited[toVisit.front()] = true;
            toVisit.pop_front();
        }
        if(!visited[des]) return nullptr;
        QVector<QString>* answer = new QVector<QString>;
        bool checker = true;
        QString current = des;
        while(checker){
            answer->push_back(current);
            current = temp[current].second;
            if(current == src){
                checker = false;
                answer->push_back(current);
            }
        }

        std::reverse(answer->begin(), answer->end());
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
