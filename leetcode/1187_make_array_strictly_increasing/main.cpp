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

// auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();
class Solution {
  int n, m;
  vii cur, nxt;

  public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
       n = sz(arr1); if(n==1) return 0;
       sort(all(arr2));
       arr2.erase( unique(all(arr2)), arr2.end() );
       m = sz(arr2);
       debug("arr1=", n);
       print_(arr1);
       debug("arr2=", m);
       print_(arr2);

       if( m == 0 ) return is_sorted(all(arr1)) ? 0 : -1;
       cur.pb( mp( arr1[0], 0 ) );
       if( arr2[0] < arr1[0] ) cur.pb( mp(arr2[0], 1) ); // replace the first one
       forall( i, 1, n ){// 
         debug("i=",i, "v[i]=", arr1[i]);
         printPair_(cur);
         {
           // if current is large
           auto itr = upper_bound( cur.rbegin(), cur.rend(), mp(arr1[i],0) );
           if( itr == cur.rend() ){ 
             nxt.pb( mp( arr1[i] , cur.begin()->second ) );
           }else if( itr == cur.rbegin() ){
             // arr1[i] too small
           }else{
             itr --;
             nxt.pb( mp( arr1[i], itr->second ) );
           }
         }
         {
           for(auto & p : cur){
             auto itr = upper_bound(all(arr2), p.first);
             if( itr != arr2.end() ){
               nxt.pb( mp( *itr, p.second + 1 ) );
             }
           }
         }
         if( nxt.empty() ) return -1;
         if( sz(nxt) == 1 ){
           swap(nxt, cur);
           nxt.clear();
         }else{
           map<int,int> dic;
           for(auto & p : nxt){
             if( auto itr = dic.find(p.second); itr == dic.end() ){
               dic[p.second] = p.first;
             }else{
               itr->second = min( itr->second, p.first );
             }
           }
           cur.clear();
           for(auto & p : dic){
             cur.pb(mp(p.second, p.first));
           }
           nxt.clear();
         }
       }
       int ans = INF;
       for(auto & p : cur){
         ans = min(ans, p.second);
       }
       return ans;
         
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m; 
  vi v(n); input(v);
  vi u(m); input(u);
  Solution sol;
  cout << sol.makeArrayIncreasing(v,u) << endl;
  return 0;
}
