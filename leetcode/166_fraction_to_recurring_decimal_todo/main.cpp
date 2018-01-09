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
// https://leetcode.com/problems/fraction-to-recurring-decimal/ 
// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
// If the fractional part is repeating, enclose the repeating part in parentheses.
//
// For example,
//
//  Given numerator = 1, denominator = 2, return "0.5".
//  Given numerator = 2, denominator = 1, return "2".
//  Given numerator = 2, denominator = 3, return "0.(6)".
//
class Solution {
  private:
    void count_2_and_5( int & d, int & cnt2, int & cnt5 ){
      cnt2 = 0, cnt5 = 0;
      while( d%2 == 0 ){
        ++cnt2;
        d /= 2;
      }
      while( d%5 == 0 ){
        ++cnt5;
        d /= 5;
      }
    }
    string to_str( int n, int d ){
      string rst = to_string( static_cast<double>(n) / d );
      rst.erase( rst.find_last_not_of('0')+1, std::string::npos );
      if( rst.back() == '.' ) rst.erase( rst.end()-1, rst.end() );
      return rst;
    }
    string to_str( int numerator, int cnt2, int cnt5 ){
        string rst = to_string( static_cast<double>(numerator) / pow( 2, cnt2 ) / pow( 5, cnt5 ) );
        rst.erase ( rst.find_last_not_of('0') + 1, std::string::npos );
        if( rst.back() == '.' ) rst.erase( rst.end()-1, rst.end() );
        return rst;
    }
  public:
    string fractionToDecimal(int numerator, int denominator) {
      if( denominator == 0 ) return "inf";
      int cnt2, cnt5;
      count_2_and_5( denominator, cnt2, cnt5 );
      if( denominator == 1 ){
        return to_str( numerator, cnt2, cnt5 );
      }else if( numerator % denominator == 0 ){
        numerator /= denominator;
        return to_str( numerator, cnt2, cnt5 );
      }
      string termi = to_string( static_cast<double>(numerator) / pow( 2, cnt2 ) / pow( 5, cnt5 ) / denominator );
      debug( termi );
      return "x";



    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,d; cin >> n >> d;
  Solution s;
  cout << s.fractionToDecimal(n,d) << '\n';




  return 0;
}
