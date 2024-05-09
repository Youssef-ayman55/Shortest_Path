#include "node_display.h"
#include <QTimer>
#include <QGraphicsScene>
node_display::node_display(graph * graph_w): graph_w(graph_w) {
    xv = 0;
    yv = 0;
    radius = 50;
    phase= 0;
    setRect(0,0,50,50);
    setPos(50,50);
    timer =new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(1);
    parent = nullptr;
    na = "";
    stationary_count = 0;
    weight_with_parent = new QGraphicsTextItem;
    QPen border(QColor(116, 114, 100));
    border.setWidth(3);
    setPen(border);
    QBrush fill(QColor(224,204,190));
    setBrush(fill);

}
void node_display::move(){
    for(int i= 0; i < repels.size(); i++){
        if(abs((repels[i]->x()-x())*(repels[i]->x()-x()) + (repels[i]->y()-y())*(repels[i]->y()-y())) <10000){
            xv -= 20 * (repels[i]->x() - x())/abs((repels[i]->x()-x())*(repels[i]->x()-x()) + (repels[i]->y()-y())*(repels[i]->y()-y()));
            yv -= 20 * (repels[i]->y() - y())/abs((repels[i]->x()-x())*(repels[i]->x()-x()) + (repels[i]->y()-y())*(repels[i]->y()-y()));
        }
    }
    setPos(x()+xv, y()+yv);
    name->setPos(x() + 20,y() + 15);
    if(parent != nullptr && xv == 0 && yv == 0 && parent->xv == 0 && parent->yv == 0){
        stationary_count++;
    }
    if(parent != nullptr && stationary_count == 500){
        QPen pen(QColor(60, 54, 51));
        pen.setWidth(2);
        double xnorm = (x()-parent->x())/sqrt((x()-parent->x())*(x()-parent->x())+(y()-parent->y())*(y()-parent->y()));
        int x1 = x()+25 - 25*xnorm;
        int x2 = parent->x() + 25 +25*xnorm;
        double ynorm =(y()-parent->y())/sqrt((x()-parent->x())*(x()-parent->x())+(y()-parent->y())*(y()-parent->y()));
        int y1 =y()+25 - 25*ynorm;
        int y2 =  parent->y() + 25 +25*ynorm;
        scene()->addLine(x1,y1,x2,y2,pen);
        weight_with_parent->setPlainText(QString::number(graph_w->getweight(na, parent->na)));
        scene()->addItem(weight_with_parent);
        int weightx = (x() + parent->x())/2;
        int weighty = (y() + parent->y())/2;
        weight_with_parent->setPos(weightx,weighty);
        for(int i = 0; i < connections.size(); i++){
            QGraphicsTextItem * temp = new QGraphicsTextItem;
            temp->setPlainText(QString::number(graph_w->getweight(na, connections.at(i)->na)));
            scene()->addItem(temp);
            int weightx = (x() + connections.at(i)->x())/2;
            int weighty = (y() + connections.at(i)->y())/2;
            temp->setPos(weightx,weighty);
            weights.push_back(temp);
            QPen pen(QColor(60, 54, 51));
            pen.setWidth(2);
            double xnorm = (x()-connections.at(i)->x())/sqrt((x()-connections.at(i)->x())*(x()-connections.at(i)->x())+(y()-connections.at(i)->y())*(y()-connections.at(i)->y()));
            int x1 = x()+25 - 25*xnorm;
            int x2 = connections.at(i)->x() + 25 +25*xnorm;
            double ynorm =(y()-connections.at(i)->y())/sqrt((x()-connections.at(i)->x())*(x()-connections.at(i)->x())+(y()-connections.at(i)->y())*(y()-connections.at(i)->y()));
            int y1 =y()+25 - 25*ynorm;
            int y2 = connections.at(i)->y() + 25 +25*ynorm;
            scene()->addLine(x1,y1,x2,y2,pen);
        }
    }
    xv = 0;
    yv = 0;
}
void node_display::repel(node_display * x){
    repels.push_back(x);
    x->repels.push_back(this);
}
void node_display::setText(QString nam){
    na = nam;
    name = new QGraphicsTextItem;
    name->setPlainText(nam);
    QColor text_color(60, 54, 51);
    name->setPos(x() + 20,y() + 15);
    name->setDefaultTextColor(text_color);
    scene()->addItem(name);
}
node_display::~node_display(){
    delete weight_with_parent;
    delete name;
    for(int i = 0; i < weights.size(); i++){
        delete weights[i];
    }
    delete timer;
}
