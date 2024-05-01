#ifndef ADD_CITY_H
#define ADD_CITY_H

#include <QWidget>
#include "graph.h"
namespace Ui {
class add_city;
}

class add_city : public QWidget
{
    Q_OBJECT

public:
    explicit add_city(QWidget *parent = nullptr);
    add_city(graph * graph_w);
    ~add_city();
signals:
    void back();
private slots:
    void on_back_to_main_clicked();

    void on_add_clicked();

    void on_connect_clicked();

private:
    Ui::add_city *ui;
    graph* graph_w;
};

#endif // ADD_CITY_H
