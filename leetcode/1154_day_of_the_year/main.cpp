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

int common_days [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap_days [] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Solution {
  bool is_leap_year( int yy ){
    if( yy%4 != 0 ) return false;
    else if( yy%100 != 0 ) return true;
    else if( yy%400 != 0 ) return false;
    else return true;
  }

  void parse( const string & date, 
      int & yy, int & mm, int & dd){
    yy = stoi(date.substr(0,4));
    mm = stoi(date.substr(5,2));
    dd = stoi(date.substr(8,2));
  }

public:
    int dayOfYear(string date) {
      int yy, mm, dd;
      parse(date, yy, mm, dd);
      debug(yy,mm,dd);
      mm--;
      int ans = 0;
      if( is_leap_year(yy) ){
        debug("leap year");
        forall(i,0,mm){ ans += leap_days[i]; }
      }else{
        debug("common year");
        forall(i,0,mm){ ans += common_days[i]; }
      }
      ans += dd;
      return ans;
    }
};


int main( int argc, char * argv[] ){
  string str; cin >> str; 
  Solution sol;
  cout << sol.dayOfYear(str) << endl;

  return 0;
}
