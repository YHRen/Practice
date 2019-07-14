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
  int depth;
  TreeNode * ans;
  unordered_set<int> S;
  int tot_leaf;
  int lowest_level;
  int find_depth(TreeNode * root, int level){
    if( !root ) return level;
    else return max(find_depth( root->left, level+1),
        find_depth(root->right, level+1));
  }
  void mark_deep_node(TreeNode * node, int level){
    if( node and level == depth ){
      S.insert(node->val);
    }else if( node ){
      mark_deep_node(node->left, level+1);
      mark_deep_node(node->right, level+1);
    }
  }
  bool has_deepest_node(TreeNode * root, int level){
    if( root and level == depth ){
      S.erase(root->val);
      if( S.empty() and tot_leaf==1 ){
        ans = root;
      }
      return true;
    }else if( root){
      bool p = has_deepest_node(root->left, level+1);
      bool q = has_deepest_node(root->right, level+1);
      if( ( p | q ) and S.empty() and ans == NULL ){ ans = root; }
      if( p and q ) ans = root;
      return p | q;
    }
    return false;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
      depth = find_depth(root, 0)-1;
      lowest_level = INF;
      mark_deep_node(root,0);
      tot_leaf = sz(S);
      ans = NULL;

      has_deepest_node(root, 0);
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
