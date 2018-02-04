// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
/******* Actual Code Starts Here *********/
class Solution {
  private:
    int N,M;
    vi dp;
    vvi graph;
    const int Goal = bitset<32>("001010011100101000").to_ulong();
    bool is_goal(int x){ return x == Goal; }
    int encode(const vvi & board ){
      int ans = 0;
      forall(i,0,N){
        forall(j,0,M){
          ans |=  ((1<<3) - 1) & board[i][j];
          ans <<= 3;
        }
      }
      ans >>= 3;
      return ans;
    }
    int swap_position( const int & config, int pos1, int pos2 ){
      // pos1 is 0, and pos2 is where it goes.
      // set config[pos1] to config[pos2] and 
      // set config[pos2] to zero
      pos1 = 6 - pos1;
      pos2 = 6 - pos2;
      int res = config;
      int mask = ( ((1<<3)-1) << (3*(pos2-1)) );
      int x =  mask & config;
      res &= ~mask; // set config[pos2] to zero
      if( pos1 < pos2 ){
        x >>= 3*(pos2 - pos1);
      }else{
        x <<= 3*(pos1 - pos2);
      }
      res |= x;
      return res;
    }

    int find_zero(const vvi & board) {
      int res = 0;
      forall(i,0,N){
        forall(j,0,M){
          if( board[i][j] == 0 ) return res;
          else res++;
        }
      }
      return res;
    }
    vi decode( int config ){
      vi ans;
      int mask = (1<<3) -1 ;
      forall(_,0,6){
        ans.pb( config & mask );
        config >>= 3;
      }
      reverse(all(ans));
      return ans;
    }


  public:
    int slidingPuzzle(vector<vector<int>>& board) {
      N = board.size();
      M = board[0].size();
      dp.resize( (1<<18), -1 );
      graph = {{1,3}, {0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
      int cur = encode(board), idx;
      if( cur == Goal ) return 0;
      dp[cur] = 0;
      queue<ii> Q;
      debug("find-zero=",find_zero(board));
      Q.push( mp(cur, find_zero(board) ) );
      
      while( !Q.empty() ){
        auto p = Q.front(); Q.pop();
        cur = p.first;
        idx = p.second;
        for( auto u : graph[idx] ){
          debug("cur = ", cur, "at idx", idx, "swap", u);
          print_(decode(cur));
          int nxt = swap_position( cur, idx, u );
          print_(decode(nxt));
          if( nxt == Goal ){ return dp[cur] + 1; }
          if( dp[nxt] == -1 ){
            dp[nxt] = dp[cur] + 1;
            Q.push( mp( nxt, u) );
          }
        }
      }
      return -1;
    }

};
int main( int argc, char * argv[] ){
  Solution sol;
  vvi mtx(2, vi(3) );
  input(mtx[0]);
  input(mtx[1]);
  cout << sol.slidingPuzzle(mtx) << '\n';

  return 0;
}
