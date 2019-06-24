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
    vector<double> sampleStats(vector<int>& count) {
      vector<double> ans(5);
      forall(i,0,256){
        if( count[i] != 0 ){ 
          ans[0] = i;
          break;
        }
      }
      for(int i = 255; i>= 0 ; --i ){
        if( count[i] != 0 ){
          ans[1] = i;
          break;
        }
      }
      ll tot = 0;
      ll tot_cnt = 0;
      forall(i,0,256){
        if( count[i] ){
          tot += static_cast<ll>(i) * count[i];
          tot_cnt += count[i];
        }
      }
      ans[2] = static_cast<double>(tot)/tot_cnt;
      ans[4] = max_element(all(count))-count.begin();
      debug("tot_cnt", tot_cnt);

      if( tot_cnt % 2 == 1 ){ // odd num
        double cur = 0;
        double half = static_cast<double>(tot_cnt)/2;
        forall(i,0,256){
          cur += count[i];
          if( cur > half ){
            ans[3] = i;
            break;
          }
        }
      }else{ // even number
        ll cur  = 0;
        ll half = tot_cnt/2;
        debug("even num", "half=",half);
        forall(i,0,256){
          cur += count[i];
          if( cur == half ){
            forall(j,i+1,256){
              if( count[j] != 0 ){
                ans[3] = (static_cast<double>(i)+static_cast<double>(j))/2;
                return ans;
              }
            }
          }else if( cur > half){
            ans[3] = i;
            break;
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  auto res = sol.sampleStats(v);
  print_(res);
  return 0;
}
