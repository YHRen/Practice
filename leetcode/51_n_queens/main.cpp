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
typedef vector<char>     vc;
typedef vector<vc>       vvc;
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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

class Solution {
  vector<vector<string>> res;
  int n;
  void mark(int x, int y, vector<string> & B){
    forall(i,x+1,n) B[i][y] = 'x';
    forall(j,y+1,n) B[x][j] = 'x';
    forall(k,1,n){
      if( x+k < n and y + k < n ){
        B[x+k][y+k] = 'x';
      }else break;
    }
    forall(k,1,n){
      if( x+k < n  and y - k >= 0  ){
        B[x+k][y-k] = 'x';
      }else break;
    }
    B[x][y] = 'Q';
  }
  void add_answer( vector<string> & B){
    for(auto & str : B ) for( auto & c : str ) if( c == 'x' ) c = '.';
    res.pb(B);
  };
  bool aux(int layer,  vector<string> B ){
    if(layer == n ){
      add_answer(B);
      return true;
    }
    forall(j,0,n){
      if(B[layer][j] == '.'){
        auto C = B;
        mark(layer, j, C);
        aux(layer+1, C);
      }
    }
    return false;
  }
        
public:
    vector<vector<string>> solveNQueens(int n) {
      this->n = n;
      vector<string> B( n, string(n,'.'));
      aux(0,B);
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
