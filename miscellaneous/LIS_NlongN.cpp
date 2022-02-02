/*

   link to the problem: https://leetcode.com/problems/longest-increasing-subsequence/submissions/

 */


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> d(nums.size(), INT32_MAX);

        for(int const& num: nums){
            int at = std::lower_bound(d.begin(), d.end(), num) - d.begin();
            d[at] = num;
        }
        
        return std::lower_bound(d.begin(), d.end(), INT32_MAX) - d.begin(); 
    }
};
