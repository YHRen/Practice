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
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      vi v = arr;
      sort(all(v));
      debug("v:");
      print_(v);
      unordered_map<int, deque<int>> pos_dict;
      forall(i,0,n){ 
        pos_dict[v[i]].pb(i);
      }

      vi mark(n, -1);
      int color = 0;
      forall(i,0,n){
        debug("i=",i, "color = ", color);
        debug("mark");
        print_(mark);
        int idx = find(arr.begin()+i, arr.end(), v[i]) - arr.begin();
        if( mark[i] == -1 ){
          if( idx != i ){
            for( int j = i; j <= idx; ++j ){
              debug("j=",j,"idx =",idx, arr[j], i);
              auto & dp = pos_dict[arr[j]];
              if( !dp.empty() ){;
                int p = dp.front(); dp.pop_front();
                if( p > idx ) idx = p;
                debug("p=",p);
              }
              mark[j] = color;
            }
          }else{
            mark[i] = color;
            pos_dict[v[i]].pop_front();
          }
          color++;
        }
      }
      return color;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.maxChunksToSorted(v) << '\n';

  return 0;
}
