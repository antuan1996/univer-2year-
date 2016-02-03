#ifndef PVIEW_H
#define PVIEW_H
#include <QObject>
#include <vector>
#include <QImage>
#include <QPixmap>
#include <QBitmap>
#include <QPainter>
#include <enums.h>
class MainBoard;
class Control;
class ViewPart;

class PView : public QObject
{
    Q_OBJECT
public:
    explicit PView(Control* set,QObject *parent = 0);
    void draw_part(int id, QPainter* painter);
    void draw_shadow( int  id, QPainter* painter );
    ~PView();
signals:
    void changed_view();
public slots:
    void set_pos(int id, QPoint npos);
    void set_border(int id, int view_type_int, int side_int);
    void flush();

protected :
    int part_w, part_h;
    int n_horiz;
    MainBoard const* host_board;
    std::vector < ViewPart > data;
    int* map_logic_to_graphic(int id) const;
};

class ViewPart
{
    friend class PView;
public:
    ViewPart(){}
    ViewPart( const Control* inf) : info(  inf ) {}
    QImage result;
    QImage shadow;
    QPoint pos;
private:
    int t;
    int d;
    const Control* info;
    QImage data;

    void render();
};

#endif // PVIEW_H
