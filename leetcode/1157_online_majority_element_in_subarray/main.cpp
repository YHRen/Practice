#include <random>
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
class MajorityChecker {
  static constexpr int M = 100;
  int n;
  vi v;
  mt19937 rng;
  vi buf;
  unordered_map<int,vi> dict;
  ii get_max_elm(vector<int>::const_iterator l, vector<int>::const_iterator r){
    int max_elm = *l, run = 1;
    for(auto i = l+1; i!=r; ++i){
      if( *i == max_elm ) run ++;
      else run --;
      if( run == 0 ){
        max_elm = *i;
        run = 1;
      }
    }
    int res = count_if( l, r , [max_elm](int x){ return x==max_elm; });
    return mp(max_elm, res);
  }
  int get_counts_in_range(int x, int l, int r){
    const auto &  u = dict[x];
    return upper_bound( all(u), r) - lower_bound(all(u), l);
  }
  public:
    MajorityChecker(vector<int>& arr) {
      n = sz(arr);
      swap(v,arr);
      forall(i,0,n) dict[v[i]].pb(i);
      random_device rd;
      rng = mt19937(rd());
      buf.resize(M);
    }

    int query(int left, int right, int threshold) {
      int len = right - left + 1;
      if( threshold > len ) return -1;
      int max_elm = v[left], run = 1;
      if( len < 100 ){
        auto [elm, cnt] = get_max_elm(v.begin()+left, v.begin()+right+1);
        if( cnt >= threshold ) return elm;
        else return -1;
      }else{ // prob method
        uniform_int_distribution<int> dist(left, right);
        forall(i,0,M){ 
          int elm = v[dist(rng)];
          int cnt = get_counts_in_range(elm, left, right);
          if( cnt >= threshold ) return elm;
        }
        return -1;
      }
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
int main( int argc, char * argv[] ){
  int n; cin >> n; 
  vi v(n); input(v);
  return 0;
}
