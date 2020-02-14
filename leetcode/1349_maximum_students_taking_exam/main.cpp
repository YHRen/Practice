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
typedef vector<char>     vc;
typedef vector<vc>       vvc;
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
  int n,m,ans;
  vvi dp;

  bool is_feasible( const vc & row ){
    forall(i,0,m-1) 
      if( row[i] == 'x' and row[i] == row[i+1]) 
        return false;
    return true;
  }
  int get_current_state( const vc & row ){
    int res = 0;
    forall(i,0,m-1){
      if( row[i] == 'x' )
        res += (1<<i);
    }
    return res;
  }
  void solve(int row, vector<vector<char>> & seats, int cur){
    trace(row, cur);
    if( row == n ){ ans = max(ans, cur); return;}
    int max_pos = count_if( all(seats[row]), [](char c){ return c != '#'; });
    trace(max_pos);
    vector<bool> bit_mask(max_pos, false);
    for(int s = max_pos; s >=0; s--){
      bit_mask.assign(max_pos, false);
      for(int j = 0; j < s; ++j){
        bit_mask[max_pos-j-1] = true;
      }
      trace(s);
      do{
        vector<char> cur_row = seats[row];
        for(int j = 0, idx = 0; j < m; ++j){
          if( cur_row[j] == '.' ){
            if( bit_mask[idx++] ){
              cur_row[j] = 'x';
            }
          }
        }
        debug("cur_row");
        print_(cur_row);
        if( !is_feasible( cur_row ) ) continue;
        int state = get_current_state(cur_row);
        if( dp[row][state] >= cur + s ) continue;
        else dp[row][state] = cur+s;

        auto nxt_seats = seats;
        if( row < n-1 ){
          forall(j,0,m){
            if( cur_row[j] == 'x' ){
              if( j>0 ) nxt_seats[row+1][j-1] = '#';
              if( j<m-1 ) nxt_seats[row+1][j+1] = '#';
            }
          }
        }
        solve(row+1, nxt_seats, cur+s);
        
      }while(next_permutation(all(bit_mask)));
    }
    return;
  }


  public:
    int maxStudents(vector<vector<char>>& seats) {
      n = sz(seats), m = sz(seats[0]);
      dp.resize(n); for(auto & v : dp) v.resize(1<<m,-1);
      ans = 0;
      solve(0, seats, 0);
      return ans;
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m;
  vvc mtx(n, vc(m));
  for(auto & v : mtx) input(v);
  for(auto & v : mtx){
    print_(v);
  }
  Solution sol;
  cout << sol.maxStudents(mtx) << endl;
  return 0;
}
