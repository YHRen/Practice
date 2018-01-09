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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  private:
    int solve( TreeNode * node, int & p, int k ){
      if( k == 1 && node->left==NULL ) return node->val;
      p++;
      int q=0;
      if( node->left != NULL ){
        int ans;
        ans = solve( node->left, q, k );
        if( ans != -1 ) return ans;
        else
          p += q;
      }
      if( k - q == 1 ) return node->val;
      int q2= 0;
      if( node->right != NULL ){
        int ans;
        ans = solve( node->right, q2, k-q-1 );
        if( ans != -1 ) return ans;
        else
          p += q2;
      }
      return -1;
    }

  public:
    int kthSmallest(TreeNode* root, int k) {
      int p;
      return solve( root, p, k );
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
