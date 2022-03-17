/*
 *
 * problem link: https://leetcode.com/problems/merge-intervals/
 *
 * */



class Solution {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> range { intervals.front() };

        for (auto i { 0ULL }; i < intervals.size(); i++) {
            if (intervals[i].front() <= range.back()) {
                if (intervals[i].back() > range.back()) {
                    range.back() = intervals[i].back();
                }
            } else {
                ans.push_back(range);
                range = intervals[i];
                i = i - 1;
            }
        }
        if (ans.empty() or intervals.back()[1] != ans.back()[1]) ans.push_back(range);
        return ans;
    }

};
