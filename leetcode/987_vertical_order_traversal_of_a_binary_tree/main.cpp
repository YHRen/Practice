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
Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  map<int, vii> store;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
      queue<pair<ii,TreeNode*>> Q;
      Q.push( mp( mp(0,0), root ) );
      store[0].pb(mp(0,root->val));
      while(!Q.empty()){
        auto u = Q.front();Q.pop();
        int x = u.first.first;
        int y = u.first.second;
        TreeNode * r = u.second;
        if( r->left != NULL ){
          store[x-1].pb(mp(y+1, r->left->val));
          Q.push(mp(mp(x-1,y+1),r->left));
        }
        if( r->right != NULL ){
          store[x+1].pb(mp(y+1, r->right->val));
          Q.push(mp(mp(x+1,y+1),r->right));
        }
      }
      
      vvi ans;
      for(auto & p : store){
        sort(all(p.second));
        vi tmp;
        for(auto x : p.second){
          tmp.pb(x.second);
        }
        ans.pb(tmp);
      }
      return ans;
        
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
