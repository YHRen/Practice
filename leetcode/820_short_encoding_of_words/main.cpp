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
// std::cin.tie(NULL);


/******* Actual Code Starts Here *********/
class Solution {
class Trie {
  private:
   const static int VOCSZ = 27; // last bit mark has_word
   vector<int> null_vec;
   vector<vector<int>> trie;
   inline int to_int( char c ){ return c - 'a'; } 
  public:

    Trie() {
      this->null_vec.resize(VOCSZ, -1);
      trie.pb(null_vec);
    }
    
    void insert(string word) {
      int i = 0, v = 0, n_ = word.size();
      for( /*  */; i < n_; ++i ){
        int & u = trie[v][to_int(word[i])];
        if( u == -1 ){
          u = trie.size();
          this->trie.pb( null_vec );
        }
        v = u;
      }
      trie[v].back() = 1;
    }

    bool search(string word) {
      if( word.empty() ) return 0;
      int i = 0, v = 0, n_ = word.size();
      for(/* */; i < n_; ++i ){
        int & u = trie[v][to_int(word[i])];
        if( u == -1 ) return false;
        v = u;
      }
      return trie[v].back() == 1;
    }

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


  public:
    int minimumLengthEncoding(vector<string>& words) {
      sort(all(words));
      words.erase( unique(all(words)), words.end());
      sort(all(words), [](const string & a, const string & b ){
          return a.length() > b.length(); });

      print_(words);

      Trie trie;
      int ans = 0;
      for( auto w : words ){
        reverse(all(w));
        if( trie.startsWith(w) ) continue;
        else{
          ans += w.length();
          ans += 1;
          trie.insert(w);
        }
      }
      return ans; 
    }
};
int main( int argc, char * argv[] ){
  vector<string> S = {"time", "me", "bell"};
  Solution sol;
  cout << sol.minimumLengthEncoding(S) << '\n';

  return 0;
}
