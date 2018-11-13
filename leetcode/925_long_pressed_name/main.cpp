#include <vector>
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
// std::cin.tie(NULL);
/******* Actual Code Starts Here *********/
class Solution {
public:
    int find_next_same( string & str, int start ){
        char x = str[start];
        start ++;
        for(; start != str.size(); ++start){
            if( str[start] != x ) break; 
        }
        return start;
    }

    bool isLongPressedName(string name, string typed) {
        int n = name.size(), m = typed.size();
        if (n>m) return false;
        if (name[0] != typed[0]) return false;
        int i=0, j = 0;
        while( i!= n && j !=m){
            if( name[i] == typed[j] ){
                i ++;
                j ++;
            }else if( typed[j] == name[i-1] ){
                j ++;
            }else{
                return false;
            }
        }
        if( i == n ) return true;
        else return false;
    }
};

int main( int argc, char * argv[] ){
    Solution sol;
    cout << sol.isLongPressedName("alex", "aaleex") << '\n';
    cout << sol.isLongPressedName("saeed", "ssaaedd") << '\n';
    cout << sol.isLongPressedName("leelee", "lleeeelee") << '\n';
    cout << sol.isLongPressedName("laiden", "laiden") << '\n';


  return 0;
}
