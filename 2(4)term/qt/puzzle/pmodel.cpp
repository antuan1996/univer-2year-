#include "pmodel.h"
#include "settings.h"
#include "pview.h"

PModel::PModel(Settings const* set, QObject* parent) : QObject( parent ),my_hash( set ),  dsu( set ),  board_w( set->board_w ), board_h( set->board_h )
{
    srand( time( 0 ) );
    my_view = nullptr;
    n_horiz = set->n_horiz;
    clicked_part = -1;
    data.resize( set->n_horiz * set->n_vert );
    part_w = set->puzzle_w / n_horiz;
    part_h = set->puzzle_h / set->n_vert;
    // init
    for(size_t i = 0; i < data.size(); ++i)
    {
        data.at( i ).id = i;
        data.at( i ).host = i;
        data.at( i ).prev_id = -1;
        int nx = rand() % (board_w - part_w);
        int ny = rand() % (board_h - part_h);
        data.at( i ).pos = QPoint( nx, ny);
        my_hash.set_pos( i, data.at( i ).pos );
        data[ i ].is_active = true;
        data.at( i ).cross_up =  (ViewType) BORDER;
        data.at( i ).cross_right = (ViewType) BORDER;
        data.at( i ).cross_down = (ViewType) BORDER;
        data.at( i ).cross_left =  (ViewType) BORDER;

    }
    // crosses
    for(int y = 0; y + 1 < set->n_vert; ++y)
        for(int x = 0; x + 1 < set->n_horiz; ++x)
        {
            int i = y * set->n_horiz + x;
            int right = y * set->n_horiz + x + 1;
            int down = (y + 1) * set->n_horiz + x;
            int cross_r = rand() % 2;
            int cross_d = rand() % 2;

            data.at( i ).cross_right = (ViewType)cross_r;
            data.at( i ).cross_down = (ViewType)cross_d;
            data.at( right ).cross_left =  (ViewType)(1 - cross_r);
            data.at( down ).cross_up =  (ViewType)(1 - cross_d);
        }
    for(int x = 0; x + 1 < set->n_horiz; ++x)
        {
            const int y = set->n_vert - 1;
            int i = y * set->n_horiz + x;
            int right = y * set->n_horiz + x + 1;
            int cross_r = rand() % 2;
            data.at( i ).cross_right = (ViewType)cross_r;
            data.at( right ).cross_left =  (ViewType)(1 - cross_r);
        }
    for(int y = 0; y + 1 < set->n_vert; ++y)
        {
            const int x = set->n_horiz - 1;
            int i = y * set->n_horiz + x;
            int down = (y + 1) * set->n_horiz + x;
            int cross_d = rand() % 2;
            data.at( i ).cross_down = (ViewType)cross_d;
            data.at( down ).cross_up =  (ViewType)(1 - cross_d);
        }

}
PModel::~PModel()
{
    data.clear();
}
void PModel::set_view(PView *v)
{
    if(my_view != nullptr)
    {
        disconnect( SIGNAL( moved_part( int, QPoint)));
        disconnect( SIGNAL( changed_border( int, ViewType, Side)));
    }
    my_view = v;
    connect(this, SIGNAL(moved_part(int,QPoint)), v, SLOT(set_pos(int,QPoint)));
    connect(this, SIGNAL(changed_border(int, int, int)), v, SLOT(set_border(int, int, int)));
    connect(this, SIGNAL(flush()), v, SLOT(flush()));
    for( int id = 0; id < data.size(); ++id )
    {
        emit moved_part(id, data.at( id ).pos);
        emit changed_border( id, data.at( id ).cross_up, UP );
        emit changed_border( id, data.at( id ).cross_right, RIGHT);
        emit changed_border( id, data.at( id ).cross_down, DOWN);
        emit changed_border( id, data.at( id ).cross_left, LEFT);

    }
    emit flush();
}
void PModel::click_event(QPoint ev_pos)
{
    last_pos = ev_pos;

    std::list < int > buf = my_hash.get_list( ev_pos );
    buf.splice( buf.end(), my_hash.get_list( QPoint( ev_pos.x() - part_w, ev_pos.y() ) ) );
    buf.splice( buf.end(), my_hash.get_list( QPoint( ev_pos.x(), ev_pos.y() - part_h ) ) );
    buf.splice( buf.end(), my_hash.get_list( QPoint( ev_pos.x() - part_w, ev_pos.y() - part_h ) ) );
    buf.unique();


    for( int& i : buf )
    {
        PPart& it = data.at( i );
        if( it.is_active
            && (ev_pos.x() >= it.pos.x() && ev_pos.x() <= it.pos.x() + part_w)
            && (ev_pos.y() >= it.pos.y() && ev_pos.y() <= it.pos.y() + part_h))
        {
            if(clicked_part == -1 || dsu.size[ dsu.get_host( i ) ] < dsu.size[ clicked_part ]
                    || ( dsu.size[ dsu.get_host( i ) ] == dsu.size[ clicked_part ]  && dsu.get_host( i ) > dsu.get_host( clicked_part ) ) )
                clicked_part = dsu.get_host( i );
        }
    }
    flush();
}
void PModel::move_event(QPoint pos)
{
    if(clicked_part != -1)
    {
        QPoint diff = pos - last_pos;
        move_group( dsu.get_host( clicked_part ), diff );
        last_pos = pos;
        emit flush();
    }
}
void PModel::release_event()
{
    if(clicked_part == -1) return;
    const std::list< int > part_ids = dsu.get_list( clicked_part );
    for( const int& i : part_ids )
    {
         check_borders( i );
    }
    clicked_part = -1;
}
void PModel::check_borders( int id )
{
    int x = id % n_horiz;
    int y = id / n_horiz;
    int eps = 10;
    QPoint npos;
    int host = dsu.get_host( id );
    if( x > 0 )
    {
        int left = id - 1;
        QPoint delt = data.at( id ).pos - data.at( left ).pos;
        delt.rx() -= part_w;
        if( hypot( delt.x(), delt.y() )  <= eps )
        {
            npos = QPoint( data.at( left ).pos.x() + part_w, data.at( left ).pos.y());
            move_group( host, npos - data.at( id ).pos );
            dsu.merge(left, id);
            host = dsu.get_host( id );
            emit changed_border(id, FILLED, LEFT);
            emit changed_border(left, FILLED, RIGHT);
        }
    }

    if( x + 1 < n_horiz )
    {
        int right = id + 1;
        QPoint delt = data.at( right ).pos - data.at( id ).pos;
        delt.rx() -= part_w;
        if( hypot( delt.x(), delt.y() )  <= eps)
        {
            npos = QPoint( data.at( right ).pos.x() - part_w, data.at( right ).pos.y());
            move_group( host, npos - data.at( id ).pos );
            dsu.merge(right, id);
            host = dsu.get_host( id );
            emit changed_border( id, FILLED, RIGHT);
            emit changed_border( right, FILLED, LEFT);
        }
    }
    if( y > 0 )
    {
        int up = id - n_horiz;
        QPoint delt = data.at( id ).pos - data.at( up ).pos;
        delt.ry() -= part_h;
        if( hypot( delt.x(), delt.y() )  <= eps )
        {
            npos = QPoint( data.at( up ).pos.x(), data.at( up ).pos.y() + part_h);
            move_group( host, npos - data.at( id ).pos );
            dsu.merge(up, id);
            host = dsu.get_host( id );
            emit changed_border( id, FILLED, UP);
            emit changed_border( up, FILLED, DOWN);
        }
    }
    if( y + 1 < data.size() / n_horiz )
    {
            int down = id + n_horiz;
        QPoint delt = data.at( down ).pos - data.at( id ).pos;
        delt.ry() -= part_h;
        if( hypot( delt.x(), delt.y() )  <= eps)
        {
            npos = QPoint( data.at( down ).pos.x(), data.at( down ).pos.y() - part_h);
            move_group( host, npos - data.at( id ).pos );
            dsu.merge(down, id);
            emit changed_border( id, FILLED, DOWN);
            emit changed_border( down, FILLED, UP);
        }
    }
    flush();
}
void PModel::move_group(int host, QPoint diff)
{
    const std::list< int > part_ids = dsu.get_list( host );
    for( const int& i : part_ids )
    {
        QPoint prev_pos = data.at( i ).pos;
        data.at( i ).pos += diff;
        my_hash.set_pos( i, data.at( i ).pos, prev_pos );
        emit moved_part( i, data.at( i ).pos );
    }
}
void PModel::show_view(QPainter *painter)
{
    if( my_view != nullptr )
    {
        const std::vector <int> nums = dsu.draw_order();
        for( int const&  id :nums )
        {
            ViewPart const* data = my_view->get_part( id );
            for( int i = 0; i < 9; ++i)
                painter->drawPixmap( data[ i ].pos, data[ i ].result);
        }
        if( clicked_part != -1)
            for(const int& id : dsu.get_list( clicked_part ) )
            {
                ViewPart const* data = my_view->get_part( id );
                for( int i = 0; i < 9; ++i)
                    painter->drawPixmap( data[ i ].pos, data[ i ].result);

            }
    }
}
