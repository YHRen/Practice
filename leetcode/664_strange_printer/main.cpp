#include <vector>
#include <regex>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
/*
There is a strange printer with the following two special requirements:

    The printer can only print a sequence of the same character each time.  At
    each turn, the printer can print new characters starting from and ending at
    any places, and will cover the original existing characters.

Given a string consists of lower English letters only, your job is to count the
minimum number of turns the printer needed in order to print it.

Example 1:

Input: "aaabbb" Output: 2 Explanation: Print "aaa" first and then print "bbb".

Example 2:

Input: "aba" Output: 2 Explanation: Print "aaa" first and then print "b" from
the second place of the string, which will cover the existing character 'a'.

Hint: Length of the given string will not exceed 100.
*/ 
class Solution {
  int dp[100][100];
  int n;
  string str;
  int aux( int x, int y, int dp[100][100] ){
    if( x > y ) return 0;
    if( x == y ) return 1;
    if( dp[x][y] != INF ) return dp[x][y];
    dp[x][y] = y-x+1;
    for(int i = x; i < y; ++i ){// split at i
      if( str[i] != str[x] ) continue;
      dp[x][y] = min(dp[x][y], aux(x, i, dp) + aux(i+1,y,dp) - (str[x]==str[y]));
    }
    return dp[x][y];
  }

public: 
    int strangePrinter(string s) {
      regex re("([a-z])\\1+");
      str.clear();
      regex_replace(back_inserter(this->str), all(s), re, "$1");
      n = sz(str);
      forall(i,0,n) forall(j,0,n) dp[i][j] = INF;
      return aux(0, n-1, dp);
    }
};

     // for(sregex_iterator itr(all(s),re); itr != sregex_iterator(); ++itr ){
     //   cout << itr->str() << endl;
     // }
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.strangePrinter(str) << endl;
  return 0;
}


/** solution 
The problem wants us to find the number of ways to do something without giving specific steps like how to achieve it. This can be a typical signal that dynamic programming may come to help.

dp[i][j] stands for the minimal turns we need for string from index i to index j.
So we have

    dp[i][i] = 1: we need 1 turn to paint a single character.
    dp[i][i + 1]
        dp[i][i + 1] = 1 if s.chartAt(i) == s.charAt(i + 1)
        dp[i][i + 1] = 2 if s.chartAt(i) != s.charAt(i + 1)

Then we can iteration len from 2 to possibly n. For each iteration, we iteration start index from 0 to the farthest possible.

    The maximum turns for dp[start][start + len] is len + 1, i.e. print one character each time.
    We can further divide the substring to two parts: start -> start+k and start+k+1 -> start+len. It is something as following:

    index |start  ...  start + k| |start + k + 1 ... start + len|
    char  |  a    ...       b   | |      c       ...      b     |

        As shown above, if we have s.charAt(start + k) == s.charAt(start + len), we can make it in one turn when we print this character (i.e. b here)
        This case we can reduce our turns to dp[start][start + k] + dp[start + k + 1][start + len] - 1

Complete codes are here

class Solution {
    public int strangePrinter(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        
        int n = s.length();
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (i < n - 1) {
                dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1) ? 1 : 2;
            }
        }
        
        for (int len = 2; len < n; len++) {
            for (int start = 0; start + len < n; start++) {
                dp[start][start + len] = len + 1;
                for (int k = 0; k < len; k++) {
                    int temp = dp[start][start + k] + dp[start + k + 1][start + len];
                    dp[start][start + len] = Math.min(
                        dp[start][start + len],
                        s.charAt(start + k) == s.charAt(start + len) ? temp - 1 : temp
                    );
                }
            }
        }
        
        return dp[0][n - 1];
    }
}

Time complexity is O(n^3)

Some simple optimization. Consecutive repeating characters do not affect our printing as we can always print them together. i.e aaabbb is equivalent with ab. So we can reduce the string first which somehow reduce n

StringBuilder sb = new StringBuilder();
for (int i = 0; i < s.length(); i++) {
    if (i > 0 && s.charAt(i) == s.charAt(i - 1)) {
        continue;
    }
    sb.append(s.charAt(i));
}
s = sb.toString();

This helps reduce running time from 60ms to 53ms.
**/
