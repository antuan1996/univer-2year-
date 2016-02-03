#include "control.h"
#include "buckets.h"
Buckets::Buckets( Control const* set)
{
    part_w = set->puzzle_w / set->n_horiz;
    part_h = set->puzzle_h / set->n_vert;

    n_horiz = set->board_w / part_w ;
    n_vert = set->board_h / part_h ;

    data.resize( n_horiz * n_vert + 1);
}
void Buckets::set_pos(int id, QPoint pos_to, QPoint pos_from)
{
    if( pos_from.x() != -1)
    {
        int x = pos_from.x() / part_w;
        int y = pos_from.y() / part_h;
        if( x < 0 ) x = 0;
        if( y < 0 ) y = 0;
        if( x >= n_horiz ) x = n_horiz - 1;
        if( y >= n_vert ) y = n_vert - 1;

        for( auto it = data.at( y * n_horiz + x ).begin(); it != data.at( y * n_horiz + x ).end() ;++it )
            if( *it == id)
            {
                it = data.at( y * n_horiz + x ).erase( it );
                break;
            }

    }
    int x = pos_to.x() / part_w;
    int y = pos_to.y() / part_h;

    if( x < 0 ) x = 0;
    if( y < 0 ) y = 0;
    if( x >= n_horiz ) x = n_horiz - 1;
    if( y >= n_vert ) y = n_vert - 1;
    data.at( y * n_horiz + x ).push_back( id );
}
Buckets::~Buckets()
{
    for( auto cur : data)
    {
        cur.clear();
    }
}

std::list< int > Buckets::get_list( QRect rect)
{
    int sx = rect.left() / part_w;
    int sy = rect.top() / part_h;

    int fx = rect.right() / part_w;
    int fy = rect.bottom() / part_h;
    if( sx < 0 ) sx = 0;
    if( sy < 0 ) sy = 0;
    if( fx >= n_horiz ) fx = n_horiz - 1;
    if( fy >= n_vert ) fy = n_vert - 1;

    std::list < int > res;
    for( int y = sy; y <= fy; ++y)
        for( int x = sx; x <= fx; ++x)
        {
            res.insert( res.end(), data.at( y * n_horiz + x ).begin(),  data.at( y * n_horiz + x ).end());
        }
    return res;
}
