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
typedef long long    ll;

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
    int shortestSubarray(vector<int>& A, int K) {
      int n = A.size();
      vi v(n+1,0);
      forall(i,0,n){ v[i+1] = v[i] + A[i]; }
      print_(v);
      deque<int> q;
      int ans = INF;
      forall(i,0,n+1){
        while( !q.empty() and  v[i]-v[q.front()] >= K ){
          ans = min( ans, i-q.front() );
          q.pop_front();
        }
        while( !q.empty() and v[i] <= v[q.back()] ){
          q.pop_back();
        }
        q.push_back(i);
      }
      return ans == INF ? -1 : ans;
    }
};
int main( int argc, char * argv[] ){
  int n, k; cin >> n >> k;
  vi v(n); input(v);
  Solution sol;
  cout << sol.shortestSubarray(v, k) << '\n';


  return 0;
}

/*
Return the length of the shortest, non-empty, contiguous subarray of A with sum at least K.

If there is no non-empty subarray with sum at least K, return -1.

 

Example 1:

Input: A = [1], K = 1
Output: 1

Example 2:

Input: A = [1,2], K = 4
Output: -1

Example 3:

Input: A = [2,-1,2], K = 3
Output: 3

 

Note:

    1 <= A.length <= 50000
    -10 ^ 5 <= A[i] <= 10 ^ 5
    1 <= K <= 10 ^ 9

*/
