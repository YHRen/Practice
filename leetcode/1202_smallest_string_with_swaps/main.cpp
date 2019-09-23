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
#include <complex>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF              (int)1000000007
#define EPS              1e-9
#define pb               push_back
#define mp               make_pair
#define all(c)           c.begin(), c.end()
#define forall(i,a,b)    for(int i=a;i<(b);++i)
#define trav(a,x)        for(auto & a: x)
#define in(a,b)          ((b).find(a) != (b).end())
#define sz(c)            (int)(c).size()
#define input(a)         for(auto & x : a) cin >> x;

using namespace std;

typedef vector<int>      vi;
typedef pair<int,int>    ii;
typedef vector<vi>       vvi;
typedef vector<ii>       vii;
typedef long long        ll;

#ifdef DEBUG
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = sz(s);
      if( n == 1 ) return s;
      UF uf(n);
      for(auto & p:pairs){ uf.join(p[0], p[1]);}
      int max_size = 0;
      forall(i,0,n) max_size = max(max_size, uf.size(i));
      unordered_map<int, string> cache;
      forall(i,0,n) cache[uf.find(i)].pb(s[i]);
      for(auto & p : cache){
        sort(all(p.second));
        debug(p.first, p.second);
      }
      debug("cluster sz = ", sz(cache));
      unordered_map<int,int> idx;
      string ans;
      forall(i,0,n){
        int cls_id = uf.find(i);
        if( idx.find(cls_id) ==idx.end() ) idx[cls_id] = 0;
        debug("i=",i,"cls_id=",cls_id);
        ans.pb( cache[cls_id][idx[cls_id]++] );
      }
      return ans;
    }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  int n; cin >> n; 
  vvi v(n,vi(2)); 
  for(auto & p: v) input(p);
  Solution sol;
  cout << sol.smallestStringWithSwaps(str, v) << endl;
  return 0;
}
