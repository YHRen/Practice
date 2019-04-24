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

static constexpr const int ALPH_SZ = 26;
struct Trie {
  int val;
  vector<Trie*> children;
  Trie(){ 
    children.resize(ALPH_SZ, nullptr);
    val = -1;
  }
  ~Trie(){
    for(auto & ptr : children ) if( ptr ) delete ptr;
    children.clear();
  }
};

class StreamChecker {
  Trie* trie;
  void insert(const string & w){
    Trie * ptr = trie;
    for(char c : w ){
      int idx = c-'a';
      if( ! ptr->children[idx] ){ ptr->children[idx] = new Trie(); }
      ptr = ptr->children[idx];
    }
    ptr->val = 1;
  }
  queue<Trie*> Q, P;
public:
    StreamChecker(vector<string>& words) {
      this->trie = new Trie();
      for(const auto w : words){
        insert(w);
      }
    }
    
    bool query(char letter) {
      bool ans = false;
      const int idx = letter - 'a';
      while(!Q.empty()){
        auto ptr = Q.front(); Q.pop();
        if( ptr->children[idx] ){
          ptr = ptr->children[idx];
          if( ptr->val == 1 ) ans = true;
          P.push(ptr);
        }
      }
      if( this->trie->children[idx] ){
        auto ptr = this->trie->children[idx];
        P.push( ptr );
        if( ptr->val == 1 ) ans = true;
      }
      swap(P,Q);
      return ans;
    }
    ~StreamChecker(){
      delete trie;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
