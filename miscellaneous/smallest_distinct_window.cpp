/**
 *
 *
 * problem link: https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1/#
 *
 *
 * */

class Solution {
public:
    string findSubString(string const& S) {
        vector<int> mp(257);
        int unique_count = 0;
        for (auto const& c : S) mp[c]++;
        for (auto& c : mp) {
            unique_count += (c != 0);
            c = 0;
        }

        int at = 0;
        int length = S.size();

        auto remove_character = [&](char const& character, int& uniqueness) -> void {
            if(mp[character] > 0){
                mp[character] = mp[character] - 1;
                uniqueness = uniqueness - (mp[character] == 0);
            }
        };

        for (int i = 0, j = 0, uniqueness = 0; i <= j and j < S.size();) {
            uniqueness += (mp[S[j]] == 0);
            mp[S[j]]++;

            if (unique_count == uniqueness) {
                if (j - i + 1 < length) {
                    length = j - i + 1;
                    at = i;
                }
                remove_character(S[i], uniqueness);
                remove_character(S[j], uniqueness);
                i = i + 1;
            } else {
                j = j + 1;
            }
        }
        return S.substr(at, length);
    }
};


