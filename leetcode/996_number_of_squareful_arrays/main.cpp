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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n;
  vi A;
  vvi g;
  set<vi> ans;
  void dfs(int idx, int p, vi & vst, vi & path ){
    if(  p == n ){ 
      vi tmp(n);
      forall(i,0,n) tmp[i] = A[path[i]];
      ans.insert(tmp);
      debug("found");
      print_(tmp);
      return;
    }
    for(auto x : g[idx]){
      if( vst[x] ) continue;
      vst[x] = true;
      path.pb(x);
      dfs(x, p+1, vst, path);
      vst[x] = false;
      path.pop_back();
    }
  }

  bool C( int x, int y ){
    ll s = x+y;
    ll t = ll(sqrt(s));
    if( t*t == s ) return true;
    else return false;
  }
  bool connected(){
    vi visited(n,0);
    visited[0] = 1;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
      int x = Q.front(); Q.pop();
      for(auto y : g[x]){
        if( visited[y] == false ){
          visited[y] = true;
          Q.push(y);
        }
      }
    }
    for(auto x : visited ) if( x == 0 ) return false;
    return true;
  }
  public:
    int numSquarefulPerms(vector<int>& A) {
      sort(all(A));
      this->A = A;
      n = A.size();
      vvi mtx(n, vi(n,0));
      g.resize(n);
      set<ii> e;
      forall(i,0,n){
        forall(j,i+1,n){
          if( C(A[i], A[j]) ){
            e.insert(mp(A[i],A[j]));
            e.insert(mp(A[j],A[i]));
            mtx[i][j] = 1;
            mtx[j][i] = 1;
            g[i].pb(j);
            g[j].pb(i);
          }
        }
      }
      if( !connected() ) return 0;
      int ans = 0;
      do{
        bool flag = true;
        forall(i,0,n-1){
          if( e.find(mp(A[i],A[i+1])) == e.end() ){
            flag = false;
            break;
          }
        }
        print_(A);
        debug("flag= ",flag);
        if( flag ) ans ++;
      }while( next_permutation(all(A)));
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.numSquarefulPerms(v) << '\n';

  return 0;
}
