
/*
 
   link to the problem:	https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/
 
 */


class Solution{
  public:
    int cutRod(int price[], int N) {
        vector<int> dp(N);
        dp[0] = price[0];
        for(int i = 1; i < N; ++i) {
            dp[i] = price[i];
            for(int j = i; j > 0; j = j - 1) {
                int store = dp[i - j] + price[j - 1];
                dp[i] = max(dp[i], store);
            }
        }
        return dp.back();
    }
};

