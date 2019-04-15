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

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  int get_number(const string & S, int & idx){
    auto x = S.find('-', idx);
    int res;
    if( x == string::npos ){
      res = stoi(S.substr(idx));
      idx = sz(S);
    }else{
      res = stoi(S.substr(idx, int(x)-idx));
      idx = x;
    }
    return res;
  }
  int get_level(const string & S, int & idx ){
    if( idx == sz(S) ) return -1;
    auto x = S.find_first_of("0123456789", idx);
    int res;
    if( x == string::npos ){
      res = sz(S) - idx;
      idx = sz(S);
    }else{
      res = int(x) - idx;
      idx = x;
    }
    return res;
  }
public:
    TreeNode* recoverFromPreorder(string S) {
      stack<pair<TreeNode*, int>> stk;
      int idx = 0;
      int val = get_number(S, idx);
      int n = sz(S);
      int lvl;
      TreeNode * root = new TreeNode(val);
      stk.push(mp(root,0));
      while( idx != n){
        lvl = get_level(S, idx);
        val = get_number(S,idx);
        TreeNode * tmp = new TreeNode(val);
        while( !stk.empty() and lvl - stk.top().second != 1 ) stk.pop();
        if( stk.empty() ) return root;
        if( lvl - stk.top().second == 1 ){
          if( stk.top().first->left == nullptr ){
            stk.top().first->left = tmp;
          }else{
            stk.top().first->right = tmp;
          }
          stk.push(mp(tmp,lvl));
        }
      }
      return root;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
