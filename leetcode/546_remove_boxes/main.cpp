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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef vector<vvi>      vvvi;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  unordered_map<int,vi> idx;
  int n;
  vvvi dp; // i,j,k
  vi v;
  int aux(int x, int y, int k){
    debug("x,y,k",x,y,k);//, v[x]);
    if( x == n or x > y ) return 0;
    if( dp[x][y][k] != -1 ) return dp[x][y][k];
    if( x == y ) return dp[x][y][k] = (k+1)*(k+1);
    int nxt = x;
    while( nxt <= y and v[nxt] == v[x] ){ ++nxt; }// nxt is the first index that is not equal to v[x]
    debug("nxt=",nxt);//, v[nxt]);
    int nxt_k = k + (nxt-x);
    int res = (nxt_k)*(nxt_k) + aux(nxt, y, 0);
    debug("x,y,k",x,y,k,"nxt_k=",nxt_k,"res=",res, "v[x]=",v[x]);
    //for( auto itr = lower_bound(all(idx[v[x]]), nxt); itr != idx[v[x]].end(); ++ itr ){
    for( auto itr = lower_bound(all(idx[v[x]]), x+1); itr != idx[v[x]].end() and *itr <= y; ++ itr ){
      debug("*itr = ",*itr);
      res = max(res, aux(x+1, *itr-1, 0) + aux(*itr,y,k+1));
      debug("updated x,y,k,",x,y,k,"*itr=",*itr,"res = ",res);
    }
    debug("assign dp[x][y][k]",x,y,k,"=",res);
    return dp[x][y][k] = res;
  }
  int helper( int x, int y, int k, int DP[100][100][100] ){
    debug("x,y,k",x,y,k);
    while( x < y && v[x+1] == v[x] ) x++,k++;
    if( x > y or x == n ) return 0;
    if( DP[x][y][k] > 0 ) return DP[x][y][k];
    DP[x][y][k] = (k+1)*(k+1) + helper(x+1, y, 0, DP);
    debug("x,y,k",x,y,k);
    for( int i = x+1; i <= y; ++i ){
      if( v[i] == v[x] ){
        DP[x][y][k] = max( DP[x][y][k], 
            helper(x+1, i-1, 0, DP) + helper(i,y,k+1,DP));
      }
    }
    return DP[x][y][k];
  }

  public:
    int removeBoxes(vector<int>& boxes) {
      v = boxes;
      n = sz(v);
      int DP[100][100][100] = {0};
      return helper(0, n-1, 0, DP);

    }
    int removeBoxes_slow(vector<int>& boxes) {
      v = boxes;
      n = sz(boxes);
      dp.resize(n);
      for(auto & mtx : dp){
        mtx.resize(n);
        for(auto & v : mtx ){
          v.resize(n,-1);
        }
      }
      forall(i,0,n) dp[i][i][0] = 1;
      forall(i,0,n){
        idx[boxes[i]].pb(i);
      }
      return aux(0, n-1, 0);
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.removeBoxes(v) << endl;
  return 0;
}
