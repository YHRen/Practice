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
class RangeModule {

public:
  set<ii> S;
    RangeModule() {
        
    }
    
    void addRange(int l, int r) {
      auto itr = S.upper_bound(mp(l, INF));
      if( itr != S.begin()){
        if((--itr)->second < l) ++itr;
        else{
          l = itr->first;
          r = max(itr->second, r);
          itr = S.erase(itr);
        }
      }
      while( itr != S.end() && itr->first <= r ){
        r = max( itr->second, r);
        itr = S.erase(itr);
      }
      S.insert(mp(l,r));
    }
    
    bool queryRange(int left, int right) {
      auto itr = S.upper_bound(mp(left,INF));
      return (itr!=S.begin() && (--itr)->second >= right);
    }
    
    void removeRange(int left, int right) {
      auto itr = S.upper_bound(mp(left,INF));
      vii to_add;
      if( itr != S.begin() ){
        if( (--itr)->second <= left ) ++itr;
        else{
          to_add.pb(mp(itr->first, left));
          if( itr->second > right ){
            to_add.pb(mp(right,itr->second));
            itr = S.erase(itr);
          }
        }
      }

      while( itr != S.end() && itr->first < right ){
        if( itr->second > right ) to_add.pb(mp(right,itr->second));
        itr = S.erase(itr);
      }
      for( auto p : to_add ) S.insert(p);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
int main( int argc, char * argv[] ){
  int T; cin >> T;
  RangeModule sol;
  while(T-->0){
    char c;
    int x,y;
    cin >> c >> x >> y;
    if( c == '+' ){
      debug("+",x,y);
      sol.addRange(x,y);
      printPair_(sol.S);
    }else if( c== '-'){
      debug("-",x,y);
      sol.removeRange(x,y);
      printPair_(sol.S);
    }else if( c=='?'){
      debug("?",x,y);
      cout << sol.queryRange(x,y) << '\n';
      debug(sol.queryRange(x,y));
    }
  }


  return 0;
}
