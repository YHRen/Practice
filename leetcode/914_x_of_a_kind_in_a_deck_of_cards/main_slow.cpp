#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
#include <bitset>
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/

class Solution {

static const int MAX_PR = 50000;
bitset<MAX_PR> isprime;
vi eratosthenes_sieve(int lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (int i = 4; i < lim; i += 2) isprime[i] = 0;
	for (int i = 3; i*i < lim; i += 2) if (isprime[i])
		for (int j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	forall(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}
public:
    bool hasGroupsSizeX(vector<int>& deck) {
      unordered_map<int,int> dict;
      for(auto x : deck) dict[x] += 1;
      if( dict.size() == 1 && dict.begin()->second > 1 ) return true;
      vi counts;
      for(auto p : dict) counts.pb(p.second);
      sort(all(counts));
      print_(counts);
      auto pr = eratosthenes_sieve(5000);
      print_(pr);

      for(auto p : pr){
        debug("p",p);
        bool flag = true;
        for(auto x : counts ){
          if( x < p || (x%p != 0) ){
            debug("in", x, p );
            flag = false;
            break;
          }
        }
        debug("flag",flag);
        if( flag ) return true;
      }
      return false;
    }

};

int main( int argc, char * argv[] ){
  cout << "gcd " << __gcd(8,0) << ' ' << __gcd(0,0) << '\n';
  Solution sol;
  vi v = {1,1,2,2,2,2};
  cout << sol.hasGroupsSizeX(v) << '\n';

  return 0;
}
