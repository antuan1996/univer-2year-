#ifndef SUPERDSU_H
#define SUPERDSU_H

#include <set>
#include <vector>
#include <list>
class Control;
class SuperDSU
{
    friend class PModel;
public:
    SuperDSU( Control const* info );
    void merge( int a, int b);
    int get_host( int id );
    void update( int id );
    const std::vector<int> get_list(int id);
    const std::vector< int > draw_order();
    int get_time( int id );
private:
    std::vector < int > host;
    std::vector < int > size;
    std::vector < int > ttime;

    std::vector < std::set< int > > parts;

    std::set < int > active;
    unsigned long long cur_t;
};

#endif // SUPERDSU_H
