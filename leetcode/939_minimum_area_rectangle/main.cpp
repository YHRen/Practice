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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
      int n = points.size(); if( n < 4 ) return 0;
      map<int,set<int>> x_loc;
      forall(i,0,n){
        auto p = points[i];
        auto x = p[0], y = p[1];
        x_loc[x].insert(y);
      }
      vector<pair<int,set<int>>> v;
      for(auto p : x_loc){ if( p.second.size() > 1 ) v.pb( p ); }
      if( v.empty() ) return 0;
      int m = v.size();
      int min_area = INF;
      forall(i,0,m){
        forall(j,i+1,m){
        int x1 = v[i].first;
        int x2 = v[j].first;
        int yy_low = -1, yy_high = -1;
        for(auto y1: v[i].second ){
          if( v[j].second.find(y1) != v[j].second.end() ){
            if( yy_low == -1 ) yy_low = y1;
            else{
              int tmp = (x2-x1)*(y1-yy_low);
              min_area = min(tmp, min_area);
              yy_low = y1;
            }
          }
        }
        }
      }
      if( min_area == INF ) return 0;
      else return min_area;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
