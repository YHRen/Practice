#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/add-and-search-word-data-structure-design/
//  Design a data structure that supports the following two operations:
//
//  void addWord(word)
//  bool search(word)
//
//  search(word) can search a literal word or a regular expression string
//  containing only letters a-z or .. A . means it can represent any one
//  letter.
//
//  For example:
//
//  addWord("bad")
//  addWord("dad")
//  addWord("mad")
//  search("pad") -> false
//  search("bad") -> true
//  search(".ad") -> true
//  search("b..") -> true
//
//  You may assume that all words are consist of lowercase letters a-z. 

// solution: it seems trie is the easiest way to do it. 
// ...there are more space-saving ways such as suffix tree and suffix array,
// ...but hard on implementation


class WordDictionary {
  private:

    static const int LETTERSZ = 27; // 26 letters + 1 termination 
    static const char END = 'z'+1; // which is '{' I think?

    struct node{
      public:
        char c; 
        uint32_t        child_bits;
        vector<node*>   children;
        int get_idx( char c ) const {
          return c-'a';
        }

        bool is_set( uint32_t bits, int pos ) const {
          return bits & ( 1u << pos );
        }

        void set_bit( uint32_t & bits, int pos ){
          bits |= ( 1u << pos );
        }

      public:
        node( ) : c ('$'), child_bits(0) {
          this->children.resize( LETTERSZ, NULL );
        } // root node
        node( char x ) : c(x), child_bits(0){
          this->children.resize( LETTERSZ, NULL );
        }

        bool has_child( char x ) const {
          return is_set( child_bits, get_idx( x ) );
        }

        node * add_child( char x ){
          if( !has_child( x ) ){
            set_bit( child_bits, get_idx(x) );
            children.at( get_idx(x) ) = new node(x);
          }
          return children.at( get_idx(x) );
        }

       node * get_child( char x ){
          return children.at( get_idx(x) );
        }

        ~node(){
          if( !child_bits ) return;
          for( auto & child : children ){
            if( child != NULL ){
              delete child;
            }
          }

        }
    };

    node root;

    bool search_aux( const string & word, node & cur, int idx ){
      if( idx == word.size() && cur.has_child(END) ) return true;
      const char c = word[idx];
      if( c != '.' ){ 
        if( cur.has_child( c ) ){
          return search_aux( word, *cur.get_child( c ), idx+1 );
        }else{
          return false;
        }
      }else{ // c is a wild charactor
        for( char x = 'a'; x < END; ++x ){
          if( cur.has_child( x ) &&
              search_aux( word, *cur.get_child( x ), idx+1 ) ){
            return true;
          }
        }
        return false;
      }
    }

  public:
    // Adds a word into the data structure.
    void addWord(string word) {
      if( word.empty() ){
        root.add_child( END );
        return;
      }

      // word should only consists of a-z
      node * cur = &root;
      for( char c : word ){
        cur = cur -> add_child( c );
      }
      cur->add_child( END );
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      if( word.empty() ){
        return root.has_child( END );
      }
      return search_aux( word, root, 0 );
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  WordDictionary wordDictionary;
  int n,m; cin >> n >> m;
  string str;
  while( n-- ){
    cin >> str;
    debug("adding ", str );
    wordDictionary.addWord( str );
  }
  while( m-- ){
    cin >> str;
    debug("searching ", str );
    cout << "has " << str << " ? " << wordDictionary.search( str ) << '\n';
  }
  return 0;
}
