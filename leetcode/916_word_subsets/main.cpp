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
  vi encode( const string & s ){
    vi v(26,0);
    for(auto c : s ){ v[c-'a'] ++; }
    return v;
  }
  bool C( const vi & v, const vi & g ){
    forall(i,0,26){
      if( v[i] < g[i] ) return false;
    }
    return true;
  }
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
      vi max_cnt(26, 0);
      for(auto & s : B ){
        auto v = encode(s);
        transform(all(v), max_cnt.begin(), max_cnt.begin(), [](int a, int b){ return max(a,b);});
      }

      vector<string> ans;
      for(auto & s : A){
        auto v = encode(s);
        if( C(v, max_cnt) ) ans.pb(s);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
