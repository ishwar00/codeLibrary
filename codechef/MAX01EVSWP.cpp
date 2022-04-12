#include <iostream>
#include<vector>
using namespace std;

struct binary_count {
    int zero = 0;
    int one = 0;
};



void solve() {
    int N;
    string S;
    cin >> N >> S;
    
    vector<binary_count> b_count(2);
    
    for(int i = 0; i < S.size(); ++i) {
        if(i & 1) {
            b_count[1].zero += (S[i] == '0');
            b_count[1].one  += (S[i] == '1');
        } else {
            b_count[0].zero += (S[i] == '0');
            b_count[0].one  += (S[i] == '1');
        }
    }
    
    int ans = 0;
    for(int i = 0, flag = 0; i < N; ++i) {
        int& zero = b_count[i & 1].zero;
        int& one = b_count[i & 1].one;
        if(not flag) {
            if(zero > 0) {
                zero = zero - 1;
                flag = 1;
            } else if(one > 0) {
                one = one - 1;
            }
        } else {
            if(one > 0) {
                one = one - 1;
                ans++;
                flag = 0;
            } else if(zero > 0){
                zero = zero - 1;   
            }
        }
    }
    
    cout << ans << endl;
}



int main() {
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i) solve();
	return 0;
}
