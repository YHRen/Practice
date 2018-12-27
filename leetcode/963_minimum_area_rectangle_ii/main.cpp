#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
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
  bool is_right( double dx1, double dy1, double dx2, double dy2 ){
    return abs(dx1*dx2 + dy1*dy2) < EPS;
  }
  bool is_parapllel( double dx1, double dy1, double dx2, double dy2){
    return abs(dy1*dx2 - dy2*dx1) < EPS;
  }
  double area( double dx1, double dy1, double dx2, double dy2){
    double l1 = sqrt((dx1*dx1+dy1*dy1));
    double l2 = sqrt((dx2*dx2+dy2*dy2));
    return l1*l2;
  }
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
      int n = points.size();
      // find all right-angle corners share the same diagonal line
      map<ii, vi > ridx;
      forall(i,0,n){
        double x = points[i][0], y = points[i][1];
        forall(j,0,n){
          if( j == i ) continue;
          double dx1 = points[j][0] - x, dy1 = points[j][1] - y;
          forall(k,j+1,n){
            if( k == i ) continue;
            double dx2 = points[k][0] - x, dy2 = points[k][1] - y;
            if( is_right(dx1, dy1, dx2, dy2) ){
              ridx[mp(j,k)].pb(i);
            }
          }
        }
      }
      double ans = INF;
      for(auto p : ridx){
        int m = p.second.size();
        if( m >= 2 ){
          int i = p.first.first, j = p.first.second;
          double x1 = points[i][0], y1 = points[i][1];
          double x2 = points[j][0], y2 = points[j][1];
          const auto & u = p.second;
          forall(k, 0, m){
            forall(l, k+1, m){
              double dx1 = points[u[k]][0] - x1;
              double dy1 = points[u[k]][1] - y1;
              double dx2 = points[u[l]][0] - x2;
              double dy2 = points[u[l]][1] - y2;
              if( is_parapllel( dx1, dy1, dx2, dy2 ) ){
                double dx3 = points[u[l]][0] - x1;
                double dy3 = points[u[l]][1] - y1;
                double a = area( dx1, dy1, dx3, dy3);
                if( ans > a ){
                  ans = min( ans,a );
                }
              }
            }
          }
        }
      }
      if( ans == INF ) return 0;
      else return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vvi p(n, vi(2));
  for( auto & v : p ){ 
    input(v);
  }
  Solution sol;
  cout << sol.minAreaFreeRect(p) << '\n';

  return 0;
}
