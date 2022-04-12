# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {
    public:
        vector() { }
        vector(int n) { this->reserve(n); }
        vector(std::initializer_list<T> ls) { for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n) { for (size_t i { 0ULL }; i != n; ++i) { T store;	cin >> store;    this->push_back(store); } }
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
template<typename Ostream, typename ...Ts>   Ostream& operator<<(Ostream& os, const pair<Ts...>& p) { return os << "{" << p.first << ", " << p.second << "}"; }
template < typename T >                      inline bool compare_float(T a, T b) { return (abs(a - b) < 1e-9) ? true : false; }
template < typename T >                      istream& operator>>(istream& os, vector<T>& v) { T store;    os >> store;    v.push_back(store);    return os; }
template < typename T >                      void print(T container, string sep = " ", string end = "\n") { for (const auto& i : container) std::cout << i << sep; cout << end; }

const std::string  sp { " " };
const char         nl { '\n' };
#define sec second
#define fir first
/*******************************************************</Temlate>********************************************************/




class solution {
    int T = 1;
    /*global fields*/
public:
    solution() {
        /*some_precomputation*/
    }

    void solve() {
        string s;
        cin >> s;
        vector<int> alp(26);

/********************************************************</All The Best>****************************************************************/

        int coins { 0 };
        for (char i : s)     alp[i - 'a']++;
        sort(alp.begin(), alp.end());
        for (size_t i { 0 }, j { 25 }; i < j;) {
            if (!alp[i]) {
                i++;
                continue;
            } else if (!alp[j]) {
                j--;
            }else {
                if (alp[i] <= (alp[j] / 2)) {
                    alp[j] = alp[j] - 2 * alp[i];
                    coins += alp[i];
                    alp[i++] = 0;
                } else {
                    alp[i] = alp[i] - alp[j] / 2;
                    coins += alp[j] / 2;
                    alp[j] = alp[j] % 2;
                    j--;
                }
            }
        }
        
        int one { 0 };
        int left { 0 };
        for (int i : alp) {
            if (i == 1) {
                one++;
            } else {
                left += i;
            }
        }
        if (one <= left / 2) {
            coins += one;
            left = left - one * 2;
            coins += (left / 3);
        } else {
            coins += (left / 2);
        }
        
        cout << coins << nl;
    }


    void operator()() { std::cin >> T;    while (T--) solve(); }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}