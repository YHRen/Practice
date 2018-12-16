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
class Solution {
  vi convert( char x ){
      vi ans(8,0);
      forall(i,0,8) if( x &(1<<i) ) ans[i] = 1; 
      return ans;
  }
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
      print_(cells);
      char x = 0;
      forall(i,0,8){ if( cells[i] ){ x |= (1<<i); } }
      char bar = (1<<8) -1;
      bar &= (1<<8) - 2;
      bar &= (1<<7) - 1;

      N -- ;
      x = ~( (x>>1) ^ (x<<1) );
      x &= bar;
      if( N == 0 ) return convert(x);

      debug( bitset<8>(x) );
      debug( bitset<8>(bar) );

      vector<char> v;
      v.pb(x);
      map<char,int> dict;
      dict[x] = 0;

      int idx = 1;
      int start_idx = 0;
      int found_idx = 0;
      while(N-->0){
        x = ~( (x>>1) ^ (x<<1) );
        x &= bar;
        debug(bitset<8>(x));
        if( dict.find(x) == dict.end() ){
          dict[x] = idx++;
          v.pb(x);
        }else{
          start_idx = dict[x];
          found_idx = idx;
          break;
        }
      }

      debug("N",N);
      if( N == -1 ){
        return convert(x);
      }else{
        int period = found_idx - start_idx;
        N %= period;
        return convert( v[start_idx+N] );
      }

        
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(8); input(v);
  Solution sol;
  auto ans = sol.prisonAfterNDays(v, n);
  print_(ans);
  return 0;
}
