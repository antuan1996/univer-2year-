#ifndef PMODEL_H
#define PMODEL_H

#include <QObject>
#include <QPainter>
#include <vector>
#include <QPoint>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#include <enums.h>
#include "buckets.h"
#include "superdsu.h"
class PView;
class Settings;
class Buckets;
class SuperDSU;
struct PPart
{
    PPart() : cross_up( FILLED ), cross_right( FILLED ), cross_down( FILLED ), cross_left( FILLED ) { }
    int id;
    bool is_active;
    int prev_id;
    QPoint pos;
    ViewType cross_up, cross_right, cross_down, cross_left;
    int host;
};
class PModel : public QObject
{
    Q_OBJECT

public:
    PModel(Settings const* set, QObject* parent);
    ~PModel();
    void set_view(PView* v);
    const PView* get_view() { return my_view; }
    void show_view( QPainter* painter );
signals:
    void moved_part(int id, QPoint delt);
    void changed_border(int id, int view_type, int side);
    void flush();
public slots:
    void click_event(QPoint ev_pos);
    void move_event(QPoint pos);
    void release_event();

protected:
    PView* my_view;
    std::vector < PPart > data;
    Buckets my_hash;
    SuperDSU dsu;
    int n_horiz;
    int part_w;
    int part_h;
    int clicked_part;
    QPoint last_pos;
    int board_w, board_h;
    int dsu_get_host(int id);
    void dsu_merge(int a, int b);
    void check_borders( int id );
    void move_group(int host , QPoint diff);
};

#endif // PMODEL_H
