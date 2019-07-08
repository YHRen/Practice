#include <vector>
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

class Solution {
  public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      priority_queue< vi > pq;
      sort(all(bookings));
      for(auto & v : bookings ){
        print_(v);
      }

      int cur = 0;
      int l   = 0, m = sz(bookings);
      vi res(n);
      forall(i,1,n+1){
        debug("i=",i);
        debug("cur=",cur);
        while( !pq.empty() and -pq.top()[0] < i ){
          cur -= pq.top()[1];
          pq.pop();
        }
        debug("cur=",cur, "l=",l);
        while( l < m and bookings[l][0] <= i and bookings[l][1] >= i ){
          cur += bookings[l][2];
          pq.push( {-bookings[l][1], bookings[l][2]} );
          ++l;
        }
        debug("cur=",cur);
        res[i-1] = cur;
      }

      return res;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vvi mtx(n, vi(3)); for(auto & v : mtx ) input(v);
  Solution sol;
  auto res = sol.corpFlightBookings(mtx, m);
  print_(res);
  return 0;
}
