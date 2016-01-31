#ifndef BUCKETS_H
#define BUCKETS_H
#include <QPoint>
#include <list>
#include <vector>

class Settings;

class Buckets
{
public:
    Buckets(Settings const* set);
    ~Buckets();
    void set_pos(int id, QPoint pos_to, QPoint pos_from = QPoint(-1, -1));
    std::list< int > get_list( QPoint pos);
private:
    int n_horiz,n_vert;
    int part_w, part_h;
    std::vector < std::list <int> > data;
};

#endif // BUCKETS_H
