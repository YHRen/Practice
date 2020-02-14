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
#define trace(...)       __f(#__VA_ARGS__, __VA_ARGS__)
#define debug(args...)   {dbg,args; clog<<endl;}
#define print_( a )      for( auto & x : a ) clog << x << ' '; clog << '\n';
#define printPair_( a )  for( auto & x : a ) clog << '(' << x.first << ',' << x.second << ')' << ' '; clog << '\n';
#else
#define trace(...)       
#define debug(args...)            
#define print_( a )               
#define printPair_( a )           
#endif

struct debugger {
  template<typename T> debugger& operator , (const T& x) {    
    clog << x << " ";    return *this;    
  }
}dbg;

template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

auto ____ =[]() { std::ios::sync_with_stdio(0); cin.tie(0); return nullptr; }();

//## commments: 
//### unique tweetname and time.?
//### **inclusive** starttime endtime.
//### stattime not 0, new example
//### contradicting example. interval[0,60] only 1, but next [0,59] is another interval
//### if no event, should output 0?
//
class TweetCounts {
  unordered_map<string, multiset<int>> rec;
  unordered_map<string, int> mode2sec;
  public:
    TweetCounts() {
      mode2sec["minute"] = 60;
      mode2sec["hour"] = 3600;
      mode2sec["day"] = 24*3600;
    }

    void recordTweet(string tweetName, int time) {
      rec[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
      debug("gettweet", freq, tweetName, startTime, endTime);
      int f = mode2sec[freq];
      if( rec.find(tweetName) == rec.end() ){
        return vi((endTime-startTime+1)/f, 0);
      }
      auto & d = rec[tweetName];
      auto itr = d.lower_bound(startTime);
      int t = startTime;
      vi res = {};
      while(itr!=d.end() and t < endTime+1 ){
        auto itr_nxt = lower_bound(itr, d.end(), min(t+f,endTime+1));
        int r = 0;
        while(itr!=itr_nxt){
          r++;
          ++itr;
        }
        res.pb(r);
        t += f;
      }
      while(t<endTime+1){
        res.pb(0);
        t+=f;
      }
      trace(t, endTime);
      return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
int main( int argc, char * argv[] ){
  TweetCounts tweetCounts = TweetCounts();
  tweetCounts.recordTweet("tweet3",0);
  tweetCounts.recordTweet("tweet3",60);
  tweetCounts.recordTweet("tweet3",10);                            // All tweets correspond to "tweet3" with recorded times at  0, 10 and 60.
  tweetCounts.getTweetCountsPerFrequency("hour","tweet3",0,60);    // return [3]. Since we want to count tweets at every hour (3600 seconds), there is only one interval of time [0,60] - > 3 tweets.
  tweetCounts.getTweetCountsPerFrequency("minute","tweet3",0,60);  // return [2,1]. Since we want to count tweets at every minute (60 seconds), there are two intervals of time: 1) [0,59] - > 2 tweets, and 2) [60,60] - > 1 tweet. 
  tweetCounts.recordTweet("tweet3",120);
  tweetCounts.getTweetCountsPerFrequency("minute","tweet3",0,210); // return [2,1,1,0]
  return 0;
}
