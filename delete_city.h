#ifndef DELETE_CITY_H
#define DELETE_CITY_H

#include <QWidget>

namespace Ui {
class delete_city;
}

class delete_city : public QWidget
{
    Q_OBJECT

public:
    explicit delete_city(QWidget *parent = nullptr);
    ~delete_city();
signals:
    void back();
private slots:
    void on_back_to_main_clicked();

private:
    Ui::delete_city *ui;
};

#endif // DELETE_CITY_H
