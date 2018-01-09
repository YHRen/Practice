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
typedef pair<double,double> dd;
class Solution {
  private:
    double midx,midy,dist;
    dd major;
    bool C( ii p ){
      debug("testing",p.first,p.second);
      double dx = p.first - midx;
      double dy = p.second - midy;
      double d = sqrt( dx*dx + dy*dy );
      debug(dx,dy,d);
      if( abs(dist-d) > EPS ) return false;
      if( abs( major.first * dx + major.second * dy ) > EPS ) return false;
      return true;
    }

  public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
      if( p1.size() < 2 || p2.size() < 2 || p3.size() < 2 || p4.size() < 2 ) return false;
      vii pnt = { mp(p1[0], p1[1]), mp(p2[0],p2[1]), mp(p3[0],p3[1]), mp(p4[0],p4[1]) };
      sort( all(pnt) );
      if( unique(all(pnt)) != pnt.end() ) return false;
      double dx = pnt[3].first - pnt[0].first;
      double dy = pnt[3].second - pnt[0].second;
      major = mp( dx,dy );
      dist = sqrt( dx * dx + dy * dy )/2; 
      midx = dx/2+pnt[0].first;
      midy = dy/2+pnt[0].second;
      debug( dx, dy, midx, midy );
      return C(pnt[1]) && C(pnt[2]);
    }
};
int main( int argc, char * argv[] ){
  vi p1(2), p2(2), p3(2), p4(2);
  cin >> p1[0] >> p1[1];
  cin >> p2[0] >> p2[1];
  cin >> p3[0] >> p3[1];
  cin >> p4[0] >> p4[1];
  Solution sol;
  cout << sol.validSquare(p1, p2, p3, p4) << '\n';

  return 0;
}
