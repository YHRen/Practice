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

// auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
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
  ll lmt;
  bool aux( TreeNode * node, ll cur){
    if( !node ) return cur >= lmt;
    cur += node->val;
    bool p = aux(node->left,cur);
    bool q = aux(node->right,cur);
    if( !p ) node->left = nullptr;
    if( !q ) node->right = nullptr;
    return  p or q;
  }

public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
      this->lmt = limit;
      if( !root ) return root;
      if( aux(root,0) ) return root; 
      else return nullptr; 
    }
};

class Solution_right {
  int lmt;
  int aux( TreeNode * node, int cur){
    cur += node->val; int res;
    if( node->left == nullptr and node->right == nullptr ){ // a leaf node
      return cur;
    }else if( node->left == nullptr and node->right ){// has right
      res = aux(node->right, cur);
      if( res < lmt ){
        node->right = nullptr;
      }
      return res;
    }else if( node->right == nullptr and node->left ){// has left
      res = aux(node->left,cur);
      if( res < lmt) {
        node->left = nullptr;
      }
      return res;
    }else{ //has both
      int p = aux(node->left,  cur);
      if( p < lmt ){ node->left = nullptr; }
      int q = aux(node->right, cur);
      if( q < lmt ){ node->right = nullptr; }
      return max(p,q);
    }
  }

public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
      lmt = limit;
      if( !root ) return root;
      if( aux(root,0) < limit ){
        return nullptr;
      }else{
        return root;
      }
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
