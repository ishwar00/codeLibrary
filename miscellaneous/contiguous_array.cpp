/*
 *
 * link problem: https://leetcode.com/problems/contiguous-array/
 *
 * */

#include<bits/stdc++.h>

class Solution {
public:
    int findMaxLength(vector<int> const& nums) {
        int max_length = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += (nums[i] ? 1 : -1);
            if (mp.find(sum) != mp.end()) {
                max_length = max(
                    max_length, 
                    sum ? (i - mp[sum]) : i + 1
                );
            } else {
                mp[sum] = i;
            }
        }
        return max_length;
    }
};


