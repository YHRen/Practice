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
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
      int n = B.size();
      multiset<int> bag(all(A));
      vii v;
      forall(i,0,n) v.pb(mp(B[i],i));
      sort(all(v));
      vi ans(n, -1);

      forall(i,0,n){
        int x = v[i].first, idx = v[i].second;
        auto itr = bag.upper_bound(x);
        if( itr != bag.end() ){
          ans[idx]=*itr;
          bag.erase(itr);
        }else{
          break;
        }
      }
      forall(i,0,n){
        if( ans[i] == -1 ){
          ans[i] = *bag.begin();
          bag.erase(bag.begin());
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}



/**
 * Given two arrays A and B of equal size, the advantage of A with respect to B is the number of indices i for which A[i] > B[i].

Return any permutation of A that maximizes its advantage with respect to B.

 

Example 1:

Input: A = [2,7,11,15], B = [1,10,4,11]
Output: [2,11,7,15]

Example 2:

Input: A = [12,24,8,32], B = [13,25,32,11]
Output: [24,32,8,12]

 

Note:

    1 <= A.length = B.length <= 10000
    0 <= A[i] <= 10^9
    0 <= B[i] <= 10^9

*/
