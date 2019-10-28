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
  int N, M, res;
  unordered_map<ll, int> dp;

  ll encode( const vi & h ){
    // sz(h) < 14, h[i] < 14
    ll ans = 0;
    for(auto & x : h){
      ans |= x;
      ans <<= 4;
    }
    return ans;
  }

  void dfs(vi & h, int cost, ll code){
    if( cost >= res ) return;
    if(auto itr = dp.find(code); itr!=dp.end() and cost >= itr->second){
      return;
    }else{
      dp[code] = cost;
    }

    // Find Valley
    auto idx = min_element(all(h)) - h.begin();
    int min_H = h[idx];
    if( min_H == M ){
      res = min(res, cost);
      return;
    }
    int end = idx;
    while( end < N and h[end] == min_H) end++;
    end = min<int>(end, M - min_H + idx);
    trace(idx, end);

    // fill the valley with squares from big to small
    for(int j = end-1; j>=idx; --j){
      int side_len = j-idx+1;
      vi u = h;
      forall(k,idx,j+1) u[k] += side_len;
      dfs(u, cost+1, encode(u));
    }
  }
public:
    int tilingRectangle(int n, int m) {
      if( n > m ) swap(n,m);
      // n <= m  always
      this->N = n, this->M = m, this->res = INF;

      vi h = vi(n, 0);
      dfs(h, 0, 0); // 
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  Solution sol;
  cout << sol.tilingRectangle(n,m) << '\n';
  return 0;
}

//# https://demonstrations.wolfram.com/MinimallySquaredRectangles/
//# http://int-e.cohomology.org/~bf3/haskell/Young.hs
//# https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/discuss/414260/8ms-Memorized-Backtrack-Solution-without-special-case!
/*
    int tilingRectangle(int n, int m) {
      if( n < m ) swap(n,m);
      vvi dp(14);
      dp[1] = {1};
      dp[2] = {2,1};
      dp[3] = {3,3,1};
      dp[4] = {4,2,4,1};
      dp[5] = {5,4,4,5,1};
      dp[6] = {6,3,2,3,5,1};
      dp[7] = {7,5,5,5,5,5,1};
      dp[8] = {8,4,5,2,5,4,7,1};
      dp[9] = {9,6,3,6,6,3,6,7,1};
      dp[10] = {10,5,6,4,2,4,6,5,6,1};
      dp[11] = {11,7,6,6,6,6,6,6,7,6,1};
      dp[12] = {12,6,4,3,6,2,6,3,4,5,7,1};
      dp[13] = {13,8,7,7,6,6,6,6,7,7,6,7,1};
      return dp[n][m-1];
    }
*/
