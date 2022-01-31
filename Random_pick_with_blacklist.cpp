/*
Link to this problem:	https://leetcode.com/problems/random-pick-with-blacklist/
*/

using namespace std;

class Solution {
    std::unordered_map<int, int> mp;
    int rest_size = 0;
public:
    Solution(int N, vector<int>& blacklist) {
        std::set<int> S;
        std::sort(blacklist.begin(), blacklist.end());

        auto contains = [&](const int target) -> bool {
            return binary_search(blacklist.begin(), blacklist.end(), target);
        };

        rest_size = N - blacklist.size();
        N = N - 1;
        for (int i = 0; i < blacklist.size() and blacklist[i] < rest_size; ++i) {
            while (contains(N)) N = N - 1;
            mp[blacklist[i]] = N;
            N = N - 1;
        }
        srand(time(0));
    }

    int pick() {
        int random_pick = rand() % rest_size;
        const int& mapping = mp[random_pick];
        return mapping != 0 ? mapping : random_pick;
    }
};
