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
class StockSpanner {
  vii v;
  int idx;
  public:
    StockSpanner() {
      v.clear();
      v.pb(mp(-INF,0));
      idx=1;
    }

    int next(int price) {
      debug("price = ", price, "vsz", v.size() );
      printPair_(v);
      auto itr = upper_bound( all(v), mp(-price, -INF) );
      if( itr == v.end() ){
        debug("to the end");
        v.pb(mp(-price,idx));
        idx ++;
        return 1;
      }else if( itr == v.begin() ){
        debug("to the begin, largest so far, should never happen");
        int ans = idx - v.begin()->second;
        v.clear();
        v.pb(mp(-price,idx));
        idx ++;
        return ans;
      }else{
        debug("found", itr->first, itr->second );
        --itr;
        int ans = idx - itr->second;
        v.erase( itr+1, v.end() );
        v.pb(mp(-price, idx));
        idx ++;
        return ans;
      }
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  StockSpanner ss;
  for(auto x : v ){
    cout << ss.next(x) << '\n';
  }

  return 0;
}
