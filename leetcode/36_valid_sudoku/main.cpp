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
  vector<char> v;
  bool is_valid_row(int row, vector<vector<char>> & board ){
    fill(all(v),0);
    for(char c : board[row]){
      if( c == '.' ) continue;
      int idx = int(c-'0')-1;
      if( v[idx] ) return false;
      v[idx] = 1;
    }
    return true;
  }

  bool is_valid_col(int col, vector<vector<char>> & board ){
    fill(all(v),0);
    forall(i,0,9){
      char c = board[i][col];
      if( c == '.' ) continue;
      int idx = int(c-'0')-1;
      if( v[idx] ) return false;
      v[idx] = 1;
    }
    return true;
  }

  bool is_valid_sub(ii sub, vector<vector<char>> & board){
    auto [x,y] = sub;
    fill(all(v),0);
    forall(i,x,x+3){
      forall(j,y,y+3){
        char c = board[i][j];
        if( c == '.' ) continue;
        int idx = int(c-'0')-1;
        if( v[idx] ) return false;
        v[idx]=1;
      }
    }
    return true;
  }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      //9 by 9
      vii sub;
      forall(i,0,9){ sub.pb(mp(i/3*3,i%3*3));}
      this->v.resize(9);
      forall(i,0,9) if( !is_valid_row(i,board)) return false;
      forall(j,0,9) if( !is_valid_col(j,board)) return false;
      forall(k,0,9) if( !is_valid_sub(sub[k], board)) return false;
      return true;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
