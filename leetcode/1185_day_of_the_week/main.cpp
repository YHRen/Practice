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
  int days_in_month[2][12]={
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  vector<string> months = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  bool is_leap_year( int year ){
    return (year%4==0 and year%100 != 0) || (year%400==0) ;
  }

  int days_from_1971( int day, int month, int year ){
    int days = 0;
    int y = 1971;
    for( int y = 1971; y < year; ++y ){
      days += is_leap_year(y) ? 366 : 365; 
    }
    int m = 1;
    for( int yL = is_leap_year(year), m=1; m != month; m++){
      days += days_in_month[yL][m-1];
    }
    days += day-1;
    return days;
  }

  public:
    string dayOfTheWeek(int day, int month, int year) {
      int x = days_from_1971(day, month, year);
      return months[ (5+x)%7 ];
    }
};
int main( int argc, char * argv[] ){
  int d,m,y; cin >> d >> m >> y;
  Solution sol;
  cout << sol.dayOfTheWeek(d,m,y) << ' ' << "Saturday\n";
  return 0;
}
