#include <vector>
#include <random>
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

random_device rd;
mt19937 rng(rd());

class Solution {
  int n;
  int eval(const vi & v){
    int s = v[0];
    forall(i,1,n){
      s = abs(v[i]-s);
    }
    return s;
  }
  
public:
    int lastStoneWeightII(vector<int>& stones) {
      n = sz(stones);
      vector<bool> dp(3001,0);
      dp[0] = 1;
      int tot = accumulate(all(stones),0);
      for(auto x : stones){
        for(int j = tot-x; j>=0; --j){
          dp[j+x] = dp[j+x] | dp[j];
        }
      }
      int res = 100;
      forall(i,1,3001){
        if( dp[i] ){
        res = min(res, abs(tot-i-i));
        }
      }
      return res;
    }
    int lastStoneWeightII_rand(vector<int>& stones) {
      n = sz(stones);
      if(n==1) return stones[0];
      if(n==2) return abs(stones[0]-stones[1]);

      int res = 100;
      forall(_,0,10000){
        if( res == 0 ) return res;
        shuffle(all(stones), rng);
        res = min(res, eval(stones));
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  cout << sol.lastStoneWeightII(v) << endl;
  return 0;
}
