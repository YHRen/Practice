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
class Solution {
  int n,m;
  void flip_row( vi & v ){
    for(auto & x : v ) x ^= 1;
  }
  bool count_column( const vvi & A, int j ){
    int cnt0=0, cnt1=0;
    forall(i,0,n) A[i][j] == 0 ? cnt0++ : cnt1++;
    return cnt0>cnt1;
  }
  void flip_column(vvi & A, int j ){
    forall(i,0,n) A[i][j] ^= 1;
  }

public:
    int matrixScore(vector<vector<int>>& A) {
      n = A.size(), m = A[0].size();
      forall(i,0,n){
        if( A[i][0] == 0 ) flip_row( A[i] );
      }
      forall(j,1,m){
        if( count_column( A, j ) ){
          flip_column(A, j);
        }
      }
      int ans = 0;
      for(auto & v : A){
        print_(v);
      }
      for(auto & v : A){
        print_(v);
        string str;
        for(auto x : v ) str.pb( x==0?'0':'1');
        debug(str);
        debug(bitset<32>(str).to_ulong());
        ans += bitset<32>(str).to_ulong();
        debug(ans);
      }
      debug("ans=",ans);
      return ans;
        
    }
};

int main( int argc, char * argv[] ){
  int n,m; cin >> n>> m;
  vvi v(n); for(auto & x : v ) { x.resize(m); input(x); }
  Solution sol;
  cout << sol.matrixScore(v) << '\n';

  return 0;
}
/*
We have a two dimensional matrix A where each value is 0 or 1.

A move consists of choosing any row or column, and toggling each value in that row or column: changing all 0s to 1s, and all 1s to 0s.

After making any number of moves, every row of this matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

Return the highest possible score.

 

Example 1:

Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
Output: 39
Explanation:
Toggled to [[1,1,1,1],[1,0,0,1],[1,1,1,1]].
0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39

 

Note:

    1 <= A.length <= 20
    1 <= A[0].length <= 20
    A[i][j] is 0 or 1.

*/
