/*
 *
 * problem link: https://leetcode.com/problems/merge-sorted-array/
 *
 *
 * */


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m - 1, j = n - 1, k = m + n - 1;
        for(; i >= 0 and j >= 0;){
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i = i - 1;
            } else {
                nums1[k] = nums2[j];
                j = j - 1;
            }
            k = k - 1;
        }
        
        while(j >= 0){
            nums1[k] = nums2[j];
            k = k -1;
            j = j - 1;
        }
        
    }
};


