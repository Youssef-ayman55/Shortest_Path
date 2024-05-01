#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add_city.h"
#include "delete_city.h"
#include "display_graph.h"
#include "find_path.h"
#include "graph.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_city_clicked();

    void reset();

    void on_delete_city_clicked();

    void on_display_graph_clicked();

    void on_find_path_clicked();


private:
    Ui::MainWindow *ui;
    add_city * add_city_w;
    delete_city * delete_city_w;
    display_graph * display_graph_w;
    find_path * find_path_w;
    graph * graph_w;
};
#endif // MAINWINDOW_H
