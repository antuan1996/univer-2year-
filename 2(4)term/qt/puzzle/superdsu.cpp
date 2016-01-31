#include "superdsu.h"
#include "settings.h"
SuperDSU::SuperDSU(Settings const* info)
{
    host.resize( info->n_horiz * info->n_vert );
    size.resize( info->n_horiz * info->n_vert, 1);
    parts.resize( info->n_horiz * info->n_vert);

    for(int i = 0; i < host.size(); ++i)
    {
        host[ i ] = i;
        active.insert( i );
        parts.at( i ).push_back( i );
    }
}
int SuperDSU::get_host(int id)
{
    if(host[ id ] == id) return id;
    return  host[ id ] = get_host( host[ id ] );
}

void SuperDSU::merge(int a, int b)
{
    a = get_host( a );
    b = get_host( b );
    if( a == b ) return;
    // merge b in a
    if( size[ a ] < size[ b ] )
        std::swap(a, b);
    size[ a ] += size[ b ];
    host[ b ] = a;
    active.erase( b );
    parts.at( a ).splice(parts.at( a ).begin(),  parts.at( b ));
}
const std::list< int > SuperDSU::get_list(int id)
{
    return parts.at( id );
}
const std::vector< int >SuperDSU::draw_order()
{
    std::vector < int > order;
    auto comp = [=]( int a, int b ){ return size[ a ] > size[ b ];};
    for( const int& id : active)
        order.push_back( id );
    std::stable_sort( order.begin(), order.end(),  comp);
    std::vector < int > part;
    for( int& id : order)
        for( int& k : parts[ id ])
        {
            part.push_back( k );
        }
    return part;
}
