#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
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
//467. Unique Substrings in Wraparound String 
//https://leetcode.com/problems/unique-substrings-in-wraparound-string/
//Consider the string s to be the infinite wraparound string of
//"abcdefghijklmnopqrstuvwxyz", so s will look like this:
//"...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
//
//Now we have another string p. Your job is to find out how many unique
//non-empty substrings of p are present in s. In particular, your input is the
//string p and you need to output the number of different non-empty substrings
//of p in the string s.
//
//Note: p consists of only lowercase English letters and the size of p might be over 10000.
//
//Example 1:
//
//Input: "a"
//Output: 1
//
//Explanation: Only the substring "a" of string "a" is in the string s.
//
//Example 2:
//
//Input: "cac"
//Output: 2
//Explanation: There are two substrings "a", "c" of string "cac" in the string s.
//
//Example 3:
//
//Input: "zab"
//Output: 6
//Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
//
class Solution {
  public:
    int findSubstringInWraproundString(string p) {
      if( p.empty() ) return 0;
      int cnt = 0;
      vector<int> maxlen( 26, 0 );
      maxlen[ p[0] - 'a' ] = 1;
      int len = 1;
      for( int i = 1; i < p.size(); ++i ){
        int idx = p[i] - 'a';
        if( p[i] - p[i-1] == 1 || (p[i-1]=='z' && p[i]=='a') ){
          len ++;
          maxlen[idx] = max( maxlen[idx], len );
        }else{
          len = 1;
          maxlen[idx] = max( maxlen[idx], len );
        }
      }
      return accumulate( maxlen.begin(), maxlen.end(), 0 );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  string str; cin >> str;
  Solution s;
  cout << s.findSubstringInWraproundString( str ) << '\n';

  return 0;
}
