/*
 *
 * problem link: https://leetcode.com/problems/add-binary/
 *
 * */



class Solution {
public:
    string addBinary(string const& a, string const& b) {
        string ans;

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while(i >= 0 and j >= 0){
            int store = a[i] + b[j] - 2 * '0' + carry;
            ans.push_back('0' + (store & 1));
            carry = (store & (1 << 1)) != 0;
            i = i - 1;
            j = j - 1;
        }

        auto fill_rest = [&](int k, string const& S) -> void {
            while(k >= 0){
                int store = S[k] + carry;
                ans.push_back('0' + (store & 1));
                carry = (store & (1 << 1)) != 0;
                k = k - 1;
            }
        };


        fill_rest(i, a);
        fill_rest(j, b);
        if(carry)   ans.push_back('0' + carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
