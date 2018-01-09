#include <vector>
#include <unordered_set>
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

using namespace std;

typedef vector<uint32_t> vi;
typedef pair<uint32_t,uint32_t> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define input_( a )               for( auto & x : a ) cin >> x;
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
typedef pair<uint32_t,uint32_t> ii;
class Solution {
  private:
    unordered_set<uint32_t> chk;
  public:
    int integerReplacement(uint32_t n) {
      if( n <= 1 ) return 0;
      chk.insert(n);
      queue<ii> Q;
      Q.push( mp( 0, n ) );
      while( !Q.empty() ){
        auto p  = Q.front(); Q.pop();
        auto d = p.first, m = p.second;
        if( m%2 ){
          if( !chk.count(m-1) ){
            chk.insert(m-1);
            Q.push( mp(d+1, m-1 ) );
          }
          if( !chk.count(m+1) ){
            chk.insert(m+1);
            Q.push( mp( d+1, m+1) );
          }
        }else{
          if( m/2 == 1 ){
            clog << chk.size() << '\n';
            return d+1;
          }
          if( !in( m/2, chk ) ){
            chk.insert(m/2);
            Q.push(mp(d + 1, m / 2));
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n;
  cin >> n;
  Solution sol;
  cout << sol.integerReplacement(n) << '\n';

  return 0;
}
