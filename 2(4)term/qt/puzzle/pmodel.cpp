#include "pmodel.h"
#include "pview.h"
#include "control.h"
PModel::PModel(Control const* set, QObject* parent) : QObject( parent ),my_hash( set ),  dsu( set ),
                                                        board_w( set->board_w ), board_h( set->board_h )
{
    srand( time( 0 ) );
    my_view = nullptr;
    n_horiz = set->n_horiz;
    clicked_part = -1;
    data.resize( set->n_horiz * set->n_vert );
    part_w = set->puzzle_w / n_horiz;
    part_h = set->puzzle_h / set->n_vert;
    // init
    for(int y = 0; y < set->n_vert; ++y)
        for(int x = 0; x < set->n_horiz; ++x)
        {
            int i = y * set->n_horiz + x;
            data.at( i ).id = i;
            data.at( i ).host = i;
            data.at( i ).prev_id = -1;
            /*
            int nx = rand() % (board_w - part_w);
            int ny = rand() % (board_h - part_h);
            */
            int nx = part_w * x + part_w / 3 * x;
            int ny = part_h * y + part_h / 3 * y;

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
    if( my_view != nullptr )
        delete my_view;
    //data.clear();
}
void PModel::shuffle()
{
    const std::vector <int> nums = dsu.draw_order();
    for(const int& id : nums)
    {
        int nx = rand() % (board_w - part_w);
        int ny = rand() % (board_h - part_h);
        int first = dsu.get_list( id ).at( 0 );
        QPoint diff = QPoint( nx, ny ) - data.at( first ).pos;
        move_group( id, diff );
    }
    flush();
}

void PModel::create_view(Control *ctrl)
{
    if(my_view != nullptr)
    {
        disconnect( SIGNAL( moved_part( int, QPoint)));
        disconnect( SIGNAL( changed_border( int, int, int)));
        delete my_view;
    }
    my_view = new PView( ctrl, parent() );
    connect(this, SIGNAL(moved_part(int,QPoint)), my_view, SLOT(set_pos(int,QPoint)));
    connect(this, SIGNAL(changed_border(int, int, int)), my_view, SLOT(set_border(int, int, int)));
    connect(this, SIGNAL(flush()), my_view, SLOT(flush()));
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
void PModel::update_view( bool upd_data, bool upd_shadow, bool upd_light  )
{
    if( my_view != nullptr )
        my_view->global_render( upd_data, upd_shadow, upd_light  );
}

void PModel::click_event(QPoint ev_pos)
{
    last_pos = ev_pos;

    std::list < int > buf = my_hash.get_list( QRect( ev_pos - QPoint( part_w, part_h ), ev_pos + QPoint( part_w, part_h )) );
    buf.unique();
    std::cout << buf.size() << std::endl;

    for( int& i : buf )
    {
        PPart& it = data.at( i );
        if( it.is_active
            && (ev_pos.x() >= it.pos.x() && ev_pos.x() <= it.pos.x() + part_w)
            && (ev_pos.y() >= it.pos.y() && ev_pos.y() <= it.pos.y() + part_h))
        {
            if( clicked_part == -1 || dsu.get_time( clicked_part ) < dsu.get_time( i ))
                clicked_part = dsu.get_host( i );
        }
    }
    if( clicked_part != -1 )
        dsu.update( clicked_part );
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
    const std::vector< int > part_ids = dsu.get_list( clicked_part );
    for( const int& i : part_ids )
    {
         check_borders( i );
    }
    flush();
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
}
void PModel::move_group(int host, QPoint diff)
{
    const std::vector< int > part_ids = dsu.get_list( host );
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
        for( int const&  s :nums )
        {
            std::vector < int > parts = dsu.get_list( s );
            if( clicked_part == dsu.get_host( s )  )
                for( int& id : parts)
                    my_view->draw_shadow( id, painter );
            else
                for( int& id : parts)
                    my_view->draw_light( id, painter );

            for( int& id : parts)
                my_view->draw_part( id, painter ) ;
        }
    }
}
