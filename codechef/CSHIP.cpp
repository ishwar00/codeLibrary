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
    int K;
    vector<long long> A;
    
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        A.clear();
        cin >> N >> K;
        for (int i { 0 }, store; i < N; ++i) {
            cin >> store;
            A.push_back(store);
        }
    }
    
    void solve() {
        long long max_pow { LLONG_MIN };
        long long cur_sum { 0 };
        for (int i { 0 }; i < K; ++i) {
            cur_sum += A[i];
        }
        if (cur_sum > max_pow)   max_pow = cur_sum;
        for (int i { K }, j { 0 }; i < N; ++i, j++) {
            cur_sum = cur_sum + A[i] - A[j];
            if (cur_sum > max_pow)   max_pow = cur_sum;
        }
        cout << max_pow << my::endl;
    }
    void operator()() {
        std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}