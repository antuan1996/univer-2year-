#ifndef TYPES_VIEW_H
#define TYPES_VIEW_H

#include <QDialog>

namespace Ui {
class types_view;
}

class types_view : public QDialog
{
    Q_OBJECT

public:
    explicit types_view(QWidget *parent = 0);
    ~types_view();

private:
    Ui::types_view *ui;
};

#endif // TYPES_VIEW_H
