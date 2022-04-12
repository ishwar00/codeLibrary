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
        A.clear();
        cin >> n;
        for (int i { 0 }, store; i < n; ++i) {
            cin >> store;
            A.push_back(store);
        }
    }
    
    void solve() {    
        sort(A.begin(), A.end());
        int i { 0 };
        int j { n - 1 };
        while (i != j) {
            if (A[i] + A[j] == 2000) {
                cout << "Accepted" << my::endl;
                return;
            } else if (A[i] + A[j] > 2000) {
                j--;
            } else {
                i++;
            }
        }
        cout << "Rejected" << my::endl;
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