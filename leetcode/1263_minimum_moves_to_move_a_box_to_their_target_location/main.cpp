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
typedef vector<vvi>      vvvi;
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
  int n,m;
  vvi dir;
  vector<bool> is_visited;
  vector<vector<char>> mtx;
  bool C(int xx, int yy){
    if( xx < 0 or yy < 0 or xx >= n or yy >= m or mtx[xx][yy] == '#' ) return false;
    else return true;
  }

  bool can_bfs(int xx, int yy, int xxx, int yyy, int x, int y){
    // BFS from xx,yy to xxx, yyy, with x,y blocked
    if( !C(xx,yy) ) return false;
    if( xx == xxx and yy == yyy ) return true;
    is_visited.assign(n*m, 0);
    is_visited[xx*m+yy] = 1;
    mtx[x][y] = '#';
    queue<int> Q;
    Q.push(xx*m+yy);
    while( !Q.empty() ){
      auto p = Q.front(); Q.pop();
      int aa = p/m, bb = p%m;
      for(auto d : dir){
        int aaa = aa+d[0], bbb = bb+d[1];
        if( aaa == xxx and bbb == yyy ){
          mtx[x][y] = '.';
          return true;
        }
        int nxt = aaa*m+bbb;
        if( C(aaa,bbb) and is_visited[nxt] == false ){
          is_visited[nxt]= true;
          Q.push(nxt);
        }
      }
    }
    mtx[x][y] = '.';
    return false;
  }

public:
    int minPushBox(vector<vector<char>>& grid) {
      n = sz(grid), m = sz(grid[0]);
      dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
      this->mtx = grid;
      this->is_visited.resize(n*m);
      int P,T,B;
      forall(i,0,n){
        forall(j,0,m){
          if( grid[i][j] == 'T' ) T = i*m+j;
          if( grid[i][j] == 'S' ) P = i*m+j;
          if( grid[i][j] == 'B' ) B = i*m+j;
        }
      }

      unordered_set<int> visited;
      queue<ii> Q;
      Q.push(mp(B,P));
      int step = 0;
      auto to_idx = [&](int x, int y){ return x*m + y; };
      auto to_hash = [&](int x, int y){ return (x<<10) + y; };
      while( !Q.empty() ){
        int cur_sz = sz(Q);
        while(cur_sz--){
          auto p = Q.front(); Q.pop();
          if( p.first == T ) return step;
          int box_x = p.first/m, box_y = p.first%m;
          int psn_x = p.second/m, psn_y = p.second%m;
          for(auto d : dir){
            int box_xx = box_x + d[0], box_yy = box_y + d[1];
            int per_xx = box_x - d[0], per_yy = box_y - d[1];
            if( !C(box_xx, box_yy) or !C(per_xx, per_yy) ) continue;
            int hash = to_hash( to_idx(box_xx, box_yy), to_idx(box_x, box_y));
            if( visited.count(hash) ) continue;
            if( can_bfs(psn_x, psn_y, per_xx, per_yy, box_x, box_y) ){
              visited.insert(hash);
              Q.push(mp( to_idx(box_xx, box_yy), p.first) );
            }
          }
        }
        step ++;
      }
      return -1;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vector<vector<char>> mtx(n, vector<char>(m));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.minPushBox(mtx) << endl;

  return 0;
}
