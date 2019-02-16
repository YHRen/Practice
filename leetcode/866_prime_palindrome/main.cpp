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
  bool is_prime(int x){
    if( x < 2 || x%2==0 ) return x==2;
    for(int i = 3; i*i <= x; i += 2){
      if( x%i==0 ) return false;
    }
    return true;
  }

  int genP(int x, bool is_odd){
    string str = to_string(x);
    str = str + string(str.rbegin()+(is_odd?1:0), str.rend() );
    return stoi(str);
  }
  
  public:
    int primePalindrome(int N) {
      if ( N == 1 or N == 2 ) return 2;
      int cur=0, odd=1, evn=1;
      int p = genP(odd,1);
      int q = genP(evn,0);
      while( cur < N or !is_prime(cur) ){
        if( p < q ){ cur = p; p = genP(++odd,1);}
        else{ cur = q; q = genP(++evn,1); }
      }
      return cur;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  Solution sol;
  cout << sol.primePalindrome(n) << '\n';

  return 0;
}

/*
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.

 

Example 1:

Input: 6
Output: 7

Example 2:

Input: 8
Output: 11

Example 3:

Input: 13
Output: 101

 

Note:

    1 <= N <= 10^8
    The answer is guaranteed to exist and be less than 2 * 10^8.

*/
