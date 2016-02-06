
#include "pview.h"
#include "mainboard.h"
#include "control.h"
#define IS_CONTAIN( n, mask ) ( ((n & mask) ^ mask) == 0)
PView::PView(Control* set, QObject *parent) : QObject(parent), info( set )
{
    n_horiz = set->n_horiz * 3;
    part_w = set->puzzle_w / (set->n_horiz * 3);
    part_h = set->puzzle_h / ( n_horiz );

    set->mask_horiz = set->mask_horiz.scaled( part_w * 2, part_h );
    set->mask_vert = set->mask_vert.scaled( part_w, part_h * 2 );

    host_board = qobject_cast< MainBoard* >(parent); // Attention!!!
    data.resize(set->n_horiz * set->n_vert * 9, ViewPart( this ));
    connect(this, SIGNAL(changed_view()), host_board, SLOT(update()));

    for(int y = 0; y < 3 * set->n_vert; ++y)
        for(int x = 0; x < n_horiz; ++x)
        {
            ViewPart& cur = data.at( y * n_horiz + x );
            QRect window(x * part_w, y * part_h, part_w, part_h);
            cur.data = set->picture.copy( window );
            cur.pos = QPoint( x * part_w, y * part_h );
            cur.t = FILLED;
            cur.d = 0;
            cur.render( true, true, true );
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
void PView::global_render(bool upd_data, bool upd_shadow, bool upd_light)
{
    for( ViewPart& cur_part : data )
        cur_part.render( upd_data, upd_shadow, upd_light );
    emit changed_view();
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
    data.at( ids[ side_ids[ 0 ] ] ).render( true, true, true );
    data.at( ids[ side_ids[ 1 ] ] ).render( true, true, true);
    data.at( ids[ side_ids[ 2 ] ] ).render( true, true, true);

}
void PView::draw_part( int id, QPainter* painter)
{
    int* ids = map_logic_to_graphic( id );
    for( int i = 0; i < 9; ++i)
    {
        painter->drawImage( data[ ids[ i ] ].pos , data[ ids [ i ] ].result);
    }
}
void PView::draw_light(  int  id, QPainter* painter)
{
    int* ids = map_logic_to_graphic( id );
    for( int i = 0; i < 9; ++i)
    {
        painter->drawImage( data[ ids[ i ] ].pos + QPoint( -1, -1), data.at( ids[ i ] ).light);
    }
}
void PView::draw_shadow(  int  id, QPainter* painter)
{
    int* ids = map_logic_to_graphic( id );
    int step = info->shadow_deep;
    for( int i = 0; i < 9; ++i)
    {
        painter->drawImage( data[ ids[ i ] ].pos + QPoint( step, step), data.at( ids[ i ] ).shadow);
    }
}

void ViewPart::render(bool upd_data, bool upd_shadow, bool upd_light )
{
    // TODO Crosses
    if( upd_data )
    {
        if( t == BORDER || t == FILLED )
        {
            result = data;
        }
        if(t == DROP_INSIDE || t == DROP_OUTSIDE)
        {
            QImage content;

            if( d == UP || d == DOWN )
                content = host->info->mask_vert;
            if( d == RIGHT || d == LEFT )
                content = host->info->mask_horiz;
            if( t == DROP_INSIDE && d == RIGHT  || t == DROP_OUTSIDE && d == LEFT)
                content = host->info->mask_horiz.mirrored(true, false);
            if( t == DROP_INSIDE && d == UP  || t == DROP_OUTSIDE && d == DOWN)
                content = host->info->mask_vert.mirrored(false, true);
            QPainter painter( &content );
            if( t == DROP_INSIDE )
            {
                painter.setCompositionMode( QPainter::CompositionMode_SourceOut );
            }
             else// DROP_OUTSIDE
            {
                painter.setCompositionMode( QPainter::CompositionMode_SourceIn );
            }
            painter.drawImage(QPoint( 0, 0 ), data);
            result = content;

            //result.setMask( mask );
        }
   }
    if( upd_shadow )
    {
        shadow = QImage(result.width(), result.height() , QImage::Format_ARGB32 );
        shadow.fill( QColor(0, 0, 0, host->info->shadow_intensity) );
        if( t == DROP_INSIDE ||  t == DROP_OUTSIDE )
        {
            QPainter buffer( &shadow );
            buffer.setCompositionMode( QPainter::CompositionMode_DestinationIn);
            //buffer.setCompositionMode( QPainter::CompositionMode_DestinationOut);
            buffer.drawImage( 0, 0, result );
            buffer.end();
        }
    }
    if( upd_light )
    {

        QImage buf(data.width(), data.height(), QImage::Format_ARGB32 );
        buf.fill( host->info->border_color );
        QPainter p( &buf );
        p.setCompositionMode( QPainter::CompositionMode_DestinationIn);
        p.drawImage( 0, 0, result);
        p.end();
        light = QImage( data.width() + 2, data.height() + 2, QImage::Format_ARGB32 );
        light.fill( QColor(255, 255, 255, 0) );
        QPainter b;
        b.begin( &light );
        b.drawImage( QPoint( 0, 0), buf);
        b.drawImage( QPoint( 2, 0), buf);
        b.drawImage( QPoint( 2, 2), buf);
        b.drawImage( QPoint( 0, 2), buf);
        b.end();
    }
}

void PView::flush()
{
    emit changed_view();
}

