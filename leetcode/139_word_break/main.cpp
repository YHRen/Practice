#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
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
  int n;
  string s;
  unordered_set<string> d;
  vvi dp;
  bool C( int pre, int idx ){
    if( idx == n ){
      if( d.count( s.substr(pre, idx-pre) ) ){
        return dp[pre][idx] = 1;
      }else{
        return dp[pre][idx] = 0;
      }
    }
    if( dp[pre][idx] != -1 ) return dp[pre][idx];
    string str = s.substr( pre, idx-pre );
    debug("pre,idx,str",pre,idx,str);
    bool flag = false;
    if( d.count(str) ){
      flag = C( idx, idx+1 );
    }
    return dp[pre][idx] =  flag | C( pre, idx+1 );
  }

  public:
    bool wordBreak(string str, vector<string>& dic) {
      n = str.size();
      s = str;
      for( auto & word : dic ) d.insert(word);
      dp.resize(n, vi(n+1, -1));
      return C(0,1);
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  string str; cin >> str;
  vector<string> v(n);
  for( auto & x : v ) cin >> x;
  print_(v);
  Solution sol;
  cout << sol.wordBreak( str, v ) << '\n';

  return 0;
}
