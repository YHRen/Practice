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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// for fully packed binary tree, nodes = 2^h -1
class Solution {
  private:
    int find_max_height( TreeNode * root ){
      if( root == NULL ) return 0;
      int h = 1;
      TreeNode * tmp = root;
      while( tmp->left != NULL ){
        h ++;
        tmp = tmp->left;
      }
      return h;
    }
    int leaves_num( TreeNode * root, int lo, int hi, int digits){
      assert( lo <= hi );
      if( lo == hi ) return lo;
      int mid = (lo+hi) / 2;
      TreeNode * tmp = root;
      for( int i = 1; i < digits; ++i ){
        if( ( mid >> (digits-i) ) & 1 ){ // pick ith binary
          tmp = tmp->right;
        }else{
          tmp = tmp->left;
        }
      }
      if( tmp->left != NULL && tmp->right == NULL ){
        return  mid&1 ? mid-1 : mid ;
      }else if( tmp->left == NULL ){ // right must == NULL
        return leaves_num( root, lo, (mid|1)-2, digits );
      }else if( tmp->right != NULL ){ // left must != NULL
        return leaves_num( root, mid|1, hi, digits );
      }
    }

  public:
    int countNodes(TreeNode* root) {
      int max_height = find_max_height( root );
      if( max_height <= 1 ) return max_height;
      int leaves_num = count_leaves( root, 0, (1u<<(max_height-1))-1, max_height-1 );
      return ((1u<<(max_height-1)) - 1) + leaves_num + 1; // = (1u<<(max_height-1)) + leaves_num;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);




  return 0;
}
