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

struct Trie{
  vector<Trie*> children;
  int val, cum;
  Trie(): val(0), cum(0){ children.resize(26, nullptr); }
  int add( const string & str, int idx, const int price){
    if( idx == sz(str) ){
      this->cum -= this->val;
      this->cum += price;
      auto ans = price - this->val;
      this->val = price;
      debug("return ans",ans);
      return ans;
    }else{
      auto & ptr = children[str[idx]-'a'] ;
      if( ptr == nullptr ){ ptr = new Trie(); }
      auto ans = ptr->add(str,idx+1,price);
      debug("c",str[idx],"ans",ans);
      this->cum += ans;
      return ans;
    }
  }
};
class MapSum {
public:
  Trie root;
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
      root.add(key, 0, val);
    }
    
    int sum(string prefix) {
      auto ptr = &root;
      for(auto c : prefix){
        if( ptr->children[c-'a'] == nullptr ) return 0;
        ptr = ptr->children[c-'a'];
      }
      return ptr->cum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
int main( int argc, char * argv[] ){
  MapSum obj;
  obj.insert("apple", 3);
  cout << obj.sum("ap") << endl;
  obj.insert("app", 2);
  cout << obj.sum("ap") << endl;
  obj.insert("apple", 8);
  cout << obj.sum("ap") << endl;

  return 0;
}
