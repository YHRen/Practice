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
  int ans = INF;
  unordered_map<string,int> cache;
  string shrink(string str){
    debug("shirnk", str);
    int n = sz(str);
    while(n > 2){
      trace(n, str);
      bool flag = false;
      for(int i = 0, end; i < n-1;  ){
        if( str[i+1] != str[i] ){
          ++i;
          continue;
        }
        end = i;
        while( end < n and str[end]==str[i] ){
          ++end;
        }
        trace(i,end);
        if( end - i >= 3 ){
          str = str.substr(0, i) + str.substr(end);
          n = sz(str);
          flag = true;
          trace("newstr", str);
          break;
        }else{
          i = end;
        }
      }
      if(flag == false) break;
    }
    debug("shirnk", str);
    return str;
  }
  void solve( const string & board, const string & hand, int cost ){
    debug("solve", board, hand, cost);
    if( cost >= ans ) return;
    if( board.empty() ){ ans = min(cost, ans); return; }
    if( hand.empty() ) return;
    if( auto itr = cache.find(board+"#"+hand); itr!=cache.end() and itr->second <= cost) return;
    cache[board+"#"+hand] = cost;
    
    // reduce
    forall(k,0,sz(hand)){
      if(k!=0 and hand[k] == hand[k-1]) continue;
      trace(board, k, hand[k]);
      char c = hand[k];
      forall(i,0,sz(board)-1){
        if( board[i] == c and board[i+1] == c ){
          debug("inserting", hand[k], "at", i, board[i]);
          string new_board = shrink(board.substr(0,i) + board.substr(i+2));
          debug("hand", hand, k);
          debug(hand.substr(0,k));
          debug(hand.substr(k+1));
          string new_hand = hand.substr(0,k)+hand.substr(k+1);
          solve(new_board, new_hand, cost+1);
        }
      }
    }

    // add
    forall(k,0,sz(hand)){
      if( k!=0 and hand[k] == hand[k-1] ) continue;
      char c = hand[k];
      forall(i,0,sz(board)){
        if( board[i] == c ){
          string new_board = board.substr(0,i) + c + board.substr(i);
          string new_hand = hand.substr(0,k)+hand.substr(k+1);
          solve(new_board, new_hand, cost+1);
        }
      }
    }
  }
  public:
    int findMinStep(string board, string hand) {
      sort(all(hand));
      solve(board, hand, 0);
      return ans == INF? -1 : ans;
    }
};

int main( int argc, char * argv[] ){
  string b,s;
  cin >> b >> s;
  Solution sol;
  cout << sol.findMinStep(b,s) << endl;
  return 0;
}
