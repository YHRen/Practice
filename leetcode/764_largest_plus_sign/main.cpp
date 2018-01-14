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
// https://leetcode.com/contest/weekly-contest-67/problems/largest-plus-sign/
class Solution {
  vector<vector<char>>  board;

  public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
      if( mines.empty() ) return (N+1) / 2;
      board.resize(N);
      for(auto & row : board ) row.resize(N,1);
      for( const auto & p : mines ){ board[p[0]][p[1]] = 0; }

      vvi dp( N, vi(N, INF));
      int tmp ;
      forall(i,0,N){
        tmp = 0;
        forall(j,0,N){
          if( board[i][j] == 1 ){
            dp[i][j] = min(++tmp, dp[i][j]);
          }else{
            tmp = 0;
          }
        }
      }
      forall(i,0,N){
        tmp = 0;
        for(int j = N-1; j >= 0; --j ){
          if( board[i][j] == 1 ){
            dp[i][j] = min(++tmp, dp[i][j]);
          }else{
            tmp = 0;
          }
        }
      }
      forall(j,0,N){
        tmp = 0;
        for(int i = N-1; i >= 0; --i ){
          if( board[i][j] == 1 ){
            dp[i][j] = min(++tmp, dp[i][j]);
          }else{
            tmp = 0;
          }
        }
      }
      forall(j,0,N){
        tmp = 0;
      forall(i,0,N){
          if( board[i][j] == 1 ){
            dp[i][j] = min(++tmp, dp[i][j]);
          }else{
            tmp = 0;
          }
        }
      }
      int ans = 0;
      forall(i,0,N){
      tmp = 0;
        forall(j,0,N){
          if( board[i][j] ){
            ans = max(dp[i][j], ans);
          }
        }
      }
      for(auto r : dp ){
        print_(r);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int N; cin >> N;
  int n; cin >> n;
  vvi v(n, vi(2));
  for( auto & r : v ) input(r);
  Solution sol;
  cout << sol.orderOfLargestPlusSign(N, v ) << '\n';

  return 0;
}
