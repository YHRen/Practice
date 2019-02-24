// #include <bits/stdc++.h>
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
   const static int VOCSZ = 3; // last bit mark has_word
   vector<int> null_vec;
   vector<vector<int>> trie;
   inline int to_int(int num, int idx ){ 
     return ( num & (1<<idx) ) != 0;
   } 
  public:

    Trie() {
      this->null_vec.resize(VOCSZ, -1);
      trie.pb(null_vec);
    }
    
    void insert(int num) {
      int  v = 0;
      for( int i = 31; i >= 0; --i ){
        int & u = trie[v][to_int(num, i)];
        if( u == -1 ){
          u = trie.size();
          this->trie.pb( null_vec );
        }
        v = u;
      }
      trie[v].back() = 1;
    }

    bool search( int num ){
      int  v = 0;
      for( int i = 31; i >= 0; --i ){
        int & u = trie[v][to_int(num, i)];
        if( u == -1 ){
          return false;
        }
        v = u;
      }
      return trie[v].back() == 1;
    }
 
    int find_max_xor( int num ){
      int v = 0;
      long long int ans = 0;
      for( int i = 31; i >= 0; --i ){
        if( trie[v][!to_int(num,i)] != -1 ){
          v = trie[v][!to_int(num,i)];
          ans += 1;
        }else{
          v = trie[v][to_int(num,i)];
        }
        ans *= 2;
      }
      return ans/2;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& v) {
      Trie trie;
      for(auto x : v ) trie.insert(x);
      int ans = 0;
      for(auto x : v ){
        ans = max( ans, trie.find_max_xor(x) );
      }
      return ans;
    }
};

int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.findMaximumXOR(v) << '\n';
  cout << "====================================================================================================\n";
  int res = 0;
  forall(i,0,n){
    forall(j,i+1,n){
      res = max( v[i] ^ v[j], res );
    }
  }
  cout << res << '\n';



  return 0;
}
