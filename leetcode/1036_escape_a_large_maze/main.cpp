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
typedef vector<char>     vc;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<vc>       vvc;
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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
      vi uniq_x, uniq_y;
      for( const auto & v : blocked ){
        uniq_x.pb(v[0]);
        uniq_y.pb(v[1]);
        if( v[0] > 0 ) uniq_x.pb(v[0]-1);
        if( v[1] > 0 ) uniq_y.pb(v[1]-1);
        if( v[0]+1 < 1000000 ) uniq_x.pb(v[0]+1);
        if( v[1]+1 < 1000000 ) uniq_y.pb(v[1]+1);
      }
      uniq_x.pb(source[0]);
      uniq_x.pb(target[0]);
      uniq_y.pb(source[1]);
      uniq_y.pb(target[1]);
      sort(all(uniq_x));
      sort(all(uniq_y));
      uniq_x.erase(unique(all(uniq_x)), uniq_x.end());
      uniq_y.erase(unique(all(uniq_y)), uniq_y.end());

      unordered_map<int,int> x2idx, y2idx;
      int n = sz(uniq_x), m = sz(uniq_y);
      forall(i,0,sz(uniq_x)){ x2idx[uniq_x[i]]=i; }
      forall(i,0,sz(uniq_y)){ y2idx[uniq_y[i]]=i; }
      vvc B( sz(uniq_x), vc(sz(uniq_y), '.'));
      for(auto & v : blocked ){
        B[x2idx[v[0]]][y2idx[v[1]]] = 'x';
      }
      vvc visited(n, vc(m, false));

      debug("target",target[0], target[1]);
      int sx = x2idx[source[0]], sy = y2idx[source[1]];
      int tx = x2idx[target[0]], ty = y2idx[target[1]];

      for(auto v : B ){
        print_(v);
      }
      visited[sx][sy] = 1;
      queue<ii> Q;
      Q.push(mp(sx,sy));
      vi dx = {1,0,-1,0};
      vi dy = {0,1,0,-1};
      debug("sx,sy",sx,sy);
      debug("ts,ty",tx,ty);
      while(!Q.empty()){
        auto [x,y] = Q.front(); Q.pop();
        forall(i,0,4){
          int xx = x + dx[i], yy = y + dy[i];
          if( xx >= 0 and yy >= 0 and xx < n and yy < m and B[xx][yy] != 'x' and visited[xx][yy] == false ){
            visited[xx][yy] = true;
            if( xx == tx and yy==ty ) return true;
            Q.push(mp(xx,yy));
          }
        }
      }
      return false;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi mtx(n, vi(2));
  for(auto & v : mtx ) 
    input(v);

  int sx,sy,ts,ty;
  cin>> sx>> sy>> ts>> ty;
  Solution sol;
  vi S = {sx,sy};
  vi T = {ts,ty};
  cout << sol.isEscapePossible(mtx, S,T ) << endl;
  return 0;
}
