#ifndef NODE_DISPLAY_H
#define NODE_DISPLAY_H
#include<QVector>
#include<QGraphicsEllipseItem>
#include<QGraphicsTextItem>
class node_display: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    node_display();
    double xv;
    double yv;
    QVector<node_display *>connections;
    void connect(node_display * x);
    QGraphicsTextItem * name;
    void setText(QString name);
public slots:
    void move();
};

#endif // NODE_DISPLAY_H
