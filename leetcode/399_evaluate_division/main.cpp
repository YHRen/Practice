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
typedef pair<int,double> id;
typedef vector<id>       vid;
typedef vector<vid>      vvid;
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
  vi visited;
  vvid G;
  double dfs( int x, int t, double cur=1.0 ){
    if( x == t ) return cur;
    for(auto & p : G[x]){
      if( visited[p.first] == 0 ){
        visited[p.first] = 1;
        auto tmp = dfs(p.first, t, cur*p.second);
        if( tmp != -1 ) return tmp;
      }
    }
    return -1.0;
  }
  
  public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
      int n = 0;
      int m = sz(values);
      unordered_map<string, int> dic;
      for(auto & e : equations){
        if( dic.find(e[0]) == dic.end() ) dic[e[0]]=n++;
        if( dic.find(e[1]) == dic.end() ) dic[e[1]]=n++;
      }
      G.resize(n);
      visited.resize(n);
      forall(i,0,m){
        auto & e = equations[i];
        if( e[0] == e[1] ) continue;
        G[dic[e[0]]].pb(mp(dic[e[1]],values[i]));
        G[dic[e[1]]].pb(mp(dic[e[0]],1/values[i]));
      }
      vector<double> res;
      for(auto & e : queries){
        if( dic.find(e[0]) == dic.end() or dic.find(e[1]) == dic.end() ) res.pb(-1.0);
        else if( e[0] == e[1] ) res.pb(1.0);
        else{
          fill(all(visited),0);
          visited[dic[e[0]]] = 1;
          res.pb( dfs(dic[e[0]],dic[e[1]]));
        }
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
