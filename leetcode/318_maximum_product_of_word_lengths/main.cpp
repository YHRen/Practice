// #include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
  vii L;
  int to_int( const string & str ){
    int ans = 0;
    for( const char & c : str ){
      ans |= (1<< ( c-'a' ) );
    }
    return ans;
  }

  public:
    int maxProduct(vector<string>& words) {
      if( words.size() <= 1 ) return 0;
      for( auto & str : words ){
        int code = to_int(str) ;
        L.pb( mp( str.length(), code ) );
      }
      int ans = 0;
      int n = words.size();
      sort(all(L), greater<ii>());
      forall(i,0,n){
        forall(j,i+1,n){
          int tmp = L[i].first*L[j].first;
          if( tmp <= ans ) break;
          if( ( L[i].second & L[j].second ) == 0 ) ans = tmp;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vector<string> v(n); input(v);
  Solution sol;
  cout << sol.maxProduct( v ) << '\n';

  return 0;
}
