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
class Solution_1 {
  int n;
  int t;
  public:
    bool C( const vi & v, int msk ){
      int tot = 0;
      forall(i,0,n){
        ( msk & (1<<i) ) ? tot +=v[i] : tot -= v[i];
      }
      return tot == t;
    }

    int findTargetSumWays(vector<int>& v, int t) {
      this->n = v.size();
      this->t = t;
      int ans = 0;
      forall(i,0,1<<n) if( C(v,i) ) ++ans;
      return ans;
    }
};

class Solution_2 {
  int n,t;
  vii lv,rv;
  public:
    int C( const vi & v, int msk ){
      int tot = 0;
      forall(i,0,n){
        ( msk & (1<<i) ) ? tot +=v[i] : tot -= v[i];
      }
      return tot;
    }

    int C( const vi & v, int msk, int lim, int pad = 0 ){
      int tot = 0;
      forall(i,0,lim){
        ( msk & (1<<i) ) ? tot +=v[i+pad] : tot -= v[i+pad];
      }
      return tot;
    }

    vii get_part( const vi & v, int p, int q ){
      unordered_map<int,int> rec;
      forall(i,0,1<<(q-p)){
        rec[C(v,i,q-p,p)] += 1;
      }
      vii ans;
      for( const auto & x : rec ){
        ans.pb(mp(x.first, x.second) );
      }
      return ans;
    }

    int calc( const vii & v, const vii & u ){
      int ans = 0;
      for( auto p : v ){
        for( auto q : u ){
          if( p.first + q.first == t ){
            ans += p.second * q.second;
          }
        }
      }
      return ans;
    }

    int findTargetSumWays(vector<int>& v, int t) {
      this->n = v.size();
      this->t = t;
      int ans = 0;
      if( n < 5 ){
        forall(i,0,1<<n) if( C(v,i) == t ) ++ans;
      }else{
        lv = get_part(v, 0, n/2);
        rv = get_part(v, n/2, n);
        printPair_(lv);
        printPair_(rv);
        ans = calc(lv, rv);
      }
      return ans;
    }
};

class Solution {
  int n;
  public:
  int findTargetSumWays(vector<int>& v, int t) {
    int tot = accumulate(all(v),0);
    if( (tot + t )%2 ) return 0;
    if( tot < t ) return 0;
    t = (tot+t)/2;
    this->n = v.size();
    vi dp(t+1, 0);
    dp[0] = 1;
    for( auto x : v )
      for( int i = t; i >= x; --i )
        dp[i] += dp[i-x];
    return dp[t];
  }
};

int main( int argc, char * argv[] ){
  int n,t; cin >> n >> t;
  vi v(n);
  input(v);
  Solution sol;
  cout << sol.findTargetSumWays(v,t) << '\n';
  return 0;
}
