#include "pview.h"
#include  "settings.h"
#include "mainboard.h"
#define IS_CONTAIN( n, mask ) ( ((n & mask) ^ mask) == 0)
PView::PView(Settings const* set, QObject *parent) : QObject(parent)
{
    n_horiz = set->n_horiz * 3;
    part_w = set->puzzle_w / (set->n_horiz * 3);
    part_h = set->puzzle_h / ( n_horiz );
    host_board = qobject_cast< MainBoard* >(parent); // Attention!!!
    data.resize(set->n_horiz * set->n_vert * 9);
    connect(this, SIGNAL(changed_view()), host_board, SLOT(update()));
    for(int y = 0; y < 3 * set->n_vert; ++y)
        for(int x = 0; x < n_horiz; ++x)
        {
            ViewPart& cur = data.at( y * n_horiz + x );
            QRect window(x * part_w, y * part_h, part_w + 2, part_h + 2);
            cur.data = set->picture.copy( window );
            cur.pos = QPoint( x * part_w, y * part_h );
            cur.t = FILLED;
            cur.render();
        }
    for(int y = 0; y < set->n_vert; ++y)
        for( int x = 0; x < set->n_horiz; ++x)
        {
            int id = y * set->n_horiz + x;
            int* ids = map_logic_to_graphic( id );
            data.at( ids[ 0 ] ).t = BORDER;
            data.at( ids[ 0 ] ).d = Side(UP | LEFT);

            data.at( ids[ 1 ] ).t = BORDER;
            data.at( ids[ 1 ] ).d = UP;

            data.at( ids[ 2 ] ).t = BORDER;
            data.at( ids[ 2 ] ).d = Side( UP | RIGHT );

            data.at( ids[ 3 ] ).t = BORDER;
            data.at( ids[ 3 ] ).d = LEFT;

            data.at( ids[ 5 ] ).t = BORDER;
            data.at( ids[ 5 ] ).d = RIGHT;

            data.at( ids[ 6 ] ).t = BORDER;
            data.at( ids[ 6 ] ).d = Side(DOWN | LEFT);

            data.at( ids[ 7 ] ).t = BORDER;
            data.at( ids[ 7 ] ).d = DOWN;

            data.at( ids[ 8 ] ).t = BORDER;
            data.at( ids[ 8 ] ).d = Side(DOWN | RIGHT);


            QPoint pos( x * part_w * 3, y * part_h * 3);
            if( x > 0 )
            {
                ViewPart& cur = data.at( ids[ 3 ] );
                cur.pos = QPoint( pos.x() - part_w , pos.y() + part_h );
                QRect window(cur.pos.x(), cur.pos.y(),  2 * part_w, part_h );
                cur.data = set->picture.copy( window );

            }
            if( x + 1 < set->n_horiz )
            {
                ViewPart& cur = data.at( ids[ 5 ] );
                cur.pos = QPoint( pos.x() + 2 * part_w , pos.y() + part_h );
                QRect window(cur.pos.x(), cur.pos.y(),  2 * part_w, part_h );
                cur.data = set->picture.copy( window );

            }
            if( y > 0 )
            {
                ViewPart& cur = data.at( ids[ 1 ] );
                cur.pos = QPoint( pos.x() + part_w , pos.y() - part_h );
                QRect window( cur.pos.x(), cur.pos.y(),  part_w, part_h * 2);
                cur.data = set->picture.copy( window );

            }
            if( y + 1 < set->n_vert )
            {
                ViewPart& cur = data.at( ids[ 7 ] );
                cur.pos = QPoint( pos.x() + part_w, pos.y() + 2 * part_h );
                QRect window(cur.pos.x(), cur.pos.y(), part_w, part_h * 2 );
                cur.data = set->picture.copy( window );
            }

        }
}
PView::~PView()
{
    data.clear();
}
int* PView::map_logic_to_graphic(int id) const
{
    static int ids[ 9 ];
    int y = id / (n_horiz / 3);
    int x = id % (n_horiz / 3) ;
    y *= 3;
    x *= 3;
    ids[ 0 ] = y * n_horiz + x;
    ids[ 1 ] = ids[ 0 ] + 1;
    ids[ 2 ] = ids[ 1 ] + 1;

    ids[ 3 ] = ids[ 0 ] + n_horiz;
    ids[ 4 ] = ids[ 3 ] + 1;
    ids[ 5 ] = ids[ 4 ] + 1;

    ids[ 6 ] = ids[ 3 ] + n_horiz;
    ids[ 7 ] = ids[ 6 ] + 1;
    ids[ 8 ] = ids[ 7 ] + 1;
    return  ids;
}
void PView::set_pos(int id, QPoint npos)
{
    int* ids = map_logic_to_graphic( id );
    QPoint diff =  npos - data.at( ids[ 0 ] ).pos;
    for(int i = 0; i < 9; ++i)
        data.at( ids[ i ] ).pos += diff;
}
void PView::set_border(int id, int view_type_int, int side_int)
{
    ViewType view_type = static_cast < ViewType > ( view_type_int );
    Side side = static_cast < Side > ( side_int );
    int* ids = map_logic_to_graphic( id );
    int side_ids[ 3 ];

    if( side == UP )
    {
        side_ids[ 0 ] = 0;
        side_ids[ 1 ] = 1;
        side_ids[ 2 ] = 2;
    }
    if( side == RIGHT )
    {
        side_ids[ 0 ] = 2;
        side_ids[ 1 ] = 5;
        side_ids[ 2 ] = 8;
    }
    if( side == DOWN )
    {
        side_ids[ 0 ] = 6;
        side_ids[ 1 ] = 7;
        side_ids[ 2 ] = 8;
    }
    if( side == LEFT )
    {
        side_ids[ 0 ] = 0;
        side_ids[ 1 ] = 3;
        side_ids[ 2 ] = 6;
    }

    if( view_type == FILLED )
    {
        data.at( ids[ side_ids[ 0 ] ] ).t = FILLED;
        data.at( ids[ side_ids[ 1 ] ] ).t = FILLED;
        data.at( ids[ side_ids[ 2 ] ] ).t = FILLED;

        data.at( ids[ side_ids[ 0 ] ] ).d &= ~(side);
        data.at( ids[ side_ids[ 1 ] ] ).d &= ~(side);
        data.at( ids[ side_ids[ 2 ] ] ).d &= ~(side);


    }
    if( view_type == DROP_INSIDE )
    {
        data.at( ids[ side_ids[ 0 ] ] ).t = BORDER;
        data.at( ids[ side_ids[ 1 ] ] ).t = DROP_INSIDE;
        data.at( ids[ side_ids[ 2 ] ] ).t = BORDER;
    }

    if( view_type == DROP_OUTSIDE )
    {
        data.at( ids[ side_ids[ 0 ] ] ).t = BORDER;
        data.at( ids[ side_ids[ 1 ] ] ).t = DROP_OUTSIDE;
        data.at( ids[ side_ids[ 2 ] ] ).t = BORDER;
    }

    // border - default;
    data.at( ids[ side_ids[ 0 ] ] ).render();
    data.at( ids[ side_ids[ 1 ] ] ).render();
    data.at( ids[ side_ids[ 2 ] ] ).render();

}
ViewPart const* PView::get_part( int id ) const
{
    static ViewPart cur_data[ 9 ];
    int* ids = map_logic_to_graphic( id );
    for(int i = 0; i < 9; ++i)
    {
        cur_data[ i ] = data.at( ids[ i ] );
    }
    return cur_data;
}

void ViewPart::render()
{
    // TODO Crosses
    result = data;
    if( t != DROP_INSIDE && t != DROP_OUTSIDE)
    {
        QPainter painter( &result );
        QPen pen;
        pen.setColor( Qt::white );
        painter.setPen( pen );
        if( IS_CONTAIN( d, UP ) )
            painter.drawLine( 0, 0, result.width() - 1 , 0);
        if( IS_CONTAIN( d, LEFT ) )
            painter.drawLine( 0, 0, 0, result.height() - 1);
        if( IS_CONTAIN( d, DOWN ) )
            painter.drawLine( 0, result.height() - 1, result.width() - 1, result.height() - 1);
        if( IS_CONTAIN( d, RIGHT ) )
            painter.drawLine( result.width() - 1, 0,  result.width() - 1, result.height() - 1);

    }
    QBitmap mask(data.width(), data.height());
    if(t == DROP_INSIDE)
        mask.fill( Qt::color0 );
    else
        mask.fill( Qt::color1 );
    result.setMask( mask );
}

void PView::flush()
{
    emit changed_view();
}

