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
  private:
    int n;
    string str;
  public:
  vii get_segments( char c ){ 
    vii ans;
    int left = -1;
    forall(i,0,n){
      if(str[i] == c and left == -1){
          left = i;
      }else if( str[i] != c and left != -1){
          ans.pb(mp(left,i));
          left = -1;
      }
    }
    if(left != -1) ans.pb(mp(left,n));
    return ans;
  }

  int get_consecutive_length( int start ){
    int end = start+1;
    while( end != n and str[end] == str[start] ){
      end ++;
    }
    return end - start;
  }
  
  int get_seg_len( ii seg ){
    return seg.second - seg.first;
  }

  int maxRepOpt1(string text) {
    swap(str, text);
    n = str.size();
    int ans = 0;
    for(char c = 'a'; c <= 'z'; c++){
      auto segs = get_segments(c);
      if( segs.empty() ) continue;
      if( segs.size() == 1 ) ans = max(ans, get_seg_len(segs[0]));
      else if( segs.size() == 2 ){
        if ( segs[1].first - segs[0].second == 1 )
          ans = max(ans, get_seg_len(segs[0])+get_seg_len(segs[1]));
        else
          ans = max(ans, 1+max(get_seg_len(segs[1]), get_seg_len(segs[0])));
      }else{ // > 2 
        forall(i,1,sz(segs)){
          ans = max(ans, get_seg_len(segs[0])+1);
          if( segs[i].first - segs[i-1].second == 1 ){
            ans = max(ans, get_seg_len(segs[i-1]) + get_seg_len(segs[i]) + 1 );
          }else{
            ans = max(ans, 1+get_seg_len(segs[i]));
          }
        }
      }
    }
    return ans;
  }
};
int main( int argc, char * argv[] ){
  string str; cin >> str;
  Solution sol;
  cout << sol.maxRepOpt1(str) << endl;
  return 0;
}
