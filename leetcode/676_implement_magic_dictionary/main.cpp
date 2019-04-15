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

class MagicDictionary {
  struct Trie{
    vector<Trie*> children;
    bool ends_here;
    Trie():ends_here(false){
      children.resize(26, nullptr);
    }
  };
  Trie * root;
  void add_to_trie(const string & str){
    Trie * ptr = root;
    for( auto c : str ){
      int idx = c-'a';
      if( ptr->children[idx] == nullptr ){
        ptr->children[idx] = new Trie();
      }
      ptr = ptr->children[idx];
    }
    ptr->ends_here = true;
  }
  void clear_trie(Trie * r){
    if( !r ) return;
    for(auto & ptr : r->children) clear_trie(ptr);
    r->children.clear();
    delete r;
  }


  bool is_a_strange_match( const string & str, const int n, int i, Trie * ptr, int diff=0 ){
    debug(str, i, diff, str[i]);
    if( diff >= 2 ) return false;
    if( i == n and diff == 1 and ptr->ends_here ) return true;
    if( i == n ) return false;
    char c = str[i];
    int idx = c-'a';
    if( ptr->children[idx] != nullptr ){
        if( is_a_strange_match( str, n, i+1, ptr->children[idx], diff ) ){
          return true;
        }
    }
    forall(k,0,26){
      if(k!=idx and ptr->children[k] != nullptr){
        if( is_a_strange_match(str, n , i+1, ptr->children[k], diff+1 ) ){
          return true;
        }
      }
    }
    return false;
  }
public:
    /** Initialize your data structure here. */
    MagicDictionary() : root(nullptr) {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
      clear_trie(root);
      debug("after clear");
      root = new Trie();
      for(const auto & str : dict){
        add_to_trie(str);
      }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
      return is_a_strange_match(word, sz(word), 0, root, 0);
    }
    ~MagicDictionary(){
      clear_trie(root);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
int main( int argc, char * argv[] ){
  MagicDictionary M;
  //vector<string> words = {"hello", "hallo", "leetcode"};
  vector<string> words = {"a"};
  M.buildDict(words);
  cout << M.search("a") << endl;
  cout << M.search("b") << endl;
  cout << M.search("c") << endl;
  M.buildDict({"hello","leetcode"});
  cout << M.search("hallo") << endl;
  cout << M.search("hello") << endl;
  M.buildDict({"a"});
  cout << M.search("hallo") << endl;
  cout << M.search("hello") << endl;
  cout << M.search("a") << endl;
  cout << M.search("b") << endl;
  cout << M.search("c") << endl;
  return 0;
}
