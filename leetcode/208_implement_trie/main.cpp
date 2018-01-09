#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

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

// std::ios::sync_with_stdio(false);
/******* Actual Code Starts Here *********/
class Trie {
  private:
   const static int MAX_NUMBER_OF_NODES = 50000;
   const static int MAX_ASCII_CODE      = 27; // last bit mark is_word
   vector<vector<int>> trie;
   int trie_nxt;
  
   inline bool try_sz( int v ){
     if( v < MAX_NUMBER_OF_NODES ) return true;
     else {
       cerr << "ERROR: reach MAX_NUMBER_OF_NODES\n";
       return false;
     }
   }

   int to_int( char c ){ return c - 'a'; }
  public:
    /** Initialize your data structure here. */
    Trie() {
      trie.resize( MAX_NUMBER_OF_NODES );
      for( auto & v : trie ){
        v.resize( MAX_ASCII_CODE, -1 );
      }
      this->trie_nxt = 1;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      if( word.empty() ) return;
      int i = 0, v = 0, n_ = word.size();
      for( /*  */; i < n_; ++i ){
        if( try_sz(v) ){
          int & u = trie[v][to_int(word[i])];
          if( u == -1 ) u = trie_nxt ++;
          v = u;
        }
      }
      trie[v][MAX_ASCII_CODE-1] = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      if( word.empty() ) return 0;
      int i = 0, v = 0, n_ = word.size();
      for(/* */; i < n_; ++i ){
        int & u = trie[v][to_int(word[i])];
        if( u == -1 ) return false;
        v = u;
      }
      return trie[v][MAX_ASCII_CODE-1] == 1;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
      if( word.empty() ) return 0;
      int i = 0, v = 0, n_ = word.size();
      for(/* */; i < n_; ++i ){
        int & u = trie[v][to_int(word[i])];
        if( u == -1 ) return false;
        v = u;
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
int main( int argc, char * argv[] ){
  Trie * obj = new Trie();
  int n, m; cin >> n >> m;
  vector<string> v(n);
  vector<string> u(m);
  input(v);
  input(u);
  forall(i,0,n){
    obj->insert(v[i]);
  }
  forall(i,0,m){
    cout << u[i] << ' ' << obj->search(u[i]) << ' ' << obj->startsWith(u[i]) << '\n';
  }
  delete obj;
  return 0;
}
