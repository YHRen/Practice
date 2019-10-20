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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      int n = sz(startTime);
      if( n == 1 ) return profit.front();
      vi ord(n); iota(all(ord),0);
      sort(all(ord), [&](int x, int y){
          if( endTime[x] < endTime[y] ) return true;
          else if( endTime[x] == endTime[y] and profit[x] > profit[y] ) return true;
          else return false;
          });
      vii ans;
      for(auto idx : ord){
        if(ans.empty()) ans.pb(mp(endTime[idx], profit[idx]));
        else{
          auto itr = upper_bound(all(ans), mp(startTime[idx],INF));
          if( itr == ans.begin() ){
            if( itr->second >= profit[idx] ) continue;
            else if( itr->first == endTime[idx] ){
              itr->second = profit[idx];
            }else{
              if( profit[idx] > ans.back().second )
                ans.pb(mp(endTime[idx], profit[idx]));
            }
          }else{
            --itr; 
            assert(itr->first <= startTime[idx]);
            auto new_profit = itr->second + profit[idx];
            if( ans.back().first == endTime[idx] ){
              ans.back().second = max( ans.back().second, new_profit );
            }else if( ans.back().second < new_profit ){
              ans.pb(mp(endTime[idx], new_profit));
            }
          }
        }
      }
      return ans.back().second;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  vi u(n); input(u);
  vi w(n); input(w);
  Solution sol;
  cout << sol.jobScheduling(v,u,w) << endl;
  return 0;
}
