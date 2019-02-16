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

vvi t2g(TreeNode* root, unordered_map<int, TreeNode*> & id2tn){
  // convert leetcode tree to graph
  vvi g;
  int idx = 0;
  queue<pair<TreeNode*,int>> Q; Q.push(mp(root,idx));
  g.pb({});
  while(!Q.empty()){
    auto tmp = Q.front(); Q.pop();
    auto ptr = tmp.first;
    int  x   = tmp.second;
    id2tn[x]=ptr;
    if( ptr->left != NULL ){
      g.pb({x});
      idx++;
      g[x].pb(idx);
      Q.push(mp(ptr->left, idx));
    }
    if( ptr->right != NULL) {
      g.pb({x});
      idx++;
      g[x].pb(idx);
      Q.push(mp(ptr->right,idx));
    }
  }
  return g;
}

class Solution {

  vi ans;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
      if( K == 0 ){ return {target->val}; }
      unordered_map<int,TreeNode*> id2tn;
      auto g = t2g(root, id2tn);
      int n = g.size();
      int source;
      forall(i,0,n){
        if(id2tn[i] == target){
          source = i;
          break;
        }
      }
      vi is_visited(n,-1);
      is_visited[source] = 0;
      queue<int> Q;
      Q.push(source);
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        int d = is_visited[x];
        for(auto u : g[x]){
          if( is_visited[u] == -1 ){
            is_visited[u]= d+1;
            if( d+1 == K ) ans.pb( id2tn[u]->val);
            else Q.push(u);
          }
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}

/*
We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.

 

Note:

    The given tree is non-empty.
    Each node in the tree has unique values 0 <= node.val <= 500.
    The target node is a node in the tree.
    0 <= K <= 1000.

*/
