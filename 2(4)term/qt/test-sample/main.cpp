#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <assert.h>
#include <malloc.h>
#include <emmintrin.h>
using namespace std;
void colorspace_convert (int wid, int hei, char* source, char* destination )
{
    for(int y = 0; y < hei; ++y)
        for(int x = 0; x + 4 <= wid; x += 4)
        {
            char r, g, b;
            r = source[ y * wid + x + 0];
            g = source[ y * wid + x + 1];
            b = source[ y * wid + x + 2];
            destination[ y * wid + x + 0 ] = b;
            destination[ y * wid + x + 1 ] = g;
            destination[ y * wid + x + 2 ] = r;
        }
}
void pack(__m128i& r, __m128i& g, __m128i& b)
{
    g = _mm_slli_epi32( g, 8 );
    r = _mm_slli_epi32( r, 16 );

    r = _mm_or_si128( r , g );
    r = _mm_or_si128( r , b );

}

void colorspace_convert_vector (int wid, int hei, char* source, char* destination )
{
    for(int y = 0; y < hei; ++y)
        for(int x = 0; x + 4 <= wid; x += 16)
        {
            //x b g r
            __m128i r, g, b;
            __m128i data;
            data = _mm_loadu_si128( (__m128i*)(source + y * wid + x) );
            b = _mm_set1_epi32( 0xFF );
            r = _mm_and_si128( data, b );
            data = _mm_srai_epi32( data, 8 );
            g = _mm_and_si128( data, b );
            data = _mm_srai_epi32( data, 8 );
            b = _mm_and_si128( data, b );

            // x r g b
            pack( r, g, b );
            _mm_storeu_si128( (__m128i*)(destination + y * wid + x), r);

        }
}

int main()
{
    srand( time( NULL ) );
    int tnum = 5;
    size_t res = 0;
    std::cout << "Scalar";
    for( int k = 0; k < tnum; ++k )
    {

        int fnum, wid, virt_wid, hei;
        fnum = 100;
        hei = 480;
        virt_wid = 640;
        wid = virt_wid * 4;
        char* frame = (char*) malloc( wid * hei * fnum );
        for(int fr = 0; fr < fnum; ++fr)
            for( int y = 0; y < hei; ++y )
                for( int x = 0; x < wid; ++x ) {
                    frame[ fr * wid * hei  + y * wid + x] = rand() % 256;
                }

        char* dst = (char*) malloc( wid * hei * fnum );
        clock_t t1 = clock();
        colorspace_convert (virt_wid, hei * fnum,frame, dst);
        clock_t t2 = clock();
        std::cout << "Time diff = " <<  t2 - t1 << std::endl;
        res += t2 - t1;
        free( frame );
        free( dst );
    }
    std::cout << "average time is :" << ( res + ( tnum / 2 ) ) / tnum;
    res = 0;
    std::cout << "Vector";
    for( int k = 0; k < tnum; ++k )
    {

        int fnum, wid, virt_wid, hei;
        fnum = 100;
        hei = 480;
        virt_wid = 640;
        wid = virt_wid * 4;
        char* frame = (char*) malloc( wid * hei * fnum );
        for(int fr = 0; fr < fnum; ++fr)
            for( int y = 0; y < hei; ++y )
                for( int x = 0; x < wid; ++x ) {
                    frame[ fr * wid * hei  + y * wid + x] = rand() % 256;
                }

        char* dst = (char*) malloc( wid * hei * fnum );
        clock_t t1 = clock();
        colorspace_convert_vector(virt_wid, hei * fnum,frame, dst);
        clock_t t2 = clock();
        std::cout << "Time diff = " <<  t2 - t1 << std::endl;
        res += t2 - t1;
        free( frame );
        free( dst );
    }
    std::cout << "average time is :" << ( res + ( tnum / 2 ) ) / tnum;

    return 0;
}
