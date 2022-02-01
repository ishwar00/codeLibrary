/*

  link to the problem: https://leetcode.com/problems/integer-break/submissions/ 

*/


class Solution {
public:
    int integerBreak(int n) {
        if(n > 3){
            vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;
            dp[3] = 3;
            
            for(int i = 4; i <= n; ++i){
                for(int j = i - 1; j >= i / 2; j = j - 1){
                    int store = (i - j) * dp[j];
                    dp[i] = max(dp[i], store); 
                }
            }
            return dp.back();
        }
        
        return n == 2 ? 1 : 2;
    }
};
