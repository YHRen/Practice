// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
/******* Actual Code Starts Here *********/
class Solution {
  int to_int( char c ){ return c - 'A'; }
  int to_int( char c, char d ){ return ( (c-'A')<<3 ) | (d-'A');}
  vector< vector<char> > g;

  bool solve( const string & str, string & nxt, int idx ){
    if( str.size() == 1 ) return true; // reach peak
    if( idx == str.size() - 1 ){
      string tmp = "";
      return solve( nxt, tmp, 0 );
    }
    int base = to_int(str[idx], str[idx+1]);
    if( g[base].empty() ) return false;
    else{
      for( char c : g[base] ){
        nxt.pb(c);
        if( solve( str, nxt, idx+1 ) ) return true;
        else nxt.pop_back();
      }
    }
    return false;
  }
  
  public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
      if( allowed.empty() ) return false;
      sort(all(allowed));
      allowed.erase( unique(all(allowed)), allowed.end() );
      g.resize(64);
      print_(allowed);
      for( auto & s : allowed ){
        debug(s, to_int( s[0], s[1] ) );
        g[ to_int( s[0], s[1] ) ].pb( s[2] ); 
      }
      string nxt = "";
      return solve( bottom, nxt, 0 );
      return true;
    }
};
int main( int argc, char * argv[] ){
  string bottom; cin >> bottom;
  int n ; cin >> n;
  vector<string> v(n); 
  input(v);
  Solution sol;
  cout << sol.pyramidTransition(bottom, v) << '\n';

  return 0;
}
