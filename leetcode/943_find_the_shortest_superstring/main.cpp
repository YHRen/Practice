#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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
  int N;
  vvi dp;
  vvi nxt;
  vvi  g;
  int calc_dist(const string & s, const string & t){
    int ans = 0;
    int m = s.size();
    char x = *s.rbegin();
    auto itr = t.find(x,0);
    while( itr != string::npos ){
      int tmp = 0;
      if( itr >= m ) break;
      for( int i = itr; i >=0 ; --i ){
        if (t[i] != s[m - itr + i - 1]) {
          tmp = 0;
          break;
        } else {
          tmp++;
        }
      }
      ans = max(ans, tmp);
      itr = t.find(x, itr+1);
    }
    return ans;
  }

  int dfs( int x, int visited){
    if( dp[x][visited] != -1 ) return dp[x][visited];
    debug(visited, N)
    if( visited == N ){ return 0; }
    int max_dist = -1;
    int nxt_idx = -1;
    forall(i,0,n){
      if( !(visited&(1<<i)) ){
        debug("at",x,"visiting",i);
        int tmp = (visited | (1<<i));
        int p = g[x][i] + dfs(i, tmp);
        if( max_dist < p ){ 
          nxt_idx  = i;
          max_dist = p; }
      }
    }
    nxt[x][visited]= nxt_idx;
    dp[x][visited] = max_dist;
    return max_dist;
  }

 public:
  string shortestSuperstring(vector<string>& A) {
    n = A.size(); if (n == 1) return A[0];
    N = (1<<n)-1;
    dp.resize(n); for(auto & v : dp ) v.resize(1<<n, -1);
    nxt.resize(n); for(auto & v : nxt ) v.resize(1<<n, -1);
    g.resize(n); for(auto & v : g ) v.resize(n,0);
    forall(i, 0, n)  forall(j, 0, n) if (i != j)
      g[i][j] = calc_dist(A[i], A[j]);
    for(auto v : g){ print_(v); }

    int longest = -1;
    int starting_id = -1;
    forall(i,0,n){
      int d = dfs(i, 1<<i);
      debug("i=",i,"d=",d);
      if( d  > longest ){
        longest = d;
        starting_id = i;
      }
    }

    for(auto v : dp){ print_(v);}
    debug("d", longest, "starting id", starting_id);
    for(auto v : nxt){ print_(v);}

    string ans;
    int dis = 0;
    int pid = starting_id;
    int visited = 0;
    forall(i,0,n){
      visited |= (1<<pid);
      ans += A[pid].substr(dis);
      auto u = nxt[pid][visited];
      dis = g[pid][u];
      debug("nxt = ", u , "dist = ", dis);
      pid = u;
    }
    debug(ans);
    return ans;
  }
};

int main(int argc, char* argv[]) {
  int n; cin >> n;
  vector<string> v(n); input(v);
  print_(v);
  Solution sol;
  cout << sol.shortestSuperstring(v) << '\n';
  return 0; }
