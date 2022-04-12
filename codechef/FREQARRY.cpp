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
    vector<int> A;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cin >> n;
        A.clear();
        for (int i { 0 }; i < n; ++i) {
            int store;
            cin >> store;
            A.push_back(store);
        }
    }
    
    void solve() {    
        sort(A.begin(), A.end());
        for (int i { 0 }; i < n - 1; ++i) {
            if (A[i] != A[i + 1]) {
                continue;
            } else {
                cout << "ne krasivo" << my::endl;
                return;
            }
        }
        cout << "prekrasnyy" << my::endl;
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