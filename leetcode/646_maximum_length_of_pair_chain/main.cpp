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
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  vi dp;
  vvi v;
  public:
    int solve(int i){
      if( i == n ) return 0;
      if( dp[i] != -1 ) return dp[i];
      const vi key = {v[i][1], v[i][1]};
      auto itr = upper_bound( v.begin()+i+1, v.end(), key, [](const vi& lhs, const vi & rhs){
          if( lhs[0] < rhs[0] ) return true; else return false;
          });
      int p;
      if( itr == v.end() ){
        p = 1;
      }else{
        p = 1 + solve( itr-v.begin() );
      }
      return dp[i] = max( p, solve(i+1) );
    }
    int findLongestChain(vector<vector<int>>& v) {
      if( v.size() == 0 ) return 0; 
      if( v.size() == 1 ) return 1; 
      sort(all(v));
      this->v = v;
      this->n = v.size();
      this->dp.resize(n, -1);
      return solve(0);

    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi v(n);
  for( auto & x : v ) x.resize(2);
  forall(i,0,n) cin >> v[i][0] >> v[i][1];
  Solution sol;
  cout << sol.findLongestChain(v) << '\n';

  return 0;
}
