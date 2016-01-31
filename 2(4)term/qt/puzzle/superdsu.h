#ifndef SUPERDSU_H
#define SUPERDSU_H

#include <set>
#include <vector>
#include <list>
class Settings;
class SuperDSU
{
    friend class PModel;
public:
    SuperDSU( Settings const* info );
    void merge( int a, int b);
    int get_host( int id );
    const std::list< int > get_list(int id);
    const std::vector<int> draw_order();
private:
    std::vector < int > host;
    std::vector < int > size;
    std::vector < std::list< int > > parts;
    std::set < int > active;
};

#endif // SUPERDSU_H
