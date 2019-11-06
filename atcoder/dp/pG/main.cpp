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

int main( int argc, char * argv[] ){
  int n, m, a, b; cin >> n >> m; 
  vvi G(n), H(n);
  vi indeg(n,0);
  forall(i,0,m){
    cin >> a >> b;
    G[a-1].pb(b-1);
    H[b-1].pb(a-1);
    indeg[b-1] ++;
  }
  
  // linearize
  queue<int> Q;
  forall(i,0,n) if(indeg[i]==0){
    Q.push(i);
  }
  vi ord;
  while( !Q.empty() ){
    auto x = Q.front(); Q.pop();
    ord.pb(x);
    for(auto y : G[x]){
      indeg[y] --;
      if( indeg[y] == 0 ){
        Q.push(y);
      }
    }
  }
  debug("ord", sz(ord));
  print_(ord);
  
  // find the maximum path
  vi dist(n, -1);
  for(auto x : ord){
    if( H[x].empty() ){
      dist[x] = 0;
    }else{
      for(auto y : H[x]){
        dist[x] = max(dist[x], 1+dist[y]);
      }
    }
    trace(x, dist[x]);
  }
  cout << *max_element(all(dist)) << endl;
  return 0;
}
