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
    int N;
    array<int, 8> X;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cin >> N;
        for (int i { 0 }; i < N; ++i)   cin >> X[i];
    }
    
    void solve() {    
        int best_case { 10 };
        int worst_case { 1 };
        for (int i { 1 }, cnt { 1 }; i < N ; ++i) {
            int diff { abs(X[i] - X[i - 1]) };
            if (diff <= 2) {
                cnt++;
                if (i != N - 1)    continue;
            }
            // dbg(cnt);
            if (best_case > cnt) best_case = cnt;
            if (worst_case < cnt) worst_case = cnt;
            cnt = 1;
        }
        if (abs(X[N - 1] - X[N - 2]) > 2) {
            best_case = 1;
        }
        cout << best_case << my::ws << worst_case << my::endl;
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