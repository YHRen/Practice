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
    bool is_possible( const string & S, const string & T ){
      if( S.size() != T.size() ) return false;
      int n = S.size();
      int c1[3] = {0,0,0}, c2[3]={0,0,0};
      {
        auto & V = S;
        auto & c = c1;
        forall(i,0,n){
          if( V[i] == 'X' ) c[0]++;
          else if( V[i] == 'L' ) c[1] ++;
          else if( V[i] == 'R' ) c[2] ++;
        }
      }
      {
        auto & V = T;
        auto & c = c2;
        forall(i,0,n){
          if( V[i] == 'X' ) c[0]++;
          else if( V[i] == 'L' ) c[1] ++;
          else if( V[i] == 'R' ) c[2] ++;
        }
      }
      forall(i,0,3){
        if( c1[i] != c2[i] ) return false;
      }
      return true;
    }
        
  public:
    bool canTransform(string start, string end) {
      if( !is_possible(start, end) ) return false;
      int n = start.size();
      int T = 1000;
      while(T-->0 && start != end ){
      for(int i = 0; i < n-1; ++i ){
        if( start[i] == end[i] ) continue;
        if( start[i] == 'X' && start[i+1] == 'L' && end[i] == 'L' ){
          swap(start[i], start[i+1]);
        }else if( start[i] == 'R' && start[i+1] == 'X' && end[i] == 'X' ){
          swap(start[i], start[i+1]);
        }
      }
      for( int i = n-1; i > 0; --i ){
        if( start[i] == end[i] ) continue;
        if( start[i] == 'X' && start[i-1] == 'R' && end[i] == 'R' ){
          swap(start[i],start[i-1]);
        }else if( start[i] =='L' && start[i-1] == 'X' && end[i] == 'X' ){
          swap(start[i], start[i-1]);
        }
      }
      }
      debug(start);
      debug(end);
      return start == end;
    }
};
int main( int argc, char * argv[] ){

//  string S = "RXXLRXRXL";
//  string T = "XRLXXRRLX";

  string S,T; cin >> S >> T;
  Solution sol;
  cout << sol.canTransform(S,T) << '\n';

  return 0;
}
