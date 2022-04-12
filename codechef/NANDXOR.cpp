# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {
    public:
        vector() { }
        vector(int n) { this->reserve(n); }
        vector(std::initializer_list<T> ls) { for (auto i : ls)	this->push_back(i); }
        void push_input(size_t n) { for (size_t i { 0ULL }; i != n; ++i) { T store;	cin >> store;    this->push_back(store); } }
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
template<typename T1, typename T2>           std::istream& operator>> (std::istream& in, pair<T1, T2>& P) { in >> P.first >> P.second;  return in; }
template<typename Ostream, typename ...Ts>   Ostream& operator<<(Ostream& os, const pair<Ts...>& p) { return os << "{" << p.first << ", " << p.second << "}"; }
template < typename T >                      inline bool   compare_float(T a, T b) { return (abs(a - b) < 1e-9) ? true : false; }
template < typename T >                      istream& operator>>(istream& os, vector<T>& v) { T store;    os >> store;    v.push_back(store);    return os; }
template < typename T >                      void          print(T container, string sep = " ", string end = "\n") { for (const auto& i : container) std::cout << i << sep; cout << end; }

const std::string  sp { " " };
const std::string  nl { "\n" };
#define sec second
#define fir first
/*******************************************************</Utilities>********************************************************/




class solution {
    int T = 1;
    int N;
public:
    solution() {
        /*some_precomputation*/
    }

    void brute_force(vector<int> const& A) {
        auto pop_count = [](int const a) -> int {
            return __builtin_popcount(a);
        };
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if(i == j) continue;
                for (int k = 0; k < N; ++k) {
                    if(i == k or j == k) continue;
                    for (int l = 0; l < N; ++l) {
                        set<int> S;
                        S.insert(i);
                        S.insert(j);
                        S.insert(k);
                        S.insert(l);

                        if (S.size() == 4 and pop_count(A[i] ^ A[j]) == pop_count(A[k] ^ A[l])) {
                            cout << i + 1 << sp
                                << j + 1 << sp
                                << k + 1 << sp
                                << l + 1 << nl;
                            return;
                        }
                    }
                }
            }
        }
        cout << -1 << nl;
    }

    void solve() {
        my::vector<int> A;
        cin >> N;
        A.push_input(N);

        //# </DON'T PANIC RELAX>

        if (N > 64) {
            vector<int> mp(32, -1);
            for (int i = 0; i + 1 < N; i += 2) {
                int store = __builtin_popcount(A[i] ^ A[i + 1]);
                if (mp[store] != -1) {
                    cout << i + 1 << sp << i + 2 << sp << mp[store] + 1 << sp << mp[store] + 2 << nl;
                    return;
                }
                mp[store] = i;
            }
            cout << -1 << nl;
        } else {
            brute_force(A);
        }
    }

    void operator()() {
        #warning MULTIPLE TEST CASES WILL BE EXECUTED
            std::cin >> T;
        while (T--) {
            solve();
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    solution()();
    return 0;
}