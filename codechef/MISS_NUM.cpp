#include <iostream>
#include <vector>
#include<cassert>
using namespace std;


pair<int, int> extract(int const A, int const B) {
    int sum { A + B };
    if((sum & 1) == 0) {
        int a = sum / 2;
        int b = A - a;
        if(a >= 1 and a <= 10'000 and b >= 1 and b <= 10'000)   return { a, b };
    }
    return { -1, -1 };
}


pair<int, int> get_rest(int const i, int const j, vector<int> const& A) {
    assert(A.size() == 4);
    
    vector<int> rest;
    for(int k = 0; k < A.size(); ++k) {
        if(k != i and k != j) rest.push_back(A[k]);  
    }
    return {rest[0], rest[1]};
}

bool vailidate_rest(pair<int, int> const ab, pair<int, int> const rest) {
    int const a = ab.first;
    int const b = ab.second;
    
    int64_t product { a * b * 1LL };
    int divide = a / b;
    
    if(rest.first  == product and rest.second == divide) return true;
    if(rest.second == product and rest.first == divide) return true;
    return false;
}


bool satisfy(int const i, int const j, vector<int> const& A) {
    auto guess = extract(A[i], A[j]);
    // cout << "# " << i << " " << j << endl;
    // cout << "## " << guess.first << " " << guess.second << endl;

    if(guess != pair<int, int>{-1, -1}) {
        auto rest = get_rest(i, j, A);
        // cout << "rest " << rest.first << " " << rest.second << endl;
        if(vailidate_rest(guess, rest)) return true;
    }
    return false;
}


void print(pair<int, int> const p) {
    cout << p.first << " " << p.second << endl;
}


void solve() {
    vector<int> A(4);
    for(int& i: A) cin >> i;

    
    for(int i = 0; i < A.size(); ++i){
        for(int j = i + 1; j < A.size(); ++j) {
            if(satisfy(i, j, A)){
                print(extract(A[i], A[j]));
                return ;
            }
            
            if(satisfy(j, i, A)){
                print(extract(A[j], A[i]));
                return ;
            }
        }
    }
    cout << "-1 -1\n";
}



int main() {
	int T = 0;
	cin >> T;
	for(int i = 0; i < T; ++i) solve();
	return 0;
}
