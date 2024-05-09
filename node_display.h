#ifndef NODE_DISPLAY_H
#define NODE_DISPLAY_H
#include<QVector>
#include<QGraphicsEllipseItem>
#include<QGraphicsTextItem>
#include <graph.h>
class node_display: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    node_display(graph * a);
    ~node_display();
    double xv;
    double yv;
    int radius;
    double phase;
    QVector<node_display *>repels;
    void repel(node_display * x);
    QGraphicsTextItem * name;
    void setText(QString name);
    node_display * parent;
    QVector<node_display *> connections;
    QVector<QGraphicsTextItem *> weights;
    QString na;
    QTimer * timer;
    QGraphicsTextItem * weight_with_parent;
    graph * graph_w;
    int stationary_count;
public slots:
    void move();
};

#endif // NODE_DISPLAY_H
