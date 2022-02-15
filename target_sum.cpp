/**
 *
 *
 * problem link: https://leetcode.com/problems/target-sum/
 *
 *
 **/


class Solution {
public:
    
    int findTargetSumWays(vector<int> const& nums, int const target) {
        int sum = accumulate(nums.begin(), nums.end(), 0LL);
        int sum_target = sum + target;
        int new_target = sum_target / 2;
        int N = nums.size();
        
        if((sum_target & 1) or new_target < 0 or new_target > sum) return 0;
        
        vector<int> dp(new_target + 1);
        dp[0] = 1;
        for(int i = 0; i < N; ++i) {
            for(int j = new_target; j >= 0; j = j - 1) {
                if(nums[i] <= j) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        
        return dp.back();
    }
};
