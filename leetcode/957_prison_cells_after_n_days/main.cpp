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
    bool isCompleteTree(TreeNode* root) {
      vi visited(1024, 0);
      queue<pair<int, TreeNode*>> Q;
      Q.push(mp(1,root));
      visited[1] = 1;
      int cnt = 0;
      while(!Q.empty()){
        auto x = Q.front(); Q.pop();
        cnt += 1;
        int idx = x.first;
        if( idx > 500 ) return false;
        auto ptr = x.second;
        if( ptr->left != NULL ){
          visited[idx*2] = 1;
          Q.push( mp( idx*2, ptr->left) );
        }
        if( ptr->right != NULL ){
          visited[idx*2+1] = 1;
          Q.push( mp( idx*2+1, ptr->right) );
        }
        if( ptr->left == NULL && ptr->right!=NULL ) return false;
      }
      int run = 0;
      forall(i,1,1024){
        if( visited[i] == 1 ){
          run ++;
        }else{
          if( run == cnt ) return true;
          else return false;
        }
      }

    }
};
int main( int argc, char * argv[] ){

  return 0;
}
