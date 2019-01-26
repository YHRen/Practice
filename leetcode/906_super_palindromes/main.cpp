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
typedef unsigned long long ull;

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
  unsigned long long l,r, sqrtR;
  int max_depth;
  int ans;
  bool C( ull x ){ 
    if(x >= l and x <= r){
      string a = to_string(x);
      int n = a.size();
      forall(i,0,n/2){
        if( a[i] != a[n-i-1] ) return false;
      }
      return true;
    }else return false;
  }
  void dfs( ull x, int depth ){
    if( x > sqrtR ) return;
    if( depth > max_depth/2 ){
      debug("depth, max_depth/2, ", depth, max_depth/2);
      auto y = x*10;
      if( x == 0){
        forall(i,1,10){
          dfs( y+i, depth-1 );
        }
      }
      else{
        forall(i,0,10){
          dfs( y+i, depth-1 );
        }
      }
    }else if(depth == (max_depth)/2){
      string str = to_string(x);
      string str2 = str;
      reverse(all(str2));
      if( max_depth%2 ){ // odd
        str+=str2.substr(1);
      }else{
        str+=str2;
      }
      debug("str",str);
      ull xl = stoull(str);
      xl *= xl;
      if( C(xl) ) ans += 1;
    }
  }

  public:
    int superpalindromesInRange(string L, string R) {
      ans = 0;
      l = stoull(L); r = stoull(R); sqrtR = 100000;
      forall(d,1, R.size()+1){
        debug("define max depth = ", d );
        max_depth = d;
        dfs(0, d);
      }
      return ans;


    }
};
int main( int argc, char * argv[] ){
  string l,r; cin >> l >> r;
  Solution sol;
  cout << sol.superpalindromesInRange(l,r) << '\n';

  return 0;
}
