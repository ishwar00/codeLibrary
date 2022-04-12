# include <bits/stdc++.h>
namespace my {
    const std::string ws { " " };
    const char endl { '\n' };
    #define dbg(ARG) { std::cout << #ARG " = [ " << ARG << " ]" << my::endl; }
    typedef long long ll;
    template < class T > inline bool compare_float(T a, T b) {    return (abs(a - b) < 1e-9) ? true : false;    }
    template < class T > inline T SQ(T a) {                       return (a) * (a);    }
    template < class T > inline T CUBE(T a) {                     return (a) * (a) * (a);    }
}
using namespace std;

class solution {
    int T = 1;
    int n;
    array<int, 100'001> B;
    vector<bool> prime;
    int size;
public:
    solution() 
        : size { 4 * 1000'000 + 1 } {
        prime.resize(size, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= size; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= size; j += i) {
                    prime[j] = false;
                }
            }
        }
        // dbg(size);
    }
    
    void read() {
        cin >> n;
        for (int i { 1 }; i <= n; ++i) {
            cin >> B[i];
            // dbg(B[i]);
        }
    }
    
    void solve() {    
        vector<int> A(n + 1, 1);
        for (int i { 1 }, j { 2 }; i <= n; ++i) {
            // dbg(i);
            if (A[B[i]] == 1) {
                for (; j < size; ++j) if (prime[j])  break;
                A[i] = A[B[i]] = j++;
            } else {
                A[i] = A[B[i]];
            }
        }
        for (int i { 1 }; i <= n; i++) {
            cout << A[i] << my::ws;
        }
        cout << my::endl;
    }
    void run_on_test_cases() {
        std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution().run_on_test_cases();
    return 0;
}