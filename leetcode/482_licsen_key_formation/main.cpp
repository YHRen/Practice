#include <vector>
#include <list>
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
// https://leetcode.com/contest/leetcode-weekly-contest-14/problems/license-key-formatting/
class Solution {
  public:
    string licenseKeyFormatting(string S, int K) {
      string str;
      if( K == 0 || S.empty() ) return str;
      vector<char> tmp;
      tmp.reserve(S.size());
      for( auto itr = S.begin(); itr != S.end(); ++itr ){
        if( *itr != '-' ){
          tmp.push_back( toupper(*itr) );
        }
      }
      list<char> rst;
      int idx = 1;
      for( auto itr = tmp.rbegin(); itr != tmp.rend(); ++itr ){
        rst.push_front(*itr);
        if( idx % K == 0 ){
          rst.push_front('-');
        }
        idx++;
      }
      if( rst.front() == '-' ) rst.pop_front();
      return string( rst.begin(), rst.end() );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int k; cin >> k;
  string str; cin >> str;
  Solution s;
  cout << s.licenseKeyFormatting( str, k ) << '\n';




  return 0;
}
