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

typedef vector<int>         vi;
typedef pair<int,int>       ii;
typedef vector<vi>          vvi;
typedef vector<ii>          vii;
typedef long long           ll;
typedef unsigned long long  ull;

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
  int find_subarray_sum( vector<int> & arr, int k ){
    ll ans = 0, run = 0;
    if( k == 1 ){
      forall(i,0,sz(arr)){
        run += arr[i];
        ans = max(ans, run);
        run = max(run, 0LL);
      }
      return ans%INF;
    }else{ // k > 2 
      int n = sz(arr);
      forall(i,0,2*n){
        run += arr[i%n];
        ans = max(ans, run);
        run = max(run, 0LL);
      }
      return ans%INF;
    }
  }
  
  public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
      int n = sz(arr);
      ll tot = accumulate(all(arr),0);
      if( tot <= 0 or k <= 2 ){
        return find_subarray_sum(arr, k);
      }else{// tot > 0  and k > 2
        int min_a = 0, run = 0, min_b = 0;
        forall(i,0,n){
          run += arr[i];
          min_a = min(min_a, run);
        }
        run = 0;
        for(int i=n -1; i >=0 ; --i ){
          run += arr[i];
          min_b = min(min_b, run);
        }
        ll ans = 0;
        forall(i,0,k){
          ans += tot;
          ans %= INF;
        }
        ans = ans - min_a - min_b ;
        ans %= INF;
        return ans;
      }
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
