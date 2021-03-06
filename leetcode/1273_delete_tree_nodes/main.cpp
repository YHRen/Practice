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
    int deleteTreeNodes(int n, vector<int>& parent, vector<int>& value) {
      if( n == 1 ) return value[0] == 0 ? 1 : 0;
      vi deg(n,0);
      forall(i,1,n){
        deg[parent[i]]++;
      }
      vi sub_tree(n,1);
      int ans = 0;
      queue<int> Q;
      forall(i,1,n){
        if( deg[i] == 0 ){
          Q.push(i);
        }
      }
      trace(Q.size());
      while( !Q.empty() ){
        int x = Q.front(); Q.pop();
        trace(x, value[x], sub_tree[x], parent[x], ans);
        if (value[x] == 0) {
          ans += sub_tree[x];
          debug("adding ans", ans, sub_tree[x]);
          if( parent[x] != -1 ){
            int p = parent[x];
            deg[p] -= 1;
            if( deg[p] == 0 ){ Q.push(p); }
            //  sub_tree[parent[x]] -= sub_tree[x];
          }
          continue;
        }
        if( parent[x] != -1 ){
          int p = parent[x];
          value[p] += value[x];
          deg[p] -= 1;
          sub_tree[p] += sub_tree[x];
          if( deg[p] == 0 ){
            Q.push(p);
          }
        }
      }
      return n - ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  vi u(n); input(u);
  Solution sol;
  cout << sol.deleteTreeNodes(n, v, u) << endl;
  return 0;
}
