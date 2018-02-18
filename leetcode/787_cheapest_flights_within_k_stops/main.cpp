// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
typedef vector<vii> vvii;

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
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int
        dst, int K) {
      int m = flights.size();
      vi v(n, INF), u;
      v[src] = 0;
      u = v;
      forall(_,0,K+1){
        print_(v);
        for( const auto & e : flights ){
          debug("e=",e[0],e[1],e[2]);
          u[e[1]] = min( u[e[1]], v[e[0]] + e[2] );
        }
        swap(v,u);
      }
      
      return v[dst] == INF ? -1 : v[dst];
    }
};
int main( int argc, char * argv[] ){
  int n, m, k, src, trg;
  cin >> n >> m >> k >> src >> trg;

  vvi fli(m, vi(3));
  for( auto & row : fli ) input(row);
  Solution sol;
  debug("n,m,src,trg,k", n, m, src, trg, k );
  cout << sol.findCheapestPrice( n, fli, src, trg, k ) << '\n';

  return 0;
}
