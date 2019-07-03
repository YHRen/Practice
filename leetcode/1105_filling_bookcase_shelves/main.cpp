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
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
      const int n = sz(books), W = shelf_width;
      vi dp(n+1,INF);
      dp[0] = 0;
      forall(i,0,n){
        dp[i+1] = dp[i] + books[i][1];
        int w = books[i][0];
        int max_H = books[i][1];
        for(int j = i-1; j >= 0; --j ){
          w += books[j][0];
          if( w > W ) break;
          max_H = max(max_H, books[j][1]);
          dp[i+1] = min(dp[i+1], dp[j]+max_H);
        }
      }
      print_(dp);
      return dp.back();
    }
};
int main( int argc, char * argv[] ){
  int n,w; cin >> n >> w; 
  vvi mtx(n,vi(2));
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.minHeightShelves(mtx, w) << endl;
  return 0;
}
