#include <vector>
#include <bitset>
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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool same_set(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	void join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
	}
};



class Solution {
  int n;
public:
    int largestComponentSize(vector<int>& A) {
      print_(A);
      n = A.size();
      UF uf(n);
      unordered_map<int,vi> dict;
      forall(i,0,n){
        int x = A[i];
        for(int p = 2; p*p <= x; ++p ){
          if( x%p == 0 ){
            dict[p].pb(i);
            while(x%p==0) x/=p;
          }
        }
        if( x > 1 ) dict[x].pb(i);
      }
      for(auto p : dict ){
        const auto & v = p.second;
        int m = v.size();
        debug(p.first);
        print_(v);
        forall(i,1,m){
          uf.join(v[0], v[i]);
        }
      }
      int ans = 1;
      forall(i,0,n){
        ans = max(ans, uf.size(i));
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n; cin >> n;
  vi v(n); input(v);
  Solution sol;
  cout << sol.largestComponentSize(v) << '\n';

  return 0;
}
