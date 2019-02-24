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
  vi get_values( TreeNode * r ){
    vi ans ;
    if( r -> left != NULL ){
      auto vl = get_values(r->left);
      ans = vl;
    }
    ans.pb(r->val);
    if( r->right != NULL){
      auto vr = get_values(r->right);
      copy( all(vr), back_inserter(ans));
    }
    return ans;
  }
  TreeNode * construct( vi v  ){
    int n = v.size();
    int idx =  max_element(all(v)) - v.begin();
    TreeNode * ptr = new TreeNode(v[idx]);
    if( idx > 0 ){
      vi sub_left;
      copy(v.begin(), v.begin()+idx, back_inserter(sub_left));
      ptr->left = construct( sub_left);
    }
    if( idx <  n - 1 ){
      vi sub_right;
      copy(v.begin()+idx+1, v.end(), back_inserter(sub_right));
      ptr->right = construct( sub_right);
    }
    return ptr;
  }

public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
      auto v = get_values(root);
      v.pb(val);
      return construct(v);
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
