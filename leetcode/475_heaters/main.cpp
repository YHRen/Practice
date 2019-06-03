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
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      sort(all(houses));
      sort(all(heaters));
      int r = 0;
      for(auto itr1 = houses.begin(), itr2 = heaters.begin(); itr1!= houses.end(); ++itr1){
        if( itr2==heaters.end() ){ r = max(r, *itr1 - heaters.back()); }
        else if( *itr1 == *itr2 ) ++itr2;
        else if( *itr1 > *itr2 ){
          while(itr2!=heaters.end() and *itr2 < *itr1){
            ++itr2;
          }
          if( itr2 == heaters.end() ){ 
            r = max(r, *itr1 - heaters.back());
          }else{
            r = max(r, min( *itr2 - *itr1, itr2 == heaters.begin() ? INF : *itr1-*(itr2-1)));
          }
        }else{ // *itr1 < *itr2
          r = max(r, min( *itr2 - *itr1, itr2 == heaters.begin() ? INF : *itr1-*(itr2-1)));
        }
      }
      return r;
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
