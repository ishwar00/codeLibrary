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
    vector<int> dish;
public:
    solution()  { 
        /*some_precomputation*/    
    }
    
    void read() {
        dish.clear();
        cin >> n;
        for (int i { 0 }; i < n; ++i){
            int store;
            cin >> store; 
            dish.push_back(store);
        }
    }
    
    void solve() {    
        sort(dish.begin(), dish.end(), [](int a, int b) {    return a > b;   });
        int burn_1 { 0 }, burn_2 { 0 };
        for (int i { 0 }; i < n; ++i) {
            if (burn_1 >= burn_2) {
                burn_2 += dish[i];
            } else {
                burn_1 += dish[i];
            }
        }
        if (burn_1 > burn_2) cout << burn_1 << my::endl;
        else                 cout << burn_2 << my::endl;
    }
    void run_on_test_cases() {
        std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution().run_on_test_cases();
    return 0;
}