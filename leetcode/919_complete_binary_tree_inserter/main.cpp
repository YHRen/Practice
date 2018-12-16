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
 
class CBTInserter {
  private:
    vector<TreeNode*> data;
    int cur = 0;
public:
    CBTInserter(TreeNode* root) {
      queue<pair<int, TreeNode*> > P;
      forall(i,0,11000) data.pb( NULL );
      P.push(mp(1,root));
      while(!P.empty()){
        auto x = P.front(); P.pop();
        int idx = x.first;
        TreeNode * node = x.second;
        data[idx] = node;
        if( node->left != NULL ){ P.push(mp(idx*2, node->left)); }
        if( node->right != NULL ){ P.push(mp(idx*2+1,node->right)); }
      }
      forall(i,1,11000){
        if( data[i] == NULL ){
          cur = i;
          break;
        }
      }
    }
    
    int insert(int v) {
      data[cur] = new TreeNode(v);
      int ans = cur/2;
      if( cur%2 == 0 ){ data[ans]->left = data[cur];
      }else{ data[ans]->right = data[cur]; }
      forall(i, cur+1, 11000){
        if( data[i] == NULL ) {
          cur = i;
          break;
        }
      }
      return data[ans]->val;
        
    }
    
    TreeNode* get_root() {
      return this->data[1];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
int main( int argc, char * argv[] ){

  return 0;
}
