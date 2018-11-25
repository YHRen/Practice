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
    int n,m;
    string S,T;
    vi ans;
    int dec;
    bool match( int i ){
      dec = 0;
      forall(j,0,m){
        if( T[i+j] == '#' ) continue;
        if( T[i+j] != S[j] ) return false;
        dec += 1;
      }
      if (dec == 0) return false;
      return true;
    }

public:
    vector<int> movesToStamp(string stamp, string target) {
      n = target.size();
      m = stamp.size();
      T = target;
      S = stamp;
      int cnt = n;
      int lim = n;
      while( cnt > 0 and lim-->0 ){
        forall(i,0,n-m+1){
          debug(i, T);
          if( match(i) ){
            cnt -= dec;
            ans.pb(i);
            fill( T.begin()+i, T.begin()+i+m, '#');
          }
        }
      }
      debug(lim, T);
      if( lim == -1 ) return {};
      reverse(all(ans));
      return ans;
        
    }
};

int main( int argc, char * argv[] ){
  string stamp, target;
  cin >> stamp >> target;
  Solution sol;
  auto ans = sol.movesToStamp(stamp, target);
  print_(ans);


  return 0;
}
