#ifndef SETTER_H
#define SETTER_H

#include <QWidget>
#include <QColorDialog>
namespace Ui {
class setter;
}

class setter : public QWidget
{
    Q_OBJECT

public:
    QColor back_col, line_col;
    explicit setter(QWidget *parent = 0);
    ~setter();
    void setparams(int fid, bool b);
signals :
    void data_changed(QColor, QColor, bool);
    void sendfid(int);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_radioButton_toggled(bool checked);
    void getColor(QColor c);
    void getPoint(double x, double y);

private:
    QColor curcolor;
    int style;
    bool grid;
    Ui::setter *ui;
protected :
};

#endif // SETTER_H
