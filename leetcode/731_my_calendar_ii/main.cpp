#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class MyCalendarTwo {
  bool C( int xs, int xe, int ys, int ye ){
    return xs >= ye or ys >= xe;
  }
  map<ii,int> events;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int s, int e) {
      debug("(",s,",",e,")");
      auto itr = events.upper_bound(mp(s, -1));
      vii buffer;
      for(auto itr = events.upper_bound(mp(s,-1)); itr != events.end(); ++itr){
        if( ! C(s, e, itr->first.second, itr->first.first) ){
          buffer.pb(itr->first);
          if( itr->second == 2 ) return false;
        }
      }
      debug("intersect ", buffer.size());
      printPair_(buffer);
      for(auto p : buffer ){
          int tmp = events.at(p);
        events.erase(p);
        int x = p.second, y = p.first;
        if( x <= s and y >= e ){
          if( s != x ) events[mp(s,x)] = 1;
          events[mp(e,s)] = 2;
          if( e != y ) events[mp(y,e)] = 1;
          e = -1;
        }else if( x > s and y >= e ){
          events[mp(x,s)] = 1;
          events[mp(e,x)] = 2;
          if( e != y ) events[mp(y,e)] = 1;
          e = -1;
        }else if( x > s and y < e ){
          events[mp(x,s)] = 1;
          events[mp(y,x)] = 2;
          s = y;
        }else if( x <= s  and y < e ){
          if( s != x ) events[mp(s,x)] = 1;
          events[mp(y,s)] = 2;
          s = y;
        }else{
          cerr << " some error \n";
        }
      }
      if( e != -1 and s != e ){
        events[mp(e,s)] = 1;
      }
      
      // debug("printing events");
      // for(auto evt : events){
      //   debug(evt.first.second, evt.first.first, "cnt =",evt.second);
      // }

      return true;
        
    }
};

int main( int argc, char * argv[] ){
  MyCalendarTwo mc2;
  int n; cin >> n;
  vii v(n);
  for(auto & p : v){ cin >> p.first >> p.second; }
  for(auto p : v ){
    debug("p = ", p.first, p.second);
    cout << mc2.book(p.first, p.second) << ' ';
  }cout << '\n';



  return 0;
}
