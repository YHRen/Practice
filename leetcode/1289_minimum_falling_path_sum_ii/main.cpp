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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
      int n = sz(arr); if( n == 1 ) return arr[0][0];
      auto k = min_element(all(arr[0])) - arr[0].begin();
      forall(i,1,n){
        forall(j,0,n){
          if( j!=k ) arr[i][j] += arr[i-1][k];
          else{
            int tmp_min = INF;
            forall(w, 0, n) {
              if (w != j and arr[i - 1][w] < tmp_min) tmp_min = arr[i - 1][w];
            }
            arr[i][j] += tmp_min;
          }
        }
        k = min_element(all(arr[i])) - arr[i].begin();
      }
      return *min_element(all(arr[n-1]));
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vvi mtx(n, vi(n)); 
  for(auto & v : mtx) input(v);
  Solution sol;
  cout << sol.minFallingPathSum(mtx) << endl;
  return 0;
}
