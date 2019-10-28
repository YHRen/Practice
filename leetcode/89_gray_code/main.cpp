class Solution {
public:
    vector<int> grayCode(int n) {
        if( n == 0 ) return {0};
        vector<int> v(1<<n);
        iota(v.begin(), v.end(), 0);
        for(auto & x : v) x ^= (x>>1);
        return v;
    }
};
