# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {    public:    
        vector()                            { }    
        vector(int n)                       {    this->reserve(n); }
        vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
    };
}

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(Ostream& os, const Cont& v) {
    os << "[";
    for (auto& x : v) { os << x << ", "; }
    return os << "]";
}
template<typename Ostream, typename ...Ts>   Ostream& operator<<(Ostream& os, const pair<Ts...>& p)       {    return os << "{" << p.first << ", " << p.second << "}";             }
template < typename T >                      inline bool compare_float(T a, T b)                          {    return (abs(a - b) < 1e-9) ? true : false;                          }
template < typename T >                      istream& operator>>(istream& os, vector<T>& v)               {    T store;    os >> store;    v.push_back(store);    return os;       }
template < typename T >                      void print(T container, string sep = " ", string end = "\n") {    for (const auto& i : container) std::cout << i << sep; cout << end; }

const std::string  sp  { " " };
const char         nl  { '\n' };
#define sec second
#define fir first
/*******************************************************</Temlate>********************************************************/         




class solution {
    int T = 1;
    int N;
public:
    solution() { 
        /*some_precomputation*/
    }
    
    void solve() {
        string s;
        string p;
        cin >> N >> s >> p;

        /********************************************************</All The Best>****************************************************************/

        vector<int> one;
        vector<int> zero;
        if (s == p) {
            cout << "Yes" << nl;
            return;
        }
        for (size_t i { 0 }; i < N; ++i) {
            if (s[i] != p[i]) {
                if (s[i] == '0') zero.push_back(i);
                if (s[i] == '1') one.push_back(i);
            }
        }
        if (one.size() != zero.size()) {
            cout << "No" << nl;
        } else {
            for (size_t i { 0 }; i < one.size(); ++i) {
                if(one[i] < zero[i])    continue;
                cout << "No" << nl;
                return;
            }
            cout << "Yes" << nl;
        }
    }
    
    void operator()() {  std::cin >> T;    while (T--) solve(); }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}