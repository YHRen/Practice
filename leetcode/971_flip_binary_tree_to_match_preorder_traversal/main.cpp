#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bitset>
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
// std::cin.tie(NULL);
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
  vi ans;
  int node;
  int n;
  bool dfs( TreeNode* r, const vi & v ){
    if( r==NULL ) return true;
    if( v[node] != r->val ) return false;
    node ++;
    if( node == n ) return true;
    if( r->left == NULL && r->right == NULL ) return true;

    bool p = true,q = true;
    if( r->left != NULL ){
      if( r->left->val == v[node] ) return dfs(r->left, v) && dfs(r->right, v);
      else if( r->right != NULL && r->right->val == v[node] ){
        ans.pb(r->val);
        return dfs(r->right, v) && dfs(r->left,v);
      }else return false;
    }else{
      return dfs(r->right, v);
    }
  }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
      node = 0;
      n = voyage.size();
      if( dfs(root, voyage) ){
        return ans;
      }else{
        return {-1};
      }


        
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
