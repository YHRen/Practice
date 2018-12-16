#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bitset>
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
  int n,m;
  vector<string> B;
  bool C( string & lhs, string & rhs ){
    forall(i,0,n){ 
      if( lhs[i] <= rhs[i] ) continue;
      else return false;
    }
    return true;
  }
public:
    int minDeletionSize(vector<string>& A) {
      n = A.size();
      m = A[0].size();
      B.resize(m);
      forall(j,0,m){ forall(i,0,n){ B[j].pb(A[i][j]); } }
      print_(B);

      vii tail;
      tail.pb(mp(0,1));
      vi dp(m, 1);
      forall(i,1,m){
        forall(j,0,i){
          if( C( B[j], B[i] ) ){
            dp[i] = max(dp[i], dp[j]+1);
          }
        }
      }
      print_(dp);

      return m - *max_element(all(dp));
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vector<string> A(n);
  input(A);
  Solution sol;
  cout << sol.minDeletionSize(A) << '\n';

  return 0;
}
