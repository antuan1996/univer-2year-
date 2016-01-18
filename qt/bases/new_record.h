#ifndef NEW_RECORD_H
#define NEW_RECORD_H

#include <QDialog>

namespace Ui {
class new_record;
}

class new_record : public QDialog
{
    Q_OBJECT

public:
    explicit new_record(QWidget *parent = 0);
    ~new_record();

private:
    Ui::new_record *ui;
};

#endif // NEW_RECORD_H
