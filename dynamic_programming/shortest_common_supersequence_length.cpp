/*
 * problem link: https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1/#
 *
 *
 * */



class Solution {
public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string const& X, string const& Y, int const& m, int const& n) {
        auto dp = vector<vector<int>>(X.size() + 1, vector<int>(Y.size() + 1));
        dp[0] = vector<int>(Y.size() + 1, 1);
        iota(dp[0].begin(), dp[0].end(), 0);
        for (int i = 1; i <= X.size(); ++i) {
            dp[i][0] = i;
            for (int j = 1; j <= Y.size(); ++j) {
                if (X[i - 1] != Y[j - 1]) {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }
        return dp.back().back();
    }
};
