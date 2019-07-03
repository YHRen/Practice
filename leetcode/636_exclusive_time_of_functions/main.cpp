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
/*
On a single threaded CPU, we execute some functions.  Each function has a unique id between 0 and N-1.

We store logs in timestamp order that describe when a function is entered or exited.

Each log is a string with this format: "{function_id}:{"start" | "end"}:{timestamp}".  For example, "0:start:3" means the function with id 0 started at the beginning of timestamp 3.  "1:end:2" means the function with id 1 ended at the end of timestamp 2.

A function's exclusive time is the number of units of time spent in this function.  Note that this does not include any recursive calls to child functions.

The CPU is single threaded which means that only one function is being executed at a given time unit.

Return the exclusive time of each function, sorted by their function id.

 

Example 1:

Input:
n = 2
logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
Output: [3, 4]
Explanation:
Function 0 starts at the beginning of time 0, then it executes 2 units of time and reaches the end of time 1.
Now function 1 starts at the beginning of time 2, executes 4 units of time and ends at time 5.
Function 0 is running again at the beginning of time 6, and also ends at the end of time 6, thus executing for 1 unit of time. 
So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.

 

Note:

    1 <= n <= 100
    Two functions won't start or end at the same time.
    Functions will always log when they exit.

 */
class Solution {
  bool is_start( const string & str, int & id, int & time){
    vector<string> tmp;
    istringstream iss(str);
    for( string token; getline(iss, token, ':'); tmp.pb(token));
    id = stoi(tmp[0]);
    time = stoi(tmp[2]);
    return tmp[1] == "start";
  }

public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
      stack<int> S;
      int prev, id, time;
      vi res(n,0);
      for(auto & str : logs){
        if( is_start(str, id, time) ){
          if( !S.empty() )
            res[S.top()] += time - prev;
          S.push(id);
          prev = time;
        }else{
          res[S.top()] += time-prev+1;
          S.pop();
          prev = time+1;
        }
      }
      return res;
    }
};
int main( int argc, char * argv[] ){
  int n,m; cin >> n >> m ;
  vector<string> v(n); input(v);
  Solution sol;
  auto res = sol.exclusiveTime(m, v);
  print_(res);
  return 0;
}
