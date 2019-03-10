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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

static constexpr const int ALPH_SZ = 27;
struct trie_node {
  int val;
  vector<trie_node*> children;
  trie_node(){ 
    children.resize(ALPH_SZ, nullptr);
    val = -1;
  }
};

class WordFilter {
  trie_node * head;
public:
    WordFilter(vector<string> words) {
      int n = sz(words);
      head = new trie_node();
      forall(idx,0,n){
        string w = "{"+words[idx];
        int m = words[idx].size();
        for( int j = m; j>=0; --j ){
          if( j != m ){ 
            w = string(1, words[idx][j]) + w; 
          }
          auto ptr = head;
          for( auto c : w ){
            if( ptr->children[c-'a'] == nullptr ){
              ptr->children[c-'a'] = new trie_node();
            }
            ptr = ptr->children[c-'a'];
            ptr->val = idx;
          }
        }
      }
    }
    
    int f(string prefix, string suffix) {
      string query = suffix + "{" + prefix;
      auto ptr = head;
      for(auto c : query){
        if( ptr->children[c-'a'] == nullptr ) return -1;
        else ptr = ptr->children[c-'a'];
      }
      return ptr->val;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter obj = new WordFilter(words);
 * int param_1 = obj.f(prefix,suffix);
 */
int main( int argc, char * argv[] ){
  WordFilter wd({"abc"});

  return 0;
}

