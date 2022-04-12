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
    long long x;
public:
    solution()  { 
            
    }
    
    void read() {
        std::cin >> x;
    }
    
    void solve() {
        std::cout << 0 << my::ws << x << my::endl;
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
    solution().run_on_test_cases();
    return 0;
}