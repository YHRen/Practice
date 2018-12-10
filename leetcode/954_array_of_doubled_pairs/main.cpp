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
  bool C(const vi & v){
    int n = v.size();
    map<int, queue<int>> dict;
    forall(i,0,n){ dict[v[i]].push(i); }
    vi is_visited(n,0);
    forall(i,0,n){
      if( is_visited[i] ) continue;
      is_visited[i] = true;
      auto itr = dict.find(2*v[i]);
      if( itr == dict.end() || itr->second.empty() ) return false;
      else{
        int idx = itr->second.front();
        is_visited[idx] = true;
        itr->second.pop();
      }
    }
    return true;
  }
public:
    bool canReorderDoubled(vector<int>& A) {
      int n = A.size(); 
      if(n == 0) return true;
      int min_elm = *min_element(all(A));
      int max_elm = *max_element(all(A));
      if (min_elm < -50000 || max_elm > 50000) return false;
      vi pos, neg;
      forall(i,0,n) if( A[i] < 0 ) neg.pb(-A[i]); else pos.pb(A[i]);
      if(neg.size()%2 != 0 || pos.size()%2 != 0) return false;
      sort(all(pos));
      sort(all(neg));
      if( C(pos) && C(neg) ) return true;
      else return false;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.canReorderDoubled(v) << '\n';

  return 0;
}
