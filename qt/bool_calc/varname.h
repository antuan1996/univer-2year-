#ifndef VARNAME_H
#define VARNAME_H

#include <QDialog>

namespace Ui {
class varname;
}

class varname : public QDialog
{
    Q_OBJECT

public:
    explicit varname(QWidget *parent = 0);
    ~varname();

private:
    Ui::varname *ui;
};

#endif // VARNAME_H
