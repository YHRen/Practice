#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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

class Codec {
public:
    void serialize(TreeNode * node, ostringstream & oss ){
      if( !node ){
        oss<<"n ";
      }else{
        oss<<to_string(node->val) << " ";
        serialize(node->left, oss);
        serialize(node->right, oss);
      }
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      ostringstream oss;
      serialize(root, oss);
      return oss.str();
    }


    TreeNode * deserialize(istringstream & iss){
      string token;
      if( iss>>token ){
        if( token == "n" ) return nullptr;
        else{
          TreeNode * ptr = new TreeNode(stoi(token));
          ptr->left = deserialize(iss);
          ptr->right = deserialize(iss);
        return ptr;
        }
      }
      return nullptr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
      if( data.empty() or data[0] == 'n' ) return nullptr;
      istringstream iss (data);
      return deserialize(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
int main( int argc, char * argv[] ){
  TreeNode * ptr = new TreeNode(30);
  string code = to_string( reinterpret_cast<size_t>(ptr) );
  cout << code << '\n';
  size_t addr;
  istringstream iss(code);
  iss>>addr;
  TreeNode * x = reinterpret_cast<TreeNode*>(addr);
  cout << x << ' ' << ptr << endl;



  return 0;
}
