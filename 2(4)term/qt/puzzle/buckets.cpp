#include "settings.h"
#include "buckets.h"
Buckets::Buckets( Settings const* set) : n_horiz( set->n_horiz ), n_vert( set->n_vert )
{
    part_w = set->board_w / set->n_horiz;
    part_h = set->board_h / set->n_vert;

    data.resize( set->n_horiz * set->n_vert + 1);
}
void Buckets::set_pos(int id, QPoint pos_to, QPoint pos_from)
{
    if( pos_from.x() != -1)
    {
        int x = pos_from.x() / part_w;
        int y = pos_from.y() / part_h;
        if( x >= 0 && x < n_horiz &&  y >= 0 && y < n_vert )
        for( auto it = data.at( y * n_horiz + x ).begin(); it != data.at( y * n_horiz + x ).end() ;++it )
            if( *it == id)
            {
                it = data.at( y * n_horiz + x ).erase( it );
                break;
            }

    }
    int x = pos_to.x() / part_w;
    int y = pos_to.y() / part_h;
    if( x >= 0 && x < n_horiz &&  y >= 0 && y < n_vert )
        data.at( y * n_horiz + x ).push_back( id );
}
Buckets::~Buckets()
{
    for( auto cur : data)
    {
        cur.clear();
    }
}

std::list< int > Buckets::get_list( QPoint pos)
{
    int x = pos.x() / part_w;
    int y = pos.y() / part_h;
    return data.at( y * n_horiz + x );
}
