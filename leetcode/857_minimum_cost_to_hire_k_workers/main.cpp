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
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
      int n = q.size();
      // cmp by w/q
      auto cmp = [&q, &w](const int l, const int r){
        if( w[l] * q[r] > w[r] * q[l] ) return true;
        else return false;
      };

      // cmp by w small to large
      auto cmp_q = [&q](const int l, const int r){
        if( q[l] <= q[r] ) return true;
        else return false;
      };

      vi v(n), u(n);
      iota(all(v),0);
      iota(all(u),0);
      sort(all(v),cmp);
      sort(all(u),cmp_q);

      vi is_visited(n,0);
      unordered_set<int> bag; // keep k-1 elements in the bag, based on the quality
      double running_quality = 0.0, min_wage = INF;
      forall(k,0,K-1){ bag.insert(u[k]); running_quality += q[u[k]]; }
      int r = K-1; // next candidate

      forall(i,0,n-K+1){
        int idx = v[i];
        debug("i", "idx=",idx,"w/q", w[idx], q[idx]);
        if( bag.find(idx) != bag.end() ){
          bag.erase(idx);
          running_quality -= q[idx];
          while( r < n ){
            if( is_visited[u[r]] == false ){
              debug("finding ", r, u[r], "with", q[u[r]]);
              bag.insert(u[r]);
              running_quality += q[u[r]];
              debug("running_quality ", running_quality );
              r++;
              break;
            }
            r++;
          }
        }
        debug("running quality=", running_quality);
        double tmp_wage = double(w[idx]) + double(w[idx])/double(q[idx]) * running_quality;
        debug("tmp wage = ", tmp_wage);
        min_wage  = min( min_wage, tmp_wage );
        is_visited[idx] = true;
      }
      return min_wage;
    }
};
int main( int argc, char * argv[] ){
  int n, k; cin >> n >> k;
  vi q(n), w(n);
  input(q); input(w);
  Solution sol;
  cout << sol.mincostToHireWorkers(q,w,k) << '\n';

  return 0;
}


/*
There are N workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly K workers to form a paid group.  When hiring a group of K workers, we must pay them according to the following rules:

    Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
    Every worker in the paid group must be paid at least their minimum wage expectation.

Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], K = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.

Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], K = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 

 

Note:

    1 <= K <= N <= 10000, where N = quality.length = wage.length
    1 <= quality[i] <= 10000
    1 <= wage[i] <= 10000
    Answers within 10^-5 of the correct answer will be considered correct.

*/
