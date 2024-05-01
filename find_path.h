#ifndef FIND_PATH_H
#define FIND_PATH_H

#include <QWidget>

namespace Ui {
class find_path;
}

class find_path : public QWidget
{
    Q_OBJECT

public:
    explicit find_path(QWidget *parent = nullptr);
    ~find_path();
signals:
    void back();
private slots:
    void on_back_to_main_clicked();

private:
    Ui::find_path *ui;
};

#endif // FIND_PATH_H
