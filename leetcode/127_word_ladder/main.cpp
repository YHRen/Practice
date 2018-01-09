#include <vector>
#include <unordered_set>
#include <unordered_map>
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
//  https://leetcode.com/problems/word-ladder/
//  Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
// 1. Only one letter can be changed at a time
// 2. Each intermediate word must exist in the word list
// For example,
//
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5. 

// solution: it seems a search (bfs or dfs) on a unweighted undirected graph.
// ... if word diff == 1, form an edge


class Solution {
  private:
    vector<vector<int>> graph;
    unordered_map<string,int> dict;
    inline bool is_diffone( const string & lhs, const string & rhs ) const{
      // lhs.len == rhs.len
      int cnt = 0; //
      for( int i = 0; i < lhs.length(); ++i ){
        if( lhs[i] != rhs[i] ) cnt ++;
        if( cnt > 1 ) return false;
      }
      return cnt == 1;
    }
    int bfs( int s, int t ) const {
      vector<bool> is_visited( graph.size(), false );
      vector<int>  distance( graph.size(), numeric_limits<int>::max() );
      is_visited[s] = true;
      distance[s]   = 1;
      queue<int> Q;
      Q.push(s);
      while( !Q.empty() ){
        int cur = Q.front();
        Q.pop();
        for( auto neighbor : graph[cur] ){
          if( !is_visited[neighbor] ){
            if( neighbor == t ) return distance[cur]+1;
            is_visited[neighbor] = true;
            distance[neighbor] = distance[cur] + 1;
            Q.push(neighbor);
          }
        }
      }
      return 0;
    }

  public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
      if( is_diffone( beginWord, endWord ) ){
        return 2;
      }
      if( wordList.empty() ) return 0;
      
      // can we change wordList ?
      wordList.insert(beginWord);
      wordList.insert(endWord);
      graph.resize( wordList.size() );
      int idx = 0;
      vector<string> v(wordList.begin(), wordList.end());
      for( const auto & word : v ){
        dict[word] = idx;
        idx++;
      }
      for( size_t i = 0; i < v.size(); ++i ){
        for( size_t j = i+1; j < v.size(); ++j ){
          if( is_diffone( v[i], v[j] ) ){
            graph[i].push_back(j);
            graph[j].push_back(i);
          }
        }
      }
      return bfs( dict[beginWord], dict[endWord] );
    }
};
int main( int argc, char * argv[] ){
  std::ios::sync_with_stdio(false);
  int n,t; cin >> n >> t;
  unordered_set<string> dict;
  forall(i,0,n){
    string str;
    cin >> str;
    debug(str);
    dict.insert(str);
  }
  Solution s;
  while(t--){
    string beginWord, endWord;
    cin >> beginWord >> endWord;
    debug( beginWord, endWord );
    cin >> beginWord >> endWord;
    cout << s.ladderLength( beginWord, endWord, dict ) << '\n';
  }




  return 0;
}
