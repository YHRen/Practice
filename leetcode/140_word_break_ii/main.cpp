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

//auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

static constexpr const int ALPH_SZ = 27;
struct Trie {
  int val;
  vector<Trie*> children;
  Trie(){ 
    children.resize(ALPH_SZ, nullptr);
    val = -1;
  }
  ~Trie(){
    for(auto & ptr : children ) if( ptr ) delete(ptr);
    children.clear();
  }
};

class Solution {
  unordered_set<string> dic;
  unordered_map<int, vector<string>> dp;
  Trie* trie;
  string str;
  int n;
  vector<string> solve(int idx){
    if(auto itr = dp.find(idx); itr!= dp.end() ) return itr->second;
    vector<string> ans;
    Trie * ptr = this->trie;
    ptr = this->trie;
    forall(i,idx,n){
      int x = str[i]-'a';
      if(ptr->children[x] == nullptr){
        break;
      }
      if( ptr->children[x]->val == 1 ){
         if( i + 1 < n ){
           auto tmp = solve(i+1);
           if( !tmp.empty() ){
             string prefix = str.substr(idx, i-idx+1);
             for(auto & y : tmp){ ans.pb( prefix + ' ' + y); }
           }
         }else{
           ans.pb( str.substr(idx, i -idx+1));
         }
      }
      ptr = ptr->children[x];
    }
    return dp[idx] = ans;
  }

  public:
    vector<string> wordBreak(string S, vector<string>& wordDict) {
      this->trie = new Trie();
      for(auto & s : wordDict){
        Trie * ptr = this->trie;
        for(auto c : s ){
          int idx = c-'a';
          if( ptr->children[idx] == nullptr ){
            ptr->children[idx] = new Trie();
          }
          ptr = ptr->children[idx];
        }
        ptr->val = 1;
      }
      n = sz(S);
      str = S;
      return solve(0);
        
    }
};
int main( int argc, char * argv[] ){
  string S; cin >> S;
  int n; cin >> n; 
  vector<string> v(n); input(v);
  Solution sol;
  auto res = sol.wordBreak(S, v);
  print_(res);
  return 0;
}
