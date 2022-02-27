/**
 *
 *
 *
 *
 * problem link: https://leetcode.com/problems/shortest-common-supersequence/
 *
 *
 *
*/


class Solution {
public:
    string shortestCommonSupersequence(string const& str1, string const& str2) {
        
        auto dp = vector<vector<int>>(str2.size() + 1, vector<int>(str1.size() + 1));
        iota(dp[0].begin(), dp[0].end(), 0);
        for(int i = 1; i <= str2.size(); ++i){
            dp[i][0] = i;
            for(int j = 1; j <= str1.size(); ++j){
                if(str2[i - 1] != str1[j - 1]){
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                } else {
                    dp[i][j] = dp[i - 1][j - 1]  + 1;
                }
            }
        }
        
        
        
        
        string ans ;
        int i = str2.size();
        int j = str1.size();
        while(i > 0 and j > 0) {
            if(str1[j - 1] != str2[i - 1]){
                if(dp[i - 1][j] < dp[i][j - 1]){
                    ans.push_back(str2[i - 1]);
                    i = i - 1;
                } else {
                    ans.push_back(str1[j - 1]);
                    j = j - 1;
                }
            } else {
                ans.push_back(str2[i - 1]);
                j = j - 1;
                i = i - 1;
            }
        }
        
        auto patch = [&](int const& k, string const& str) -> void {
            auto buffer = str.substr(0, k);
            reverse(buffer.begin(), buffer.end());
            ans = ans + buffer;
        };
        
        if(i > 0) patch(i, str2);
        if(j > 0) patch(j, str1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
