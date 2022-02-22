/*
 *
 * problem link: https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#
 *
 * */


class Solution{   
public:
    bool isSubsetSum(int N, int A[], int sum){
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1));
        
        for(int i = 1; i <= N; ++i){
            dp[i - 1][0] = true;
            for(int j = 1; j <= sum; ++j){
                dp[i][j] = dp[i - 1][j] or (j >= A[i - 1] ? dp[i - 1][j - A[i - 1]] : false);
            }
        }
        return dp.back().back();
    }
};
