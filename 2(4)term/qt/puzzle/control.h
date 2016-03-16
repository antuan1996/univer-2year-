#ifndef CONTROL_H
#define CONTROL_H

#include <QWidget>
#include <QString>
#include <QFileDialog>
#include <QDialog>
#include <QCloseEvent>
#include <QColor>
namespace Ui {
class Control;
}

class Control : public QDialog
{
    Q_OBJECT

public:
    explicit Control(int bw, int bh, QWidget *parent = 0);
    ~Control();

private slots:
    void on_pushButton_2_clicked();

    void on_load_buttn_clicked();

    void on_lvl_slider_valueChanged(int value);

    void on_nextlvl_buttn_clicked();

    void on_add_buttn_clicked();

    void on_pushButton_clicked();

    void on_finish_buttn_clicked();

    void on_color_box_activated(int index);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_valueChanged(int value);

    void preview_change(const QString & path);

    void on_tabWidget_currentChanged(int index);

signals:
    void shuffle_puzzle();
    void closed();
    void data_changed( Control* p );
    void view_changed( bool update_data, bool update_shadow, bool update_light );
public:
    QImage data;
    QImage picture;
    //QImage scale;
    QImage mask_horiz;
    QImage mask_vert;
    QColor border_color;
    QString img_name;
    int shadow_deep;
    int shadow_intensity;

    int n_horiz;
    int n_vert;
    int puzzle_w, puzzle_h;
    int board_w, board_h;
    int part_type;
    int level;
    Ui::Control *ui;

    void scale_puzzle();
    void load_image();
protected :
     void closeEvent(QCloseEvent *event);
};

#endif // CONTROL_H
