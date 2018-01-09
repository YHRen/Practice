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
// Given a list of non negative integers, arrange them such that they form the largest number.
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// solution: reverse lexicographic order, radix sort maybe even faster
class Solution {
  private:
    // order numbers based on their most significant digits.
    // i.e. 94 > 34 (as 94x > 34x ) and 9 > 94 ( as 994 > 949 )
    struct cmp{
      bool operator() ( string x, string y ){ 
        if( x.empty() || y.empty() ){
          return false;
        }
        bool flipped = false;
        if( x.length() > y.length() ){
          swap(x,y);
          flipped = true;
        }
        for(int i = 0; i < x.length() && i < y.length(); ++i ){
          if( x[i] < y[i] ) return false^flipped;
          else if( x[i] > y[i] ) return true^flipped;
        }
        if( y.length() > x.length() ){
          cmp cmpter;
          return cmpter( x, y.substr( x.length(), y.length()-x.length()) ) ^ flipped;
        }else{ // equal
          return false;
        }
      }
    }cmpter;
  public:
    string largestNumber(vector<int>& nums) {
      vector<string> v;
      int cnt_zero = 0;
      for( const auto & x : nums ){
        if( x == 0 ) cnt_zero++;
        else v.push_back( to_string(x) );
      }
      sort( v.begin(), v.end(), cmpter );
      
      string rst; 
      for( const auto & x : v ){
        rst += x;
      }
      if( cnt_zero ){
        if( rst.empty() ) rst += '0';
        else rst += string( cnt_zero, '0' );
      }
      return rst;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> v(n);
  input(v);
  Solution s;
  cout << s.largestNumber( v ) << '\n';
  return 0;
}
