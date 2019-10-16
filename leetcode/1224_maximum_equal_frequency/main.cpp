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
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
      int n = sz(nums);
      int ans = 1;
      vi cnt(100001,0);
      map<int,int> unq_cnt; // how many uniq elements with cnt X
      forall(i,0,n){
        if( cnt[nums[i]] == 0 ){
          unq_cnt[1] += 1;
        }else{
          int x = cnt[nums[i]];
          auto itr = unq_cnt.find(x);
          itr->second -= 1;
          unq_cnt[x+1] += 1;
          if( itr->second == 0 ){
            unq_cnt.erase(itr);
          }
        }
        cnt[nums[i]]++;

        debug("i=",i, unq_cnt.size());
        for(auto p : unq_cnt){
          debug(p.first, " has ", p.second, " unq elems");
        }
        if( unq_cnt.size() == 1 ){
          if( unq_cnt.begin()->second == 1 or unq_cnt.begin()->first == 1 ) ans = i+1;
          else ans = i;
        }else if( unq_cnt.size() == 2 ){
          debug(" int sz 2");
          if( unq_cnt.begin()->first == 1 and unq_cnt.begin()->second == 1 ){
            debug("first == 1");
            ans = i+1;
          }
          else if( unq_cnt.rbegin()->first  - unq_cnt.begin()->first  == 1  and unq_cnt.rbegin()->second == 1 ){
            ans = i+1;
          }else if( unq_cnt.rbegin()->second == 1 and unq_cnt.begin()->second == 1 and unq_cnt.begin()->first==1){
            ans = i+1;
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
  cout << sol.maxEqualFreq(v) << endl;
  return 0;
}
