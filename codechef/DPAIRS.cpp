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


auto comp = [](pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
};

class solution {
    int T = 1;
    int n;
    int m;
    vector<pair<int, int>> A;
    vector<pair<int, int>> B;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        cin >> n >> m;
        for (int i { 0 }; i < n; ++i ) {
            int store;
            cin >> store;
            A.push_back({ store, i });
        }
        for (int i { 0 }; i < m; ++i) {
            int store;
            cin >> store;
            B.push_back({ store, i });
        }
    }
    
    void solve() {  
        sort(A.begin(), A.end(), comp);
        sort(B.begin(), B.end(), comp);
        int cur_max { A[0].first + B[0].first - 1 };
        for (int i { 0 }, cnt { 0 }; cnt < m + n - 1; ++i) {
            int j { m - 1 };
            for (int store { cur_max }; store < A[i].first + B[j].first and j >= 0; --j) {
                cout << A[i].second << my::ws << B[j].second << my::endl;
                int cur { A[i].first + B[j].first };
                if (cur_max < cur)   cur_max = cur;
                cnt++;
            }
        }
    }
    void operator()() {
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}