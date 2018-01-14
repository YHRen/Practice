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
  int k;
  vi  v;
  public:
  void solve(){
    print_(v);
    int stop = k;
    for( int i = stop-1; i > 0; --i ){
      if( v[i] > v[k] ) break;
      if( v[i] < v[i+1] ) stop = i;
      if( v[i-1] > v[i] ){ break; }
    }
    debug("stop left = ", stop, v[stop], v[k]);
      
    if( stop == k ){
      for( int i = stop + 1; i < v.size(); ++i ){
        if( v[i] > v[k] ) break;
        if( v[i] < v[i-1] ) stop = i;
        if( v[i+1] > v[i] ) { break; }
      }
    debug("stop right = ", stop, v[stop], v[k]);
    }
    v[stop] ++;
  }
   vector<int> pourWater(vector<int>& heights, int V, int K) {
     int n = heights.size();
     this->v.resize(n + 2);
     v[0] = v.back() = INF;
     copy( all(heights), v.begin()+1);
     this->k = K+1;
     while (V--) {
       solve();
     }
     return vi( v.begin()+1, v.end()-1 );
   }
};
int main( int argc, char * argv[] ){
  int n,V, K; cin >> n >> V >> K;
  vi v(n); input(v);
  print_(v);
  Solution sol;
  auto ans = sol.pourWater(v, V, K);
  print_(ans);


  return 0;
}
