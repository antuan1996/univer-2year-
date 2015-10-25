#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QIntValidator>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int h, int w, QWidget *parent = 0);
    ~Dialog();
signals:
    void send_coord(int w, int h);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
