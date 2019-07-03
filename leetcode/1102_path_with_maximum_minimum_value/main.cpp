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
  int n,m;
  vector<vector<char>> visited;
  int dx[4] = {1,0,-1,0};
  int dy[4] = {0,1,0,-1};
  bool D(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
  }

  bool C(const vvi & A, int w){
    /* all the nodes in the path have value greater or equal to w*/
    if( A[0][0] < w or A[n-1][m-1] < w ) return false;
    for(auto & v : visited) v.assign(m,0);
    queue<int> Q;
    visited[0][0] = true;
    Q.push(0);
    while(!Q.empty()){
      auto xy = Q.front(); Q.pop();
      int x = xy/m, y = xy%m;
      forall(i,0,4){
        int xx = x+dx[i], yy = y+dy[i];
        if( xx == n-1 and yy == m-1 ) return true;
        if( D(xx,yy) and visited[xx][yy] == false and A[xx][yy] >= w ){
          visited[xx][yy] = true;
          Q.push(xx*m+yy);
        }
      }
    }
    return false;
  }

  public:
    int maximumMinimumPath(vector<vector<int>>& A) {
      // 
      n = sz(A), m = sz(A[0]);
      visited.resize(n); for(auto & v : visited) v.resize(m);
      
      int lo = 0, hi = 0, mid, ans=-1;
      for(auto & v : A) hi = max(hi, *max_element(all(v)));
      while( lo <= hi ){
        mid = (lo+hi) / 2;
        if( C(A,mid) ){
          ans = mid;
          lo = mid+1;
        }else{
          hi = mid-1;
        }
      }
      return ans;
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvi mtx(n, vi(m)); 
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.maximumMinimumPath(mtx) << endl;
  return 0;
}
