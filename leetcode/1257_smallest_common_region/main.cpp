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
  vvi G;
  unordered_map<string,int> r2idx;
  unordered_map<int,string> idx2r;
  void build( const vector<vector<string>> & regions ){
    for(auto & v : regions){
      for(auto & s : v){
        if( r2idx.find(s) == r2idx.end() ){
          r2idx[s] = sz(r2idx);
        }
      }
    }
    G.resize(sz(r2idx));
    for(auto & v : regions){
      int m = sz(v);
      for(int i = m-1; i > 0; --i){
        G[r2idx[v[i]]].pb(r2idx[v[0]]);
      }
    }
    for(auto & p : r2idx){
      idx2r[p.second] = p.first;
    }
  }

  public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
      build(regions);
      int x = r2idx[region1], y = r2idx[region2];

      set<int> path_to_root;
      while(true){
        path_to_root.insert(x);
        if(G[x].empty() ) break;
        debug(x, idx2r[x], "has", idx2r[G[x][0]]);
        x = G[x][0];
      }
      print_(path_to_root);

      while(true){
        if( path_to_root.find(y) != path_to_root.end() ) return idx2r[y];
        if( G[y].empty() ) break;
        y = G[y][0];
      }

      return "";
    }
};
int main( int argc, char * argv[] ){
  vector<vector<string>> reg = {{"Earth","North America","South America"},
    {"North America","United States","Canada"},
    {"United States","New York","Boston"},
    {"Canada","Ontario","Quebec"},
    {"South America","Brazil"}};
  string region1 = "Quebec";
  string region2 = "New York";
  Solution sol;
  cout << sol.findSmallestRegion(reg, region1, region2);
  return 0;
}
