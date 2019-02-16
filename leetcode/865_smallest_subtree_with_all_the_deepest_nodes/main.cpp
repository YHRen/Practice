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
  int max_d, max_cnt;
  TreeNode * ans;
  unordered_map<int, int> dist;
  int rec(TreeNode* r){
    int x = 0;
    if( r->left != NULL ){
      x += rec(r->left);
    }
    if( r->right != NULL){
      x += rec(r->right);
    }
    if( x == max_cnt ){
      ans = r;
      return 0;
    }
    if( dist[r->val] == max_d ){
      if( max_cnt == 1 ){
        ans = r;
        return 0;
      }else{ return 1; }
    }
    return x;
  }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      max_d = 0;
      max_cnt= 0;
      dist[root->val] = 0;
      queue<TreeNode*> Q;
      Q.push(root);
      while(!Q.empty()){
        auto r = Q.front(); Q.pop();
        int  d = dist[r->val];
        if( r->left != NULL ){
          dist[r->left->val] = d+1;
          Q.push(r->left);
          if( max_d < d+1 ){
            max_d = d+1;
            max_cnt = 1;
          }else if(max_d == d+1 ){
            max_cnt ++;
          }
        }
        if( r->right != NULL){
          dist[r->right->val] = d+1;
          Q.push(r->right);
          if( max_d < d+1 ){
            max_d = d+1;
            max_cnt = 1;
          }else if(max_d == d+1 ){
            max_cnt ++;
          }
        }
      }

      rec(root);
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
