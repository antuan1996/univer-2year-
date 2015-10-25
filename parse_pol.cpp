
// Problem :
// tegs :

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <iostream>

#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x.size()))
#define forn(i,n) for(int i = 0; i < (n); ++i)
#define update(buf,val) buf = max((buf),val) 

using namespace std;

typedef long long llong;
typedef unsigned long long ullong;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair <int,int> pi;
string prepare_str(const string& data)
{
    string res;
    res = "(";
    forn(i, sz(data))
    {
        if( i>0 && isalpha(data[i]) && data[i - 1] == '-')
        {
            res = res + "(" + data[i] + ")";
        }
        else
            res.pb(data[ i ]);
    }
    res += ")";
    
    return res;
}    
string parse_form(const string& data)
{
    string res;
    map <char, int > prior;
    
    prior['='] = 1;
    prior['>'] = 2;
    prior['+'] = 3;
    prior['+'] = 4;
    prior['&'] = 5;
    prior['-'] = 6;
    prior['('] = 7;
    stack <char> buf;
    forn(i, sz(data))
    {
        if( isalpha(data[ i ]))  res.pb(data[ i ]);
        else
        {
            //cout << data[i] << " " << isalpha(data[i]) << endl;
            if(data[i] != ')')
                {
                    while( (!buf.empty()) && (buf.top()!='(') && (prior[ buf.top() ] >= prior[ data[ i ] ]))
                    {
                        res.pb( buf.top() );
                        buf.pop();
                    }
                    buf.push( data[ i ] );
                }
            else
                {
                        while( !buf.empty() && buf.top() != '(' )
                        {
                            res.pb( buf.top() );
                            buf.pop();
                        }
                        if (buf.top() == '(') buf.pop(); 
                }
        }
    }
    return res;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //assert(!"Unsupported format");
    string str;
    cin >> str;
    str = prepare_str( str );
    cout << parse_form(str);
    return 0;
}
