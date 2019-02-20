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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
      int n = difficulty.size(), m = worker.size();
      vi idx(n); iota(all(idx),0);
      auto cmp = [&difficulty](int x, int y){ return difficulty[x] < difficulty[y]; };
      sort(all(idx),cmp);
      vii upto;
      int run = -1;
      forall(i,0,n){
        int id = idx[i];
        if( upto.empty() ){
          run = profit[id];
          upto.pb(mp(difficulty[id], profit[id]));
        }else{
          if( difficulty[id] == upto.rbegin()->first ){
            run = max(run, profit[id]);
            upto.rbegin()->second =  run;
          }else{
            run = max(run,profit[id]);
            upto.pb(mp(difficulty[id], run));
          }
        }
      }
      printPair_(upto);
      int ans = 0;
      forall(j,0,m){
        debug("worker ", j, worker[j]);
        auto itr = upper_bound(all(upto), mp(worker[j],INF));
        if(itr == upto.begin()) continue;
        else {
          --itr;
          debug("found ", itr->first, itr->second);
          ans += itr->second;
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  int n, m; cin >> n >> m;
  vi v(n), u(n), w(m); 
  input(v);
  input(u);
  input(w);
  print_(v);
  print_(u);
  print_(w);

  Solution sol;
  cout << sol.maxProfitAssignment(v,u,w) << '\n';

  return 0;
}
