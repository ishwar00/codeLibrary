# include <bits/stdc++.h>
# define dbg(ARG) cout << #ARG " = [ " << ARG << " ]" << '\n';
# define ws " " 
# define endl '\n'
typedef long long ll;
using namespace std;
template < class T > inline bool compare_float(T a, T b) {
    return (abs(a - b) < 1e-9) ? true : false;
}
template < class T > inline T SQ(T a) {
    return (a) * (a);
}
template < class T > inline T CUBE(T a) {
    return (a) * (a) * (a);
}


class solution {
public:
    void solve() {
        int N;
        std::cin >> N;
        std::vector<int> edge { 2, 3, 1};
        if(N == 1){
            std::cout << 1 << endl;
            return;
        }else if(!(N & (N - 1))){
            std::cout << -1 << endl;
            return;
        }else{
            for (int i = 4; i <= N; ++i) {
                if (i & (i - 1)) {
                    edge.push_back(i);
                } else {
                    edge.push_back(i + 1);
                    edge.push_back(i++);
                }
            }
        }
        for (int i : edge)   std::cout << i << ws;
        std::cout << endl;
    }
};

class Testing {
private:
    int T;
    solution S;
public:
    Testing() {
        std::cin >> T;
        while (T--)  S.solve();
    }
};

int main() {
    Testing Solution;
    return 0;
}