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
  set<int> del;
  vector<TreeNode*> aux(TreeNode *& node, int cur_root){
    if(node == NULL ) return {};
    if( del.count(node->val) ){
      del.erase(node->val);
      vector<TreeNode*> p,q;
      if( node->left){
        p = aux(node->left, node->left->val);
      }
      if(node->right){
        q = aux(node->right, node->right->val);
      }
      vector<TreeNode*> res;
      for(auto x : p ) res.pb(x);
      for(auto x : q ) res.pb(x);
      delete node; // node = NULL;
      return res;
    }else{ // not deleting this one
      vector<TreeNode*> p,q;
      if( node->left){
        p = aux(node->left, cur_root);
      }
      if(node->right){
        q = aux(node->right, cur_root);
      }
      vector<TreeNode*> res;
      for(auto x : p ) res.pb(x);
      for(auto x : q ) res.pb(x);
      if( node->val == cur_root ){
        res.pb(node);
      }
      return res;
    }
  }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      for(auto x : to_delete) del.insert(x);
      vector<TreeNode*> res = aux(root, root->val);
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
