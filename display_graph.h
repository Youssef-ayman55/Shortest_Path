#ifndef DISPLAY_GRAPH_H
#define DISPLAY_GRAPH_H
#include <QWidget>
#include "graph.h"
#include <QGridLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include "node_display.h"
namespace Ui {
class display_graph;
}

class display_graph : public QWidget
{
    Q_OBJECT

public:
    explicit display_graph(QWidget *parent = nullptr);
    display_graph(graph * graph_w);
    ~display_graph();
signals:
    void back();
private slots:
    void on_back_to_main_clicked();
private:
    Ui::display_graph *ui;
    graph * graph_w;
    QGridLayout* layout;
    QGraphicsScene * scene;
    QGraphicsView * view;
    QVector<node_display*> * vector;

};

#endif // DISPLAY_GRAPH_H
