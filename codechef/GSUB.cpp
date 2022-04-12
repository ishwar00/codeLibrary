# include <bits/stdc++.h>
namespace my {
    const std::string ws { " " };
    const char endl { '\n' };
    #define dbg(ARG) { std::cout << #ARG " = [ " << ARG << " ]" << my::endl; }
    typedef long long ll;
    template < class T > inline bool compare_float(T a, T b) {
        return (abs(a - b) < 1e-9) ? true : false;
    }
    template < class T > inline T SQ(T a) {
        return (a) * (a);
    }
    template < class T > inline T CUBE(T a) {
        return (a) * (a) * (a);
    }
}
using namespace std;

class solution {
    int T = 1;
    int N;
    int Q;
    int x;
    int y;
    int max_sub = 1;
    std::vector<int> a;
public:
    solution() { 
        a.reserve(static_cast<size_t>(1e5) + 1);
    }
    void Query() {
        std::cin >> x >> y;
    }
    
    void read() {
        std::cin >> N >> Q;
        max_sub = 1;
        std::cin >> a[1];
        for (int i { 2 }; i <= N; ++i) {
            std::cin >> a[i];
            max_sub += (a[i - 1] != a[i]);
        }
    }

    void solve() {
        while (Q--) {
            Query();
            if (x != N) {
                max_sub -= (a[x] != a[x + 1]);
                max_sub += (y != a[x + 1]);
            }
            if (x != 1) {
                max_sub -= (a[x] != a[x - 1]);
                max_sub += (y != a[x - 1]);
            }
            a[x] = y;
            std::cout << max_sub << my::endl;
        }
    }

    void run_on_test_cases() {
        std::cin >> T;
        while (T--) {
            read();
            solve();
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution().run_on_test_cases();
    return 0;
}