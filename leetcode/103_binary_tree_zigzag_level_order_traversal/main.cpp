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
    vvi ans;
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      if( root == nullptr ) return vvi{};
      queue<TreeNode*> Q, P;
      Q.push(root);
      bool spin = true;
      while(!Q.empty() || !P.empty()){
        vi v;
        while( !Q.empty() ){
          auto x = Q.front(); Q.pop();
          v.pb(x->val);
          if( x->left != nullptr ) P.push(x->left);
          if( x->right != nullptr ) P.push(x->right);
        }
        if( spin ){
          ans.emplace_back(v);
        }else{
          reverse(all(v));
          ans.emplace_back(v);
        }
        spin ^= 1;
        swap(Q,P);
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
