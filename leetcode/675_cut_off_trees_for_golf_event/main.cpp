#include <vector>
#include <array>
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
  int n,m;
  static constexpr array<int,4> dx {1,0,-1,0};
  static constexpr array<int,4> dy {0,1,0,-1};
  queue<ii> get_sites(vvi & mtx){
    vector<pair<int ,ii>> sites;
    forall(i,0,n) forall(j,0,m) if(mtx[i][j] > 1) sites.pb(mp(mtx[i][j], mp(i,j)));
    sort(all(sites));
    queue<ii> ans;
    for(auto & p : sites){
      ans.push(p.second);
      debug(p.second.first, p.second.second, p.first);
    }
    return ans;
  }

  bool C( int x, int y ){
    return x >= 0 and y >= 0 and x < n and y < m ;
  }
  int cut_next( ii cur, ii tar, vvi & forest ){
    if( cur == tar ){ forest[tar.first][tar.second] = 1; return 0; }
    queue<ii> Q;
    vvi dist(n, vi(m, INF));
    dist[cur.first][cur.second]=0;
    Q.push(cur);
    while(!Q.empty()){
      auto cur = Q.front(); Q.pop();
      int d = dist[cur.first][cur.second];
      forall(i,0,4){
        int xx = cur.first+dx[i], yy = cur.second+dy[i];
        if( C( xx, yy ) ){
          if( mp(xx,yy) == tar ){
            forest[xx][yy] = 1;
            return d+1;
          }
          if( forest[xx][yy] >= 1 and dist[xx][yy] == INF ){
            dist[xx][yy] = d+1;
            Q.push(mp(xx,yy));
          }
        }
      }
    }
    return -1;
  }
  struct data{ 
    int h, g, x, y; 
    data(int h, int g, int x, int y):h(h), g(g),x(x),y(y){}
  };

  int hadlock_next(ii cur, ii tar, vvi & forest){
    if( cur == tar ){ forest[tar.first][tar.second] = 1; return 0; }
    const int tx = tar.first, ty = tar.second;
    deque<data> dq;
    dq.push_back(data(0,0,cur.first,cur.second));
    vector<bool> mask(n*m, false);
//    mask[cur.first*m+cur.second] = true;
    auto caldist = [tar](ii val){ return abs(val.first-tar.first)+abs(val.second-tar.second);};
    auto closer = [tar](ii lhs, ii rhs){ return abs(lhs.first-tar.first) < abs(rhs.first-tar.first) || abs(lhs.second - tar.second) < abs(rhs.second < tar.second) ;};
    while (!dq.empty()) {
      auto tmp = dq.front(); dq.pop_front();
      int x = tmp.x, y = tmp.y;
      debug("dq=",x,y,tmp.g);
      if( mask[x*m+y] == true ){ continue; }
      mask[x*m+y] = true;
      if( mp(x,y) == tar ){
        forest[x][y] = 1;
        return caldist(cur)+2*tmp.g;
      }
      forall(i,0,4){
        int xx = tmp.x+dx[i], yy = tmp.y+dy[i];
        if( C( xx, yy ) ){
          if( forest[xx][yy] >= 1 and mask[xx*m+yy] == false ){
            if( abs(x-tx) > abs(xx-tx) || abs(y-ty) > abs(yy-ty) ){
              dq.push_front(data(0,tmp.g, xx, yy ));
            }else{
              dq.push_back(data(0,tmp.g+1, xx, yy ));
            }
          }
        }
      }
    }
    return -1;
  }

  int astar_next(ii cur, ii tar, vvi & forest){
    if( cur == tar ){
      forest[tar.first][tar.second] = 1;
      return 0;
    }
    auto cmp = [](data lhs, data rhs){ return lhs.h > rhs.h; };
    auto caldist = [tar](ii val){ return abs(val.first-tar.first)+abs(val.second-tar.second);};
    priority_queue<data, vector<data>, decltype(cmp)> pq(cmp);
    vvi dist(n, vi(m, INF));
    dist[cur.first][cur.second]=0;
    pq.push(data(1+caldist(cur), 0, cur.first, cur.second));
    while(!pq.empty()){
      auto tmp = pq.top(); pq.pop();
      debug(tmp.x,tmp.y,tmp.g,tmp.h);
      if( tmp.g > dist[tmp.x][tmp.y]) continue;
      forall(i,0,4){
        int xx = tmp.x+dx[i], yy = tmp.y+dy[i];
        if( C( xx, yy ) ){
          if( mp(xx,yy) == tar ){
            forest[xx][yy] = 1;
            return tmp.g+1;
          }
          if( forest[xx][yy] >= 1 and dist[xx][yy] > tmp.g+1 ){
            dist[xx][yy] = tmp.g+1;
            pq.push(data(tmp.g+1+caldist(mp(xx,yy)),tmp.g+1, xx, yy)); 
          }
        }
      }
    }
    return -1;
  }
  struct Node{
    int r, c, d;
    Node(int i, int j, int v) {
      r = i;  // row
      c = j;  // col
      d = v;  // height or Detour
    }

    bool operator<(const Node& n) const{
      return (d < n.d);
    }
  };
  int hadlock(vector<vector<int>>& forest, int sr, int sc, int tr, int tc) {    
        deque<Node> dq;
        Node cur(sr, sc, 0);
        dq.push_back(cur);
        
        int R = forest.size(), C = forest[0].size();
        vector<bool> mask(R*C, false);
        
        vector<vector<int>> direct = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!dq.empty()) {
            Node n = dq.front();
            dq.pop_front();
            if (mask[n.r*C+n.c]) {
                continue;
            }
            mask[n.r*C+n.c] = true;
            if (n.r == tr && n.c == tc) {
                return abs(sr - tr) + abs(sc - tc) + 2*n.d;
            }
            
            for (int i = 0; i < direct.size(); i++) {
                int nr = n.r + direct[i][0];
                int nc = n.c + direct[i][1];
                
                if (nr >= 0 && nr < R && nc >= 0 && nc < C && forest[nr][nc] > 0) {
                    bool closer = abs(n.r - tr) > abs(nr - tr) || abs(n.c - tc) > abs(nc - tc);
                    // If the next position is closer to the target, we put it in the front of the deque
                    if (closer) {
                        Node t(nr, nc, n.d);
                        dq.push_front(t);
                    }
                    // Otherwise, we put it in the rear of the deque
                    else {
                        Node t(nr, nc, n.d+1);
                        dq.push_back(t);
                    }
                }
            }
        }
        
        return -1;
    }

  public:
    int cutOffTree(vector<vector<int>>& forest) {
      n = sz(forest), m = sz(forest[0]);
      auto sites = get_sites( forest );
      ii cur = {0,0};
      int ans = 0;
      do{
        //int d = cut_next(cur, sites.front(), forest);
        //int d = astar_next(cur, sites.front(), forest);
        int d = hadlock_next(cur, sites.front(), forest);
       //int d = hadlock(forest, cur.first, cur.second,  sites.front().first, sites.front().second);
        if( d == -1 ) return -1;
        ans += d;
        cur = sites.front();
        sites.pop();
      }while(!sites.empty());
      return ans;
    }
};
constexpr array<int,4> Solution::dx;
constexpr array<int,4> Solution::dy;
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n,vi(m));
  for(auto & v : mtx )input(v);
  Solution sol;
  cout << sol.cutOffTree(mtx) << '\n';
  return 0;
}

