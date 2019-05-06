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
class MedianFinder {
  multiset<int> S, L; 
  void balance_SL( ){
    if( sz(S) - sz(L) > 1 ){
      L.insert(*S.rbegin());
      S.erase(--S.end());
    }else if( sz(L)-sz(S) > 1 ){
      S.insert( *L.begin() );
      L.erase(L.begin());
    }
  }
  void insert_SL( int val){
    if( S.empty() or val <= *S.rbegin() ) S.insert(val);
    else L.insert(val);
  }
public:
    /** initialize your data structure here. */
    MedianFinder() {
      S.clear();
      L.clear();
    }
    
    void addNum(int num) {
      insert_SL(num);
      balance_SL();
    }
    
    double findMedian() {
      if( sz(S) == sz(L) )
          return (double)( (ll)*S.rbegin() + (ll)*L.begin() ) / 2;
      else
          return sz(S) > sz(L) ? *S.rbegin() : *L.begin();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
