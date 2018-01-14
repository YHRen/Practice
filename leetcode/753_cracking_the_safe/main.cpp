// #include <bits/stdc++.h>
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
  string ans;
  unordered_set<string> track;
  int goal, n, k;
  bool dfs( int idx ){
    if( idx == goal ) return true;
    auto prv = ans.substr( ans.size() + 1 - n );
    forall(i,0,k){
      auto cur = prv + to_string(i);
      if( track.count(cur) == 0 ){
        ans += to_string(i);
        track.insert(cur);
        if( dfs( idx+1 ) ) return true;
        ans.pop_back();
        track.erase(cur);
      }
    }
    return false;
  }

  public:
    string crackSafe(int n, int k) {
      if( n == 1 && k == 1 ) return "0";
      ans = "";
      goal = pow(k,n);
      this->n = n;
      this->k = k;
      forall(i,0,n-1){ ans += '0'; }
      dfs( 0 );
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,k; cin >> n >> k;
  Solution sol;
  cout << sol.crackSafe(n,k) << '\n';

  return 0;
}
