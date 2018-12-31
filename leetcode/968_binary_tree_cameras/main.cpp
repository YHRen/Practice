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

/**
 * Definition for a binary tree node.
 */

class Solution {
  vvi g;
  vi depth;
  void colorize( int x, vi & is_colored ){
    is_colored[x] = true;
    for(auto y : g[x] ){
      is_colored[y] = true;
    }
  }
  bool is_children_colorized( int x, vi & is_colored){
    bool flag = true;
    for( auto y : g[x] ){
      if(y > x && is_colored[y] ==false ){
        flag = false;
      }
    }
    return  flag;
  }
  public:
    int minCameraCover(TreeNode* root) {
      g.resize(1000);
      depth.resize(1000);
      depth[0] = 0;

      queue<pair<TreeNode*,int>> Q;
      Q.push(mp(root,0));
      int idx = 0;
      while(!Q.empty()){
        auto q = Q.front(); Q.pop();
        auto r = q.first;
        auto i = q.second;
        if( r->left != NULL ){
          ++idx;
          g[i].pb(idx);
          g[idx].pb(i);
          depth[idx] = depth[i]+1;
          Q.push(mp(r->left,idx));
        }
        if( r->right != NULL ){
          ++idx;
          g[i].pb(idx);
          g[idx].pb(i);
          depth[idx] = depth[i]+1;
          Q.push(mp(r->right,idx));
        }
      }
      debug("total node = ",idx+1);
      int n = idx+1;


      // find all leaf node
      priority_queue<ii> P;

      vi is_colored( n, false );
      forall(i,0,n){
        if( g[i].size() == 1 ){
          int x = g[i][0];
          P.push(mp( depth[x], x ) );
        }
      }
        
      int ans = 0;
      while( !P.empty() ){
        
        ii p = P.top(); P.pop();
        int x = p.second;
        if( is_children_colorized(x, is_colored) ){
          if( g[x][0] < x ) x = g[x][0];
            if(x != 0 )          P.push( mp(depth[x], x) );
          continue;
        }
        colorize(x, is_colored);
        ans ++;

        if( g[x][0] < x  ) x = g[x][0];
        if( g[x][0] < x  ) x = g[x][0];
        if( g[x][0] < x  ) x = g[x][0];
        if( x != 0 ) {
            P.push(mp( depth[x], x) );
        }
      }
      if( is_children_colorized(0, is_colored) == false || is_colored[0] == false ){
        colorize(0, is_colored);
        ans ++;
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
