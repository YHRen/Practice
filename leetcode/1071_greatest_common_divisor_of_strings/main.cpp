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
  bool is_sub(const string & str, const string & pat){
    int n = sz(str), m = sz(pat);
    if( n%m!= 0 ) return false;
    int p = n/m;
    forall(j,0,p){
      forall(i,0,m){
        if( str[j*m+i] != pat[i] ) return false;
      }
    }
    return true;
  }

public:
    string gcdOfStrings(string str1, string str2) {
      int n = sz(str1), m = sz(str2);
      if( n < m ){ swap(n,m); swap(str1, str2);}
      if( n==m and str1 == str2 ) return str1;
      int i = 0;
      for(i =0; i < m; ++i ){
        if( str1[i] != str2[i] ) return "";
      }
      debug("i==",i);
      while( i > 0 ){
        debug("i=",i);
        if( m%i != 0 or n%i != 0 ){
          --i;
        }else{
          debug("iiii=",i);
          string tmp = str2.substr(0,i);
          debug("tmp",tmp);
          if( is_sub(str2,tmp) and is_sub(str1,tmp) ) return tmp;
          --i;
        }
      }
      return "";
    }
};
int main( int argc, char * argv[] ){
  string A,B; cin >> A >> B;
  Solution sol;
  cout << sol.gcdOfStrings(A,B) << endl;
  return 0;
}
