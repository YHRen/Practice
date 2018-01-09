#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// 386. Lexicographical Numbers
//https://leetcode.com/problems/lexicographical-numbers/
// Given an integer n, return 1 - n in lexicographical order.
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.
//
//
class Solution {
  private:
    void lexic_aux( int n, vector<int> & rst, const int N ){
      debug(n);
      if( n != 0 ){
        rst.push_back(n); 
        if( 10*n <= N ){
          lexic_aux( 10*n, rst, N );
        }
      }
      for( int i = 1; i < 10; ++i ){
        if( n+i <= N ){
          rst.push_back( n+i );
          if( 10*(n+i) <= N ){
            lexic_aux( 10*(n+i), rst, N );
          }
        }
      }
    }
  public:
    vector<int> lexicalOrder(int n) {
      vector<int> rst;
      if( n <=0 ) return rst;
      //rst.push_back(1);
      lexic_aux( 0, rst, n );
      return rst;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  Solution s;
  auto v = s.lexicalOrder(n);
  print_(v);
  return 0;
}
