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
class Solution {
public:
    int totalFruit(vector<int>& tree) {
      int ans = 0, cur = 0, k = 0, l = 0;
      map<int,int> types;
      int n = tree.size();
      forall(i,0,n){
        int x = tree[i];
        if( types.find(x) != types.end() ){ // existing element
          types[x] += 1;
          cur += 1;
          ans = max(ans, cur);
        }else if( k < 2 ){ // new element with space
          k += 1;
          types[x] = 1;
          cur += 1;
          ans = max(ans, cur);
        }else{ // k == 2 no space
          while( k == 2 ){
            types[tree[l]] -= 1;
            cur -= 1;
            if( types[tree[l]] == 0 ){
              types.erase(tree[l]);
              k = 1;
            }
            l++;
          }
          types[x] = 1;
          k = 2;
          cur += 1;
          ans = max(ans,cur);
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
