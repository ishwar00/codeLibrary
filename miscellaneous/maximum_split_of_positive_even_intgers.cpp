/*
 *
 * problem link: https://leetcode.com/problems/maximum-split-of-positive-even-integers/
 *
 * */


class Solution {
public:
    vector<long long> maximumEvenSplit(long long const finalSum) {
        vector<long long> max_split_vec;
        
        if(finalSum & 1){
            return max_split_vec;
        } else {
            int64_t sum = 0;
            for(int i = 2; sum + i <= finalSum; i += 2){
                max_split_vec.push_back(i);
                sum += i;
            }
            max_split_vec.back() += (finalSum - sum);
            return max_split_vec;
        }
    }
};
