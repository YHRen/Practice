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
class Solution {
public:
    int findMaximizedCapital(const int K, int W, vector<int>& Profits, vector<int>& Capital) {
      int n = sz(Profits);
      vi idx(n);
      iota(all(idx),0);
      sort(all(idx),[&Profits,&Capital](int lhs, int rhs){
          if( Capital[lhs] < Capital[rhs] ) return true;
          else if(  Capital[lhs] == Capital[rhs] and Profits[lhs] > Profits[rhs] ) return true;
          else return false;
          });
      priority_queue<int> pq;
      int i = 0;
      int k = 0;
      do{
        while( i!=n and Capital[idx[i]] <= W ){
          pq.push(Profits[idx[i]]);
          ++i;
        }
        if( pq.empty() ) return W;
        W += pq.top();
        k ++;
        pq.pop();
      }while(k<K);
      return W;
    }
};
int main( int argc, char * argv[] ){
  int n,k,w; cin >> n>>k>>w; 
  vi v(n); input(v);
  vi u(n); input(u);
  Solution sol;
  cout << sol.findMaximizedCapital(k,w,v,u) << '\n';
  return 0;
}
