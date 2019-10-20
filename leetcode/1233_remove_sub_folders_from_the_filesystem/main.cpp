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
  struct Trie {
    unordered_map<string, Trie*> children;
    Trie(){ }
  };
  vector<string> parse( string & str ){
    istringstream iss(str);
    string token;
    vector<string> ans;
    while( getline(iss, token, '/' )){
      if(token.empty() or token[0] == ' ') continue;
      ans.pb(token);
    }
    return ans;
  }
public:
    vector<string> removeSubfolders(vector<string>& folder) {
      int n = sz(folder);
      vi ord(n);
      iota(all(ord),0);
      sort(all(ord), [&folder](int l, int r){ 
          auto p = count_if(all(folder[l]),[](char c){ return c == '/';});  
          auto q = count_if(all(folder[r]),[](char c){ return c == '/';});
          return p < q;
          });

      vi ans;
      Trie * root = new Trie();
      for(auto idx : ord){
        auto items = parse( folder[idx] );
        auto cur = root;
        bool flag = true;
        for(auto & str : items){
          if( cur->children.count("#") ){
            flag = false;
            break; // subfolder
          }
          if( cur->children.count(str) ){
            cur = cur->children[str];
          }else{
            cur->children[str] = new Trie();
            cur = cur->children[str];
          }
        }
        if( flag ){
          cur->children["#"] = nullptr;
          ans.pb(idx);
        }
      }
      vector<string> res;
      for(auto x : ans){
        res.pb(folder[x]);
      }
      return res;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vector<string> s;
  forall(i,0,n){
    string tmp ;
    cin >> tmp;
    s.pb(tmp);
  }
  Solution sol;
  auto tmp = sol.removeSubfolders(s);
  print_(tmp);
  return 0;
}
