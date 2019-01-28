#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
typedef pair<int,ii> iii;
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
  vi speed;
  public:
    int racecar(int target) {
      forall(i,0,15){ speed.pb(1<<i); }
      set<ii> dict;
      dict.insert(mp(0,0));
      auto cmp = [target](const iii & lhs, const iii & rhs ){
        if( lhs.first >  rhs.first ) return true;
        else if( lhs.first == rhs.first ){ 
          return abs(lhs.second.first - target) > abs(rhs.second.first-target);
        }else{
          return false;
        }
      };
      //priority_queue<iii, vector<iii>, greater<iii>> Q;
      priority_queue<iii, vector<iii>, decltype(cmp)> Q(cmp);
      //queue< iii > Q;
      Q.push(mp(0, mp(0,0)));
      while(!Q.empty()){
        auto p = Q.top(); Q.pop();
        //auto p = Q.front(); Q.pop();
        int dist = p.first;
        int pos = p.second.first, spd = p.second.second;
        debug("pos, spd, dist", pos, spd, dist);
        {// A
          if( spd < 15 and pos < (1<<17) ){ 
            int x = pos + (1<<spd);
            int y = spd + 1;
            if( x == target ) return dist+1;
            if( not in(mp(x,y),dict) and x > 0 ){
              dict.insert(mp(x,y));
              Q.push(mp(dist+1, mp(x, y) ) );
            }
          }else if( spd > 15 and spd < 32 and pos > -(1<<17)){
            int x = pos - (1<<(spd-16));
            int y = spd + 1;
            if( x == target ) return dist+1;
            if( not in( mp(x,y), dict ) and x > 0 ){
              dict.insert(mp(x, y));
              Q.push(mp(dist+1, mp(x, y) ) );
            }
          }
        }
        { // R
          if( spd < 15 ){
            int s = 16;
            if( not in( mp(pos,s), dict ) ){
              dict.insert(mp(pos,s));
              Q.push(mp(dist+1, mp(pos,s)));
            }
          }else if( spd > 15 and spd < 32) {
            int s = 0;
            if( not in( mp(pos,s), dict ) ){
              dict.insert(mp(pos,s));
              Q.push(mp(dist+1, mp(pos,s)));
            }
          }
        }
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  cout << sol.racecar(n) << '\n';

  return 0;
}
