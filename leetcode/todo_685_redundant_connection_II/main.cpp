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
  private:
    vi idx;
    int find_root(int x ){
      vi cache;
      while( idx[x] != x ){
        cache.pb(x);
        x = idx[x];
      }
      for( auto y : cache ) idx[y] = x;
      return x;
    }
    void unify(int x, int y){
      int ry = find_root(y);
      idx[ry] = find_root(x);
    }
  public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      idx.resize(n+1);
      forall(i,0,n+1) idx[i] = i;
      for(const auto & e : edges ){
        int x = e[0], y = e[1];
        int rootx = find_root(x);
        int rooty = find_root(y);
        if( rootx == rooty ) return e;
        else unify(x,y) ;
      }
      return {0,0};
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
