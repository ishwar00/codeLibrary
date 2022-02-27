/*
 *
 * link problem: https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/#
 *
 *
 * **/


class Solution {
public:
    //Function to count subarrays with 1s and 0s.
    int64_t countSubarrWithEqualZeroAndOne(int A[], int N) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sub_array_count = 0;
        for (int i = 0, sum = 0; i < N; ++i) {
            sum += (A[i] ? 1 : -1);
            if (mp.find(sum) != mp.end()) {
                sub_array_count += mp[sum];
            } 
            mp[sum]++;
        }
        return sub_array_count;
    }
};
