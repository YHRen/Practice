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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>        vi;
typedef pair<int,int>      ii;
typedef vector<vi>         vvi;
typedef vector<ii>         vii;
typedef long long          ll;
typedef unsigned long long ull;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
  unordered_map<string,vector<TreeNode*>> dic;
  string aux(TreeNode * node){
    if( !node ) return "#";
    string res = to_string(node->val)+":";
    res+=aux(node->left);
    res+="*";
    res+=aux(node->right);
    //cout << node->val << ':' << res << endl;
    dic[res].pb(node);
    return res;
  }
 public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    if(!root) return {};
    dic.clear();
    string lstr, rstr;
    if(root->left)     aux(root->left);
    if(root->right)   aux(root->right);
    vector<TreeNode*> ans;
    for(auto & p : dic){
      if( p.second.size() > 1 ){
        ans.pb(p.second[0]);
      }
    }
    return ans;
  }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
