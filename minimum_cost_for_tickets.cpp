/*
 *
 * problem link: https://leetcode.com/problems/minimum-cost-for-tickets/
 *
 *
 * */

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int> const& costs) {
        vector<int> dp(days.back() + 1);
        vector<int> pass_time { 1, 7, 30 };
        int min_at = min(costs[0], min(costs[1], costs[2]));

        auto cut_cost = [&](int const& day, int const& index) -> int {
            int target = day - (day > pass_time[index] ? pass_time[index] : day);
            auto at = std::upper_bound(days.begin(), days.end(),
                target
            ) - days.begin();
            return dp[days[at] - 1] + costs[index];
        };

        for (int day = 1, j = 0; day <= days.back(); ++day) {
            if (days[j] == day) {
                int min_cost = dp[day - 1] + min_at;
                min_cost = min(min_cost, cut_cost(day, 1));
                min_cost = min(min_cost, cut_cost(day, 2));
                dp[day] = min_cost;
                j = j + 1;
            } else {
                dp[day] = dp[day - 1];
            }
        }
        return dp.back();
    }
};
