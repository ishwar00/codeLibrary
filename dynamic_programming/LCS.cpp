/*

  problem to the link: https://leetcode.com/problems/longest-common-subsequence/submissions/ 
 
*/



class Solution {
public:
    int longestCommonSubsequence(string& text1, string& text2) {
        vector<int> last(text1.size() + 1);
        vector<int> present(text1.size() + 1);
        cout << text1 << endl;
        for(int i = 1; i <= text2.size(); ++i){
            for(int j = 1; j <= text1.size(); ++j){
                if(text2[i - 1] != text1[j - 1]){
                    present[j] = max(present[j - 1], last[j]);
                } else {
                    present[j] = 1 + last[j - 1];
                }
            }
            last.swap(present);
        }
        return last.back();
        
    }
};
