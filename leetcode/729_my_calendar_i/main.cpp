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

//auto ____ =[]()
//{
//    std::ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    return nullptr;
//}();
//
// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class MyCalendar {
  bool C( int xs, int xe, int ys, int ye ){
    return xs >= ye or ys >= xe;
  }
  vii events;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
      for(auto p : events){
        if( ! C(start, end, p.first, p.second )  ) return false;
      }
      events.pb(mp(start,end));
      return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main( int argc, char * argv[] ){
  MyCalendar cal;
  int x, y;
  while(true){
    cin >> x >> y;
    cout << cal.book(x,y) << '\n';
  }

  return 0;
}
