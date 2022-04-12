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
    int x;
    int y;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cin >> x >> y;
    }
    
    void solve() {    
        if(x == y) {
            cout << 0 << my::endl;
        } else if (x < y) {
            int store { y - x };
            if (store & 1) cout << 1 << my::endl;
            else if ((store / 2) & 1) {
                cout << 2 << my::endl;
            } else {
                cout << 3 << my::endl;
            }
        } else {
            int store { x - y };
            if (store & 1) cout << 2 << my::endl;
            else  cout << 1 << my::endl;
        }
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