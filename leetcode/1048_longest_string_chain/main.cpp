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
  bool C( const string & wx, const string & wy){
    int tor = 1;
    int m = sz(wy);
    for(int i = 0, j = 0; i < m-1 and j < m; ){
      if( wx[i] == wy[j] ){
        ++i; ++j;
      }else if( tor-- == 1 ){
        ++j;
      }else{
        return false;
      }
    }
    return true;
  }

public:
    int longestStrChain(vector<string>& words) {
      int n = sz(words);
      sort(all(words), [](const string & lhs, const string & rhs){
          if( sz(lhs) < sz(rhs) ) return true;
          else if( sz(lhs) == sz(rhs) ) return lhs < rhs;
          else return false;
          });
      print_(words);
      vvi G(n);
      forall(i,0,n){
        forall(j,i+1,n){
          if( sz(words[i]) == sz(words[j]) ) continue;
          if( sz(words[j]) - sz(words[i]) > 1 ) break;
          if( C(words[i], words[j]) ){
            debug("connecting ", words[i], words[j]);
            G[i].pb(j);
          }
        }
      }
      vi ind(n,0);
      for(auto & v : G){
        for(auto x : v ){
          ind[x] ++;
        }
      }
      queue<int> Q;
      forall(i,0,n) if( ind[i] == 0 ) Q.push(i);
      vi dist(n,0);
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        for(auto y : G[x] ){
          dist[y] = max(dist[y],dist[x]+1);
          ind[y] -= 1;
          if( ind[y] == 0 ) Q.push(y);
        }
      }
      return 1+*max_element(all(dist));
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vector<string> words(n);
  input(words);
  Solution sol;
  cout << sol.longestStrChain(words) << endl;
  return 0;
}
