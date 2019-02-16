#include <vector>
#include <set>
#include <map>
#include <regex>
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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
  int n;
  string str;
  int find_closing(int i){
    stack<int> s;
    s.push( str[i++] );
    while( !s.empty() and i < n ){
      if( str[i] == ')' ){
        s.pop();
        i++;
      }
      else s.push(i++);
    }
    return i;
  }


  int solve(int left ){

    if( left == n or str[left] == ')' ) return 0;
    int right = find_closing(left);
    debug("left ", left , "right=",right);
    if( right - left  - 1 == 1 ) return 1 + solve(right);
    else return 2*solve( left + 1 ) + solve(right);
  }
public:
    int scoreOfParentheses(string S) {
    n = S.size();
    str=S;
    return solve(0);
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.scoreOfParentheses(str) << '\n';

  return 0;
}

/*
Given a balanced parentheses string S, compute the score of the string based on the following rule:

    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

 

Example 1:

Input: "()"
Output: 1

Example 2:

Input: "(())"
Output: 2

Example 3:

Input: "()()"
Output: 2

Example 4:

Input: "(()(()))"
Output: 6

*/
