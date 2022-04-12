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
    int A[100'00];
    int Q;
    int Q1;
    int Q2;
    int N;
    vector<int> pre_A;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        pre_A.clear();
        cin >> N;
        for (int i { 0 }; i < N; ++i) cin >> A[i];
        cin >> Q;
        int sum { A[0] };
        pre_A.push_back(0);
        pre_A.push_back(A[0]);
        for (int i { 1 }; i < N; ++i) {
            sum += A[i];
            pre_A.push_back(sum);
        }
    }
    
    void solve() {    
        for (int i { 0 }; i < Q; ++i) {
            cin >> Q1 >> Q2;
            cout <<  pre_A[Q2] - pre_A[Q1 - 1] << my::endl;
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