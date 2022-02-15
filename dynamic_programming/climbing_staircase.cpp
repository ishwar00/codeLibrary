/**
 *
 *
 * problem link: https://leetcode.com/problems/climbing-stairs/
 *
 * */


class Solution {
public:
    int climbStairs(int const N) {
        vector<int64_t> dp(N + 1);
        dp[0] = 1;
        
        for(int i = 1; i <= N; ++i){
            dp[i] = dp[i - 1] + (i > 1 ? dp[i - 2]: 0);
        }
        return dp.back();
    }
};
