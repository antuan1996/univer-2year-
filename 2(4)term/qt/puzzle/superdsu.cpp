#include "superdsu.h"
#include "control.h"
SuperDSU::SuperDSU(const Control *info)
{
    host.resize( info->n_horiz * info->n_vert );
    size.resize( info->n_horiz * info->n_vert, 1);
    parts.resize( info->n_horiz * info->n_vert);    
    ttime.resize( info->n_horiz * info->n_vert);
    cur_t = host.size();
    for(int i = 0; i < host.size(); ++i)
    {
        host[ i ] = i;
        ttime[ i ] = i;
        active.insert( i );
        parts.at( i ).insert( i );
    }
}

int SuperDSU::get_host(int id)
{
    if(host[ id ] == id) return id;
    return  host[ id ] = get_host( host[ id ] );
}
void SuperDSU::update(int id)
{
    ++cur_t;
    id = get_host( id );
    ttime[ id ] = cur_t;
}
int SuperDSU::get_time(int id)
{
    id = get_host( id );
    return ttime[ id ];
}

bool SuperDSU::merge(int a, int b)
{
    a = get_host( a );
    b = get_host( b );
    if( a == b ) return false;
    // merge b in a
    if( size[ a ] < size[ b ] )
        std::swap(a, b);
    size[ a ] += size[ b ];
    host[ b ] = a;
    ttime[ a ] = std::max( ttime[ a ], ttime[ b ] );
    active.erase( b );
    for(const int& id : parts.at( b ))
    {
        parts.at( a ).insert( id );
    }
    parts.at( b ).clear();
    if( parts.at( a ).size() >= host.size() )
        return true;
    return false;
}
const std::vector< int > SuperDSU::get_list(int id)
{
    std::vector< int > result;
    id = get_host( id );

    for(const int& a : parts.at( id ))
        result.push_back( a );
    return result;
}
const std::vector< int >SuperDSU::draw_order()
{
    std::vector < int > order;
    auto comp = [=]( int a, int b ){ return get_time( a ) < get_time( b );};
    for( const int& id : active)
        order.push_back( id );
    std::stable_sort( order.begin(), order.end(),  comp);
    return order;
}
