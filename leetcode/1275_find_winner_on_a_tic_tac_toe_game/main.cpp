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
  bool if_win(vvi & mtx, int player){
    forall(i,0,3){
      if( all_of( all(mtx[i]), [&](int x){ return x== player; } ) ) {
        return true;
      }
    }
    forall(j,0,3){
      bool flag = true;
      forall(i,0,3){
        if( mtx[i][j] != player ){
          flag = false;
          break;
        }
      }
      if(flag) return true;
    }
    bool flag = true;
    forall(i,0,3){
      if( mtx[i][i] != player ){
        flag = false;
        break;
      }
    }
    if( flag) return true;
    flag = true;
    forall(i,0,3){
      trace(player, 2-i, i, mtx[2-i][i]);
      if(mtx[2-i][i] != player ){
        flag =false;
        break;
      }
    }
    if(flag) return true;
    return false;
  }

public:
    string tictactoe(vector<vector<int>>& moves) {
      vvi mtx(3, vi(3, 0));
      int n = sz(moves);
      for(int i = 0; i < n; i++){
        int x = moves[i][0], y = moves[i][1];
        trace(x,y);
        if( i%2 == 0 ){ //place 1
          mtx[x][y] = 1;
        }else{
          mtx[x][y] = 2;
        }
      }
      for(auto & v : mtx){
        print_(v);
      }
      if( if_win(mtx, 1) ) return "A";
      if( if_win(mtx, 2) ) return "B";
      bool flag = true;
      forall(i,0,3) forall(j,0,3) if(mtx[i][j]==0){
        flag = false;
      }
      if( flag ) return "Draw";
      return "Pending";
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi v(n, vi(2));
  for(auto & x : v) input(x);
  Solution sol;
  cout << sol.tictactoe(v) << endl;
  return 0;
}
