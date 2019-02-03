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
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
      if( pre.empty() ) return NULL;
      assert( pre.front() == post.back() );
      TreeNode * node = new TreeNode(pre.front());
      if( pre.size() == 1 ) return node
      vi tmp(pre.begin()+1, pre.end());
      swap(tmp,pre);
      post.pop_back();
      int n = pre.size();
      set<int> l,r;
      int m = n;
      forall(i,0,n){
        l.insert(pre[i]);
        r.insert(post[i]);
        if( l == r ){
          m = i;
          break;
        }
      }
      vector<int> x,y;
      copy(pre.begin(), pre.begin()+m+1, back_inserter(x));
      copy(post.begin(), post.begin()+m+1, back_inserter(y));
      node->left = constructFromPrePost( x,y );
      x.clear();
      y.clear();
      copy(pre.begin()+m+1, pre.end(), back_inserter(x));
      copy(post.begin()+m+1, post.end(), back_inserter(y));
      node->right = constructFromPrePost(x,y);
      return node;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
