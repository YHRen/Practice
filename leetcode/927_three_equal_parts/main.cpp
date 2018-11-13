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
    vi cum;
    int l;
public:
    vector<int> threeEqualParts(const vector<int>& A) {
        int n = A.size();
        int ones = 0;
        {
            int total_ones = count_if(all(A), [](int x){ return x==1; });
            if(total_ones   == 0) return {0,2};
            if(total_ones%3 != 0) return {-1,-1};
            ones = total_ones/3;
        }

        int right_start = -1;
        int left_start =  -1;
        for( int i = n-1, cnt=0; i >= 0; --i ){
            if( A[i] == 1 ){
                ++cnt;
                if( cnt == ones ){
                    right_start = i;
                    break;
                }
            }
        }
        int l = n-right_start;
        forall(i,0,n){
            if( A[i] == 1 ){
                left_start = i;
                break;
            }
        }

        debug("left start = ", left_start, "right start = ", right_start);

        if( equal( A.begin()+right_start, A.end(), A.begin()+left_start ) ){
            int mid_start = -1;
            forall(i, left_start + (n-right_start), right_start ){
                if( A[i]==1 ){ 
                    mid_start = i;
                    break;
                }
            }
            debug(" mid start = ", mid_start );
            if( equal( A.begin() + right_start,  A.end(), A.begin() + mid_start ) ){
                return {left_start+l-1, mid_start+l};
            }else{
                return {-1, -1};
            }
        }else{
            return {-1, -1};
        }

    }

};

int main( int argc, char * argv[] ){
    int n; cin >> n;
    vi A(n);
    input(A);
    Solution sol;
    auto ans = sol.threeEqualParts(A);
    cout << ans[0] << ' ' << ans[1] << '\n';

  return 0;
}
