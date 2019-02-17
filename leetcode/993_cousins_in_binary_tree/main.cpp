#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_set>
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

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
  int x,y;

  ii rec_x, rec_y;
  void solve( TreeNode * node, int p, int d ){
    if( node->val == x ){
      rec_x.first = d;
      rec_x.second = p;
    }
    if( node->val == y ){
      rec_y.first = d;
      rec_y.second = p;
    }
    if( node->left != NULL ) solve( node->left, node->val, d+1);
    if( node->right!= NULL ) solve( node->right, node->val, d+1);
  }
public:
    bool isCousins(TreeNode* root, int x, int y) {
    this->x = x; this->y=y;
    this->rec_x = mp(-1,-1);
    this->rec_y = mp(-2,-2);

    solve(root, -1, 0);
    if( rec_x.first == rec_y.first and rec_x.second != rec_y.second ) return true;
    else return false;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
