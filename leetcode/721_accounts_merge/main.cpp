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
#define forall(i,a,b)               for(int i=a;i<(b);++i)
#define trav(a,x)                   for(auto & a: x)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define sz(c)                       (int)(c).size()
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

auto ____ =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

// std::ios::sync_with_stdio(false);
// std::cin.exceptions(cin.failbit);
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

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      unordered_map<string, vi> email_map;
      int n = sz(accounts);
      forall(i,0,n){
        forall(j,1,sz(accounts[i])){
          email_map[accounts[i][0] + "$" + accounts[i][j]].pb(i);
        }
      }
      UF uf(n);
      for(auto & p : email_map){
        if( p.second.size() == 1 ) continue;
        int m = p.second.size();
        auto & u = p.second;
        forall(i,0,m){
          forall(j,i+1,m){
            uf.join(u[i],u[j]);
          }
        }
      }
      forall(i,0,n){
        int p = uf.find(i);
        if( p == i ) continue;
        forall(j,1,sz(accounts[i])){
          accounts[p].pb(accounts[i][j]);
        }
      }
      vector<vector<string>> ans;
      forall(i,0,n){
        if( uf.find(i) == i ){
          sort(all(accounts[i]));
          accounts[i].erase( unique(all(accounts[i])), accounts[i].end());
          ans.pb(accounts[i]);
        }
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){

  return 0;
}
