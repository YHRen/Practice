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

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

class Solution {
  vi v;
  int c2idx(char c){ return int(c-'0')-1;}
  int cor2subidx(int x, int y){ return x/3*3+ y/3;}
  vi get_row_binary(int row, const vvc & B){
    fill(all(v),0);
    for(char c : B[row]){
      if( c == '.' ) continue;
      int idx = int(c-'0')-1;
      v[idx] = 1;
    }
    return v;
  }
  vi get_col_binary( int col, const vvc & B ){
    fill(all(v),0);
    forall(i,0,9){
      char c = B[i][col];
      if( c == '.' ) continue;
      int idx = int(c-'0')-1;
      v[idx] = 1;
    }
    return v;
  }

  
  vi get_sub_binary(ii sub, const vvc & B){
    auto [x,y] = sub;
    fill(all(v),0);
    forall(i,x,x+3){
      forall(j,y,y+3){
        char c = B[i][j];
        if( c == '.' ) continue;
        int idx = int(c-'0')-1;
        v[idx]=1;
      }
    }
    return v;
  }


  bool solve(int cor, vvc & B, vector<set<int>> & row_pos, 
                               vector<set<int>> & col_pos,
                               vector<set<int>> & sub_pos){
    debug("at solve", cor);
    for(auto & v : B ){
      print_(v);
    }
    if( cor == 81 ){
      debug("returning true");
      for(auto & v : B ){
        print_(v);
      }
      return true;
    }
    int x = cor / 9, y = cor % 9;
    int z = cor2subidx(x,y);
    debug("cor,x,y,z",cor,x,y,z, B[x][y]);
    if( B[x][y] != '.' ) return  solve(cor+1, B, row_pos, col_pos, sub_pos);
    set<int> tmp_pos, cur_pos; // = row_pos && col_pos && sub_pos
    set_intersection(all(row_pos[x]), all(col_pos[y]), inserter(tmp_pos, tmp_pos.begin()));
    set_intersection(all(tmp_pos), all(sub_pos[z]), inserter(cur_pos, cur_pos.begin()));
    debug("cor,x,y,z",cor,x,y,z, B[x][y]);
    print_(cur_pos);
    if( cur_pos.empty() ) return false;
    for(auto v : cur_pos){
      B[x][y] = char('0'+v+1);
      row_pos[x].erase(v);
      col_pos[y].erase(v);
      sub_pos[z].erase(v);
      debug("try x y = ", B[x][y]);
      if( solve(cor+1, B, row_pos, col_pos, sub_pos) ) return true;
      row_pos[x].insert(v);
      col_pos[y].insert(v);
      sub_pos[z].insert(v);
    }
    B[x][y]='.';
    return false;
  }

  public:
    void solveSudoku(vector<vector<char>>& board) {
      v.resize(9);
      vii sub; forall(i,0,9){ sub.pb(mp(i/3*3,i%3*3));}
      vector<set<int>> row_pos(9), col_pos(9), sub_pos(9);
      forall(i,0,9){
        vi u = get_row_binary(i,board);
        forall(t,0,9){
          if( ! u[t] ) row_pos[i].insert(t);
        }
      }
      forall(j,0,9){
        vi u = get_col_binary(j,board);
        forall(t,0,9){
          if( ! u[t] ) col_pos[j].insert(t);
        }
      }
      forall(k,0,9){
        vi u = get_sub_binary(sub[k], board);
        debug("sub pos ",k);
        print_(u);
        forall(t,0,9){
          if( ! u[t] ) sub_pos[k].insert(t);
        }
      }
      solve(0,board, row_pos, col_pos, sub_pos) ;
    }
};
int main( int argc, char * argv[] ){
  vvc board(9, vc(9));
  for(auto & v : board ) input(v);
  Solution sol;
  sol.solveSudoku(board);
  for(auto & v : board ){
    print_(v);
  }
  return 0;
}
