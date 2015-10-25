#ifndef SUBW_H
#define SUBW_H

#include <QWidget>
#include <QDialog>
#include <string>
#include <cstdio>
#include "str.h"
namespace Ui {
class subw;
}

class subw : public QDialog
{
    Q_OBJECT

public:
    explicit subw(QWidget *parent = 0);
    ~subw();

private:
    Ui::subw *ui;
public slots:
    void but_press();
signals:
    void send_pair(int_pair);
};

#endif // SUBW_H
