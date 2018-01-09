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
  private:
    vi v;
    bool C(int x){
      auto itr = lower_bound( v.begin(), v.end(), x );
      print_(v);
      int p = v.end() - itr;
      debug(x,p);
      return p >= x;
    }

  public:
    int hIndex(vector<int>& u) {
      this->v = u;
      if( v.empty() ) return 0;
      sort(all(v));
      int n = v.size();
      int l = 0, r = n+1;
      while( l+1 < r ){
        int mid = (l+r)/2;
        debug("mid=",mid);
        if( C(mid) ){
          debug("yes");
          l = mid;
        }else{
          debug("no");
          r = mid;
        }
      }
      return l;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n);
  for( auto & x : v ) cin >> x;
  Solution sol;
  cout << sol.hIndex(v) << '\n';

  return 0;
}
