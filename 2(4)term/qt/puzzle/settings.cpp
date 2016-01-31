#include "settings.h"
/*
static int gcd(int a, int b)
{
    while( a )
    {
        b %= a;
        std::swap(a, b);
    }
    return b;
}
*/
Settings::Settings(std::string filename, int lvl, int p_type) : picture( filename.c_str() )
{
    puzzle_h = picture.height();
    puzzle_w = picture.width();

    // div to 3
    if(puzzle_w % 3)
        puzzle_w += 3 - puzzle_w % 3;
    if(puzzle_h % 3)
        puzzle_h += 3 - puzzle_h % 3;
    picture.scaled(puzzle_w, puzzle_h);

    // part len optimization
    //n_horiz = puzzle_w / gcd(puzzle_w , puzzle_h);
    //n_vert = puzzle_h / gcd(puzzle_w , puzzle_h);
    n_horiz = 4;
    n_vert = 4;

    n_horiz *= pow( 3, lvl) ;
    n_vert  *= pow( 3, lvl ) ;

}
