# include <bits/stdc++.h>
using namespace std;
namespace my {
    const std::string ws { " " };
    const char endl { '\n' };
    typedef long long ll;
    template < typename T >                inline bool compare_float(T a, T b) {    return (abs(a - b) < 1e-9) ? true : false;    }
    template < typename T >                istream& operator>>(istream& os,  vector<T>& v) {    T store;    os >> store;    v.push_back(store);    return os;  }
    template < typename A, typename B >    ostream& operator<<(ostream& os, const pair<A, B>& p) {     return os << '(' << p.first << ", " << p.second << ')';  }

    template < typename T > class vector : public std::vector<T> {    public:    
        vector()                            { }    
        vector(int n)                       {    this->reserve(n); }
        vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
    };

    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>    void dbg_out(Head H, Tail... T) {    cerr << ' ' << H;     dbg_out(T...);     }
}
#define dbg(ARG)                  cout << #ARG " = [ " << ARG << " ]" << '\n'; 
#define loop(i, start, till )     for(int i {(start)}; i != (till); ++i)
#define fir first
#define sec second

template<class T>
void print(T container, string sep = " ", string end = "\n") {
    for (const auto& i : container) std::cout << i << sep;
    cout << end;
}

class solution {
    int T = 1;
    int D1;
    int V1;
    int D2;
    int V2;
    int P;
public:
    solution() { 
        /*some_precomputation*/
    }
    
    void read() {
        cin >> D1 >> V1 >> D2 >> V2 >> P;
    }
    
    void solve() {
        int vaccines { 0 };
        int days { min(D1 , D2) - 1 };
        for (int i { abs( D1 - D2) }; i != 0 and (P > vaccines); i--) {
            if (D1 > D2) {
                vaccines += V2;
                days++;
            } else if (D2 > D1) {
                vaccines += V1;
                days++;
            }
        }
        for (; P > vaccines;) {
            vaccines += (V1 + V2);
            days++;
          
        }
        cout << days << my::endl;
    }
    void operator()() {
        // std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}