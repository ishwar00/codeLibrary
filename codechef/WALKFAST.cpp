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
    int A;
    int B;
    int C;
    int D;
    int P;
    int Q;
    int Y;
    vector<int> x;
public:
    solution()  { 
        x.reserve(301);
    }
    
    void read() {
        x.resize(0);
        cin >> N >> A >> B >> C >> D >> P >> Q >> Y;
        for(int i {1}; i <= N; ++i)  cin >> x[i]; 
    }
    
    void solve() {    
        int walk_time { abs(x[A] -x[B]) * P };
        if (abs(x[A] - x[C]) * P <= Y) {
            // catches train
            int store { Y + abs(x[C] - x[D]) * Q + abs(x[B] - x[D]) * P };
            if (walk_time > store) {
                cout << store << my::endl;
                return;
            }
        }
        cout << walk_time << my::endl;
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