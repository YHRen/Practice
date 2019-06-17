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
typedef vector<vii>      vvii;
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

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  int n,m;
  string S,T;
  vi vs,vt;
  vvii nxt;

  int aux(int x, int y, vvi & dp){
    if( x == n or y == m ) return 0;
    if( dp[x][y]  != -1 ) return dp[x][y];
    debug("x,y",x,y);
    if( S[x] == T[y] ){
      dp[x][y] = 1+aux(x+1,y+1, dp);
      debug("assiging",x,y,"dp",dp[x][y]);
      nxt[x][y] = mp(x+1,y+1);
    }else{
      int p = aux(x+1,y,dp);
      int q = aux(x,y+1,dp);
      if( p>q ){
        dp[x][y] = p;
        nxt[x][y] = mp(x+1,y);
      }else{
        dp[x][y] = q;
        nxt[x][y] = mp(x,y+1);
      }
      debug("assiging",x,y,"dp",dp[x][y]);
    }
    return dp[x][y];
  }

  public:
    string shortestCommonSupersequence(string str1, string str2) {
      n = sz(str1), m = sz(str2);
      swap(S,str1);
      swap(T,str2);
      vvi dp(n+1,vi(m+1, -1));
      nxt.resize(n+1);for(auto & v : nxt) v.resize(m+1,mp(-1,-1));
      
      string res="";
      int common = aux(0,0,dp);
      debug("common",common);
      int w = sz(vs);
      int p = 0, q = 0;
      debug("vs");
      print_(vs);
      debug("vt");
      print_(vt);
      debug("nxt");
      for(auto & v : nxt){
        printPair_(v);
      }
      do{
        auto [pp,qq] = nxt[p][q];
        debug("res",res, pp, qq, p, q);
        debug("n,m",n,m);
        if( pp!= p and qq!=q ){
          res.pb(S[pp-1]);
        }else if( pp != p ){
          res.pb(S[pp-1]);
        }else if( qq != q ){
          res.pb(T[qq-1]);
        }
        swap(pp,p);
        swap(qq,q);
      }while(p<n and q <m);

      debug("p,q",p,q);

      while(p<n){
        res.pb(S[p++]);
      }
      while(q<m){
        res.pb(T[q++]);
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  string s,t; cin >> s >> t;
  Solution sol;
  cout << sol.shortestCommonSupersequence(s,t) << endl;
  return 0;
}
