#include "node_display.h"
#include <QTimer>
#include <QGraphicsScene>
node_display::node_display() {
    xv = 0;
    yv = 0;
    setRect(0,0,20,20);
    setPos(50,50);
    QTimer * timer =new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(2);
}
void node_display::move(){
    for(int i= 0; i < connections.size(); i++){
        if(abs((connections[i]->x()-x())*(connections[i]->x()-x()) + (connections[i]->y()-y())*(connections[i]->y()-y())) <2500){
            xv -= (connections[i]->x() - x())/abs((connections[i]->x()-x())*(connections[i]->x()-x()) + (connections[i]->y()-y())*(connections[i]->y()-y()));
            yv -= (connections[i]->y() - y())/abs((connections[i]->x()-x())*(connections[i]->x()-x()) + (connections[i]->y()-y())*(connections[i]->y()-y()));
        }
    }
    setPos(x()+xv, y()+yv);
    name->setPos(x(),y());
    xv = 0;
    yv = 0;
}
void node_display::connect(node_display * x){
    connections.push_back(x);
    x->connections.push_back(this);
}
void node_display::setText(QString nam){
    name = new QGraphicsTextItem;
    name->setPlainText(nam);
    name->setPos(x(),y());
    scene()->addItem(name);

}
