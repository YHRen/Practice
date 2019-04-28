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


const vi order = {0, 6, 7, 5, 8,
                  2, 3, 4, 9, 1};
const vector<string> nums =
  {"zero", "xis", "seven", "vfie", "geiht", 
    "wto", "htree", "four", "inne", "one"};
              
class Solution {
public:
    string originalDigits(string s) {
      vi cnt(26,0);
      for(auto c : s ) cnt[c-'a']+=1;
      vi res(10,0);
      forall(i,0,10){
        int idx = nums[i][0]-'a';
        int tmp = cnt[idx];
        if(tmp){
          for(auto c : nums[i]){
            cnt[c-'a'] -= tmp;
          }
        }
        res[order[i]] = tmp;
      }
      string ans; 
      forall(i,0,10){
        if(res[i]) ans += string(res[i],char('0'+i));
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
