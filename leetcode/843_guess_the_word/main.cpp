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
#include <functional>
#include <cstring>
#include <cmath>
#include <cassert>


#define INF                         (int)1000000007
#define EPS                         1e-9

#define pb     push_back
#define mp     make_pair

#define all(c)                      c.begin(), c.end()
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define input( a )                  for( auto & x : a ) cin >> x;

using namespace std;

typedef vector<int>   vi;
typedef pair<int,int> ii;
typedef vector<vi>    vvi;
typedef vector<ii>    vii;
typedef long long     ll;

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
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class Master {
  string secret;
  public:
    Master( string s ) : secret(s){}
    int guess(string word){
      int ans = 0;
      forall(i,0,6) if( word[i] == secret[i] ) ans ++;
      return ans;
    }
};

class Solution {
  int N;
  int greedy_stratergy(const vvi & dp){
    vector<pair<ii,int>>  ord;
    forall(i,0,N){
      if( dp[i][i] != -1 ){
        set<int> s;
        int cnt = 0;
        for(auto x : dp[i]){
          if( x != 6 and x != -1 )
            s.insert(x);
          cnt ++;
        }
        ord.pb(mp(mp(s.size(), cnt), i));
      }
    }
    sort(all(ord));
    int max_id = ord.rbegin()->second;
    return max_id;
  }
  int minmax_stratergy( const vvi & dp ){
    // in the worst case, what is the best we can do.
    vi min_improv(N,INF);
    forall(i,0,N){
      if( dp[i][i] != -1 ){
        //int secret = i;
        forall(j,0,N){
          if( j != i and dp[j][j]!=-1 ){
            //int guess = j;
            int result = dp[i][j];
            int tmp = 0;
            forall(k,0,N){
              if(k!=i and k!=j and dp[j][k]!=-1 and dp[j][k] ==result) tmp++;
            }
            min_improv[j] = min( min_improv[j], tmp );
          }
        }
      }
    }
    for(auto & x : min_improv) x = x==INF?-1:x;
    return max_element(all(min_improv)) - min_improv.begin();
  }

public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
      int n = wordlist.size();
      N = n;
      int m = wordlist[0].size(); // = 6
      vvi dp(n, vi(n,0));
      forall(i,0,n) dp[i][i] = m;
      forall(i,0,n){
        forall(j,i+1,n){
          forall(k,0,m){
            if( wordlist[i][k] == wordlist[j][k] ) dp[i][j] ++;
          }
          dp[j][i] = dp[i][j];
        }
      }

      int r;
      int timeout=10;
      do{
        //int max_id = greedy_stratergy(dp);
        int max_id = minmax_stratergy(dp);
        debug(" guessing work ", wordlist[max_id], max_id );
        r = master.guess( wordlist[max_id] );
        debug("r = ", r);

        forall(i,0,n){
          if( dp[max_id][i] != r ){
            dp[max_id][i] = -1;
            dp[i][max_id] = -1;
          }
        }
      }while(r!=6 and timeout-->0);

    }
};
int main( int argc, char * argv[] ){
  int n; cin >> n;
  vector<string> w(n);
  input(w);
  string secret; cin >> secret;
  Master mst(secret);
  Solution sol;
  sol.findSecretWord( w, mst);
  


  return 0;
}
