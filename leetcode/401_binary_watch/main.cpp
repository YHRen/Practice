#include <vector>
#include <queue>
#include <stack>
#include <limits>
#include <iostream> 
#include <iomanip>  
#include <string>
#include <sstream>  
#include <algorithm>
#include <cmath>
#include <cassert>

#define input(v)                  for(int i = 0; i < v.size(); ++i){ cin >> v[i]; }

// numeric_limits
#define INF                         (int)1e9
#define EPS                         1e-9

#define bitcount                    __builtin_popcount
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define all(a)                      a.begin(), a.end()
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())
typedef unsigned long long int ull_t;
typedef long long int           ll_t;

using namespace std;

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

/******* Actual Code Starts Here *********/
// https://leetcode.com/problems/binary-watch/
// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
//
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
// Example:
// Input: n = 1
// Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
// Note:
//    The order of output does not matter.
//    The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
//    The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
//

// solution: 
// ... produce possible hours and possible minutes. 
// ... notice the overflow, as hours [0-11] and minutes [0-59]
class Solution {
  private:
    vector<vector<string>> get_hours( int n ){
      n = max(n,4); // max 4 bits
      vector<vector<string>> str(n+1);
      for( uint16_t i = 0; i < 12; ++i ){
        int num_set = __builtin_popcount( i );
        if( num_set <= n ){
          str[num_set].push_back( to_string(i) );
        }
      }
      return str;
    }
    vector<vector<string>> get_minutes( int n ){
      n = max(n,6); // max 6 bits
      vector<vector<string>> str(n+1);
      for( uint16_t i = 0; i < 60; ++i ){
        int num_set = __builtin_popcount( i );
        if( num_set <= n ){
          if( i < 10 ){
            str[num_set].push_back( "0" + to_string(i) );
          }else{
            str[num_set].push_back( to_string(i) );
          }
        }
      }
      return str;
    }

  public:
    vector<string> readBinaryWatch(int num) {
      vector<string> str;
      if( num < 0 ) return str;
      vector<vector<string>> hours = get_hours(num);
      vector<vector<string>> minutes = get_minutes(num);
      for( int i = 0; i < hours.size(); ++i ){
        int j = num-i;
        if( j < minutes.size() && j >= 0 ){
          for( int l = 0; l < hours[i].size(); ++l ){
            for( int k = 0; k < minutes[j].size(); ++k ){
              str.push_back( hours[i][l] + ':' + minutes[j][k] );
            }
          }
        }
      }
      return str;
    }

};


int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n; cin >> n;
  Solution s;
  vector<string> rst = s.readBinaryWatch( n );
  for( auto & x : rst ){
    cout << x << '\n';
  }





  return 0;
}
