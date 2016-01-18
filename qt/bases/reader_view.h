#ifndef READER_VIEW_H
#define READER_VIEW_H

#include <QDialog>

namespace Ui {
class reader_view;
}

class reader_view : public QDialog
{
    Q_OBJECT

public:
    explicit reader_view(QWidget *parent = 0);
    ~reader_view();

private:
    Ui::reader_view *ui;
};

#endif // READER_VIEW_H
