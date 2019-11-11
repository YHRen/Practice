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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
      int n = sz(grid), m = sz(grid[0]);
      vvi visited = grid;
      int ans = 0;
      bool flag = true;
      auto C = [n,m](int x, int y){ return x >= 0 and y >= 0 and x < n and y < m; };
      auto D = [n,m](int x, int y){ return x == n-1 or x == 0 or y == m-1 or y == 0; };
      vi dx = {1,0,-1,0};
      vi dy = {0,1,0,-1};
      forall(i,0,n){
        forall(j,0,m){
          if( visited[i][j] != 0 ) continue;
          queue<ii> Q;
          Q.push(mp(i,j));
          visited[i][j] = 1;
          flag = !D(i,j);
          while(!Q.empty()){
            auto p = Q.front(); Q.pop();
            int x = p.first, y = p.second;
            forall(d,0,4){
              int xx = x + dx[d], yy = y + dy[d];
              if( C(xx,yy) and visited[xx][yy] == 0 ){
                visited[xx][yy] = 1;
                if( D(xx, yy) ) flag = false;
                Q.push(mp(xx,yy));
              }
            }
          }
          if( flag ) ++ans;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
