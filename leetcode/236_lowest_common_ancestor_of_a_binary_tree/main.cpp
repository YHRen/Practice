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
  private:
    TreeNode * ans;
    bool contain( TreeNode * p, TreeNode * q ){
      if( p == q ) return true;
      bool f1=false,f2=false;
      if( p->left != NULL ){
        f1 = contain( p->left, q );
      }
      if( f1 ) return true;
      if( p->right != NULL ){
        f2 = contain( p->right,q);
      }
      if( f2 ) return true;
      return false;
    }
    bool get_path( TreeNode * & p, TreeNode * & q, vector<TreeNode*> & v ){
      if( p == q ){
        v.pb(q);
        return true;
      }
      if( p->left != NULL ){
        if( get_path(p->left, q, v ) ){
          v.pb(p);
          return true;
        }
      }
      if( p->right!=NULL){
        if( get_path(p->right,q,v) ){
          v.pb(p);
          return true;
        }
      }
      return false;
    }

  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if( p == root || q == root ) return root;
      if( contain(p,q) ) return p;
      if( contain(q,p) ) return q;
      vector<TreeNode*> v,u;
      get_path( root, p, v );
      get_path( root, q, u );
      debug(v.size());
      debug(u.size());
      for (auto itr1 = v.rbegin(), itr2 = u.rbegin();
           itr1 != v.rend() && itr2 != u.rend(); ++itr1, ++itr2) {
        if( *itr1 == *itr2 ){
          debug("common:",(*itr1)->val);
          ans = *itr1;
        }else{
          break;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  TreeNode * root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  Solution sol;
  auto ans = sol.lowestCommonAncestor(root, root->left, root->right);
  cout << ans->val << '\n';


  return 0;
}
