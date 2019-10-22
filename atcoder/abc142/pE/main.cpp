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
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

int encode( const vi & v ){
  int ans = 0;
  for(auto x : v ) ans |= (1<<(x-1));
  return ans;
}
int main( int argc, char * argv[] ){
  int n, m, w; cin >> n >> m; 
  vi cost(m), code(m);
  forall(t,0,m){
    cin >> cost[t] >> w;
    debug("t=",t, cost[t], w);
    vi v(w);
    debug("vsz", v.size());
    input(v);
    code[t] = encode(v);
  }
  trace(code[1]);
  trace(code[0], code[2]);

  vi p(1<<n, INF), q(1<<n, INF);
  p[0]=q[0]=0;
  forall(i,0,m){// for each code
    int cur_code = code[i];
    int cur_cost = cost[i];
    q = p;
    forall(j,0,1<<n){ // for each state
      if( p[j] == INF ) continue;
      q[j|cur_code] = min(q[j|cur_code], p[j] + cur_cost);
    }
    swap(p,q);
  }

  int ans =  p[(1<<n)-1];
  cout << ( ans == INF ? -1 : ans ) << endl;
  return 0;
}
