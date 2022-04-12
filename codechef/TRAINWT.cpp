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
    int S;
    int E;
    int W;
    int q;
    long long sum;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cin >> N;
        sum = 0;
        for (int i { 0 }; i < N; ++i) {
            int store;
            cin >> store;
            sum += store;
        }
        cin >> q;
    }
    
    void solve() {    
        for (int i { 0 }; i < q; ++i) {
            cin >> S >> E >> W;
            sum += W * (E - S + 1);
        }
        cout << sum << my::endl;
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