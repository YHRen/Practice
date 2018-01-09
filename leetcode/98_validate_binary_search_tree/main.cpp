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
//   https://leetcode.com/problems/validate-binary-search-tree/ 
// Given a binary tree, determine if it is a valid binary search tree (BST).
//
// Assume a BST is defined as follows:
//
//  The left subtree of a node contains only nodes with keys less than the node's key.
//  The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.
//
//
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  private:
    const int64_t ninf = numeric_limits<int64_t>::min();
    const int64_t pinf = numeric_limits<int64_t>::max();

    bool is_valid_aux( TreeNode * r, int64_t v, int64_t u){
      if( r == NULL ) return true;
      if( ( r->left == NULL || 
            r->left->val < r->val && 
            ( v == ninf || r->left->val > v) &&
            is_valid_aux( r->left, v, r->val ) ) &&
          ( r->right == NULL || 
            r->right->val > r->val &&
            ( u == pinf || r->right->val < u ) &&
            is_valid_aux( r->right, r->val, u ) )
        ){

        return true;

      }else{

        return false;
      }
    }
  public:
    bool isValidBST(TreeNode* root) {
      if( root == NULL ) return true;
      return is_valid_aux(root, numeric_limits<int64_t>::min(), numeric_limits<int64_t>::max() );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
