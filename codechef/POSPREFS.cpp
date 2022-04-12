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
    int N;
    int K;
public:
    solution() { 
        /*some_precomputation*/
    }
    
    void read() {
        cin >> N >> K;
    }
    
    void solve() {
        long long sum { 0 };
        int count { 0 };
        // int track { 1 };
        bool flag { true };
        vector<int> v(N + 1, 0);
        // v.push_back(1);
        for (int i { 1 }; i != N + 1; ++i) {
            // dbg(i);
            if (count != K) {
                if (sum - i > 0) {
                    v[i] = -1 * i;
                    sum -= i;
                } else {
                    sum += i;
                    v[i] = i;
                }
                count++;
                // dbg(count);
            } else {
                if (sum - i > 0 and flag) {
                    v[i - 1] *= -1;
                    v[i] =  i;
                    sum = (2 - i);
                    flag = false;
                } else {
                    v[i] = -1 * i ;
                    sum -= i;
                }
            }
            // dbg(sum);
            
            // cout << sum << my::ws;
        }
        // if (!(K & 1) and N != K) {
        //     v[1] = -1;
        // }
        // cout << my::endl;
        // int track { 0 };
        for (int i { 1 }; i != N + 1; ++i) {
            cout << v[i] << my::ws;
            // s += v[i];
            // cout << s << my::ws;
            // if (s > 0) track++;
        }
        // if (track == K) {
        //     cout << " correct";
        // } else {
        //     cout << " nope";
        // }
        cout << my::endl ;
                
    
                
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