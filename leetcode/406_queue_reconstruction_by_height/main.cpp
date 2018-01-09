#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <numeric>
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define bg     begin()
#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vi>  vvi;
typedef vector<ii>  vii;

#ifdef DEBUG
#define debug(args...)            {dbg,args; clog<<endl;}
#define print_( a )               for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )           for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define debug(args...)             // Just strip off all debug tokens
#define print_( a )               // skip
#define printPair_( a )           // skip
#endif
struct debugger
{
  template<typename T> debugger& operator , (const T& x)
  {    
    clog << x << " ";    
    return *this;    
  }
} dbg;

// std::ios::sync_with_stdio(false);
/******* Actual Code Starts Here *********/
class Solution {
  void put_in( const ii & p, list<ii> & L ){
    int m = p.second;
    auto itr = L.begin();
    for( ; itr != L.end(); ++itr){
      if( itr->first >= p.first ){
        --m;
        if( m == -1 ) break;
      }
    }
    if( itr == L.end() ){
      L.pb(p);
    }else{
      L.insert( itr, p );
    }
    printPair_(L);
  }

  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
      int n = people.size();
      if( n == 0 ) return people;
      auto comp = [](const ii & lhs, const ii & rhs){
          if( lhs.second < rhs.second ) return true;
          else if( lhs.second == rhs.second && lhs.first < rhs.first ) return true;
          else return false;
          };

      sort(all(people), comp);
      printPair_(people);
      auto itr = lower_bound( all(people), mp(INF,0), comp );
      if( itr == people.end() ) return people;
      list<ii> ans( people.begin(), itr);
      forall( i, itr - people.bg, n ){
        put_in( people[i], ans );
      }
      return vii(all(ans));
    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vii v(n);
  forall(i,0,n){
    cin >> v[i].first >> v[i].second;
  }
  printPair_(v);
  Solution sol;
  auto ans = sol.reconstructQueue(v);
  printPair_(ans);
  return 0;
}
