#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bitset>
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
class RLEIterator {
  vi v;
  int idx, N, tmp;
  public:
    RLEIterator(vector<int> A) {
      v = A;
      N = A.size();
      idx = 0;
      tmp = 0;
    }

    int next(int n) {
      debug("n=",n,"idx,tmp",idx,tmp);
      if( idx == -1 ) return -1;
      while( idx < N and n > 0 ){
        debug("idx = ",idx,"tmp=",tmp,"n=",n);
        if( v[idx] - tmp >= n ){
          tmp += n;
          return v[idx+1];
        }else{
          n -= (v[idx]-tmp);
          tmp = 0;
          idx += 2;
        }
      }
      idx = -1;
      return -1;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  int m; cin >> m;
  vi v(n); input(v);
  vi u(m); input(u);
  RLEIterator s(v);
  for(auto x : u ) cout << s.next(x) << '\n';


  return 0;
}
