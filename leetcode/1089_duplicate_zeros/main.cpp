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
    void duplicateZeros(vector<int>& arr) {
      int i = 0, j = 0;
      int mask = (1<<8)-1;
      int n = sz(arr);
      while( i < n and j < n ){
        debug("i=",i,"j=",j,arr[i],arr[j]);
        print_(arr);
        if( (arr[i]&mask) != 0 ){
          arr[j] |= (arr[i]&mask)<<8;
          i++; j++;
        }else{
          j+=2;
          i++;
        }
      }
      //    while( (arr[j] & mask)==0 and j < i ) ++j;
      //    arr[i] |= (arr[j] & mask)<<8;
      //    ++i;
      //    ++j;
      //  }else{
      //    i+=2;
      //  }
      //}
      forall(i,0,n){
        arr[i] >>= 8;
      }
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  Solution sol;
  sol.duplicateZeros(v);
  print_(v);
  return 0;
}
