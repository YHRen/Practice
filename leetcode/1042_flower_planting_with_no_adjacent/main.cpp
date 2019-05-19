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
  vvi g;
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
      g.resize(N);
      for(auto & e : paths){
        g[e[0]-1].pb(e[1]-1);
        g[e[1]-1].pb(e[0]-1);
      }
      vi colors(N,0);
      vi pos(5,0);
      queue<int> Q;
      forall(i,0,N){
        if( colors[i] == 0 ){
          Q.push(i);
          colors[i] = 1;
          while(!Q.empty()){
            int x = Q.front(); Q.pop();
            for(auto y : g[x]){
              if( colors[y] == 0 ){
                fill(all(pos), 0);
                for(auto z : g[y] ){
                  pos[colors[z]] = 1;
                }
                forall(i,1,5){
                  if( pos[i] == 0 ){
                    colors[y] = i;
                    Q.push(y);
                  }
                }
              }
            }
          }
        }
      }
      return colors;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
