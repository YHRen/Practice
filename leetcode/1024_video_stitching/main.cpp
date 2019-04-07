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
    int videoStitching(vector<vector<int>>& clips, int T) {
      vi v(101, -1);
      for(auto & x : clips ){
        v[x[0]] = max( v[x[0]], x[1] );
      }
      print_(v);
      if( v[0] == -1 ) return -1;

      int ans = 1;
      int right = v[0];
      int left = 1;
      if( right >= T ) return ans;
      do{
        int new_right = right;
        for(; left <= right; ++left){
          if( v[left] == -1 ) continue;
          new_right = max(new_right, v[left]);
        }
        if( new_right == right ) return -1;
        ans ++;
        left = right;
        right = new_right;
      }while(right < T);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vvi v(n, vi(2));
  for(auto & x : v ) input(x);
  Solution sol;
  cout << sol.videoStitching( v, m ) << '\n';
  return 0;
}
