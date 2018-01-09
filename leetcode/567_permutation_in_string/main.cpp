#include <vector>
#include <bitset>
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
  private:
    vi cnt,bnt;
    bool C(){
      forall(l,0,26){
        if( bnt[l] != cnt[l] ) return false;
      }
      return true;
    }

  public:
    bool checkInclusion(string s1, string s2) {
      if( s1.size() > s2.size() ) return false;
      cnt.resize(26,0);
      bnt.resize(26,0);
      for( auto c : s1 ) cnt[c-'a']++;
      forall(i,0,s1.size()) bnt[s2[i]-'a']++;
//      uint32_t check = (1<<26)-1;
//      forall(i,0,26){
//        if( cnt[i] == bnt[i] ){
//          check &= ~(1<<i);
//        }
//      }

//      if( !check ) return true;
      if( C() ) return true;
      int n = s1.size();
      forall(i,n,s2.size()){
        debug("i=",i, "c=",s2[i]);
        int j = i - n;
        int k1 = s2[j]-'a';
        int k2 = s2[i]-'a';
        if( k1 == k2 ) continue;
        bnt[k1] --;
        bnt[k2] ++;
        /*
        bool bit = check & (1<<k1);
        if( bit && bnt[k1]==cnt[k1]){
          check &= ~(1<<k1);
        }else if( !bit && bnt[k1]!= cnt[k1]){
          check |= (1<<k1);
        }
        bit = check | (1<<k2);
        if( bit && bnt[k2]==cnt[k2]){
          check &= ~(1<<k2);
        }else if( !bit && bnt[k2]!= cnt[k2]){
          check |= (1<<k2);
        }
        if( !check ) return true;
        */
        bool flag = true;
        forall(l,0,26){
          if( bnt[l] != cnt[l] ){
            flag = false;
            break;
          }
        }
        if( flag ){
          print_(cnt);
          print_(bnt);
          return true;
        }
      }
      return false;
    }
};
int main( int argc, char * argv[] ){
  string s1,s2;
  cin >> s1 >> s2;
  Solution sol;
  cout << sol.checkInclusion(s1,s2) << '\n';


  return 0;
}
