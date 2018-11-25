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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int knightDialer(int N) {
      if( N == 1 ) return 10;
    //  if( N == 2 ) return 20;
      vvi g(10);
      g[0].pb(4);
      g[0].pb(6);
      g[1].pb(6);
      g[1].pb(8);
      g[2].pb(7);
      g[2].pb(9);
      g[3].pb(4);
      g[3].pb(8);
      g[7].pb(2);
      g[7].pb(6);
      g[8].pb(1);
      g[8].pb(3);
      g[9].pb(2);
      g[9].pb(4);
      g[4].pb(3);
      g[4].pb(9);
      g[4].pb(0);
      g[6].pb(1);
      g[6].pb(7);
      g[6].pb(0);
      vector<long long> v(10, 0);
      forall(i,0,10){
        if(i!=5){
          if( i==4 || i ==6 ) v[i]=1;
          else v[i] = 1;
        }
      }
      print_(v);
      for( int t = 1; t < N; ++t ){
        vector<long long> vx(10,0);
        forall(i,0,10){
          for( auto u : g[i] ){
            debug("i",i,"u",u,"vx=",vx[u],v[i]);
            vx[u] += v[i];
          }
        }
        print_(vx);
        swap(vx, v);
        for( auto & x : v ){ x %= INF; }
        print_(v);
      }

      long long ans = 0;
      for( auto x : v ) ans += x;
      ans %= INF;
      return ans;
    }
};
int main( int argc, char * argv[] ){
  Solution sol;
  cout << sol.knightDialer(4) << '\n';

  return 0;
}
