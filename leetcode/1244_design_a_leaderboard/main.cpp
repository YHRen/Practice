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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Leaderboard {
  unordered_map<int, int> p2s;
  map<int, int> cnt;
public:
    Leaderboard() { }
    
    void addScore(int playerId, int score) {
      cnt[p2s[playerId]]--;
      p2s[playerId] += score;
      cnt[p2s[playerId]]++;
    }
    
    int top(int K) {
      int tot = 0;
      for(auto itr = cnt.rbegin(); K > 0 and itr != cnt.rend(); ++itr){
        tot += min( itr->second, K ) * itr->first;
        K -= itr->second;
      }
      return tot;
    }
    
    void reset(int playerId) {
      cnt[p2s[playerId]] --;
      p2s[playerId] = 0;
    }
};
int main( int argc, char * argv[] ){
  auto ld = Leaderboard();
  ld.addScore(1, 73);
  ld.addScore(2, 56);
  ld.addScore(3, 39);
  ld.addScore(4, 51);
  ld.addScore(5, 4);
  cout << ld.top(1) << endl;
  ld.reset(1);
  ld.reset(2);
  ld.addScore(2, 51);
  cout << ld.top(3) << endl;


  return 0;
}
