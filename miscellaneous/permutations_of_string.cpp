/*

    problem link: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1/

*/

class Solution {
    vector<string> vec;
public:
    void permutation(string S, int at = 0) {
        if (at < S.size()) {
            for (int i = at; i < S.size(); ++i) {
                swap(S[at], S[i]);
                permutation(S, at + 1);
                swap(S[at], S[i]);
            }
        } else {
            vec.push_back(S);
        }
    }

    vector<string> find_permutation(string S) {
        permutation(S, 0);
        sort(vec.begin(), vec.end());
        return vec;
    }
};

