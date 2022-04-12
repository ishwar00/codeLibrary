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
    int M;
    int K;
    int Q;
    int cnt;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cnt = 0;
        cin >> N >> M >> K;
        for (int i { 0 }; i < N; ++i) {
            long long watch_time { 0LL };
            for (int j { 0 }; j < K ; ++j) {
                int store;
                cin >> store;
                watch_time += store;
            }
            cin >> Q;
            if (watch_time >= M and Q <= 10) cnt++;
        }
    }
    
    void solve() {    
        cout << cnt << my::endl;
    }
    void operator()() {
        // std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}