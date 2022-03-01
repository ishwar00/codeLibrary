/*
 *
 *
 * problem link: https://atcoder.jp/contests/dp/tasks/dp_m
 *
 *
 * */


# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {    public:    
        vector()                            { }    
        vector(int n)                       {    this->reserve(n); }
        vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
        void push_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
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
template<typename T1, typename T2>           std::istream& operator>> (std::istream& in, pair<T1, T2>& P)      {    in >> P.first >> P.second;  return in;  }
template<typename Ostream, typename ...Ts>   Ostream&      operator<<(Ostream& os, const pair<Ts...>& p)       {    return os << "{" << p.first << ", " << p.second << "}";                }
template < typename T >                      inline bool   compare_float(T a, T b)                             {    return (abs(a - b) < 1e-9) ? true : false;                                   }
template < typename T >                      istream&      operator>>(istream& os, vector<T>& v)               {    T store;    os >> store;    v.push_back(store);    return os;                }
template < typename T >                      void          print(T container, string sep = " ", string end = "\n") {    for (const auto& i : container) std::cout << i << sep; cout << end; }

const std::string  sp  { " " };
const std::string  nl  { "\n" };
#define sec second
#define fir first
/*******************************************************</Utilities>********************************************************/         




class solution {
    int T = 1;
    int N;
    int K;
    int64_t MOD = 1000'000'007;
public:
    solution() {
        /*some_precomputation*/
    }

    void solve() {
        cin >> N >> K;
        my::vector<int> A;
        A.push_input(N);

//# </DON'T PANIC RELAX>

        auto dp = vector<vector<int64_t>>(N + 1, vector<int64_t>(K + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            dp[i][0] = 1;
            vector<int64_t> prefix_dp(K + 1);
            prefix_dp[0] = 1;
            for (int j = 1; j <= K; ++j)  prefix_dp[j] = (prefix_dp[j - 1] + dp[i - 1][j]) % MOD;
            for (int j = 1; j <= K; ++j) {
                int at = (j - A[i - 1]) >= 0 ? (j - A[i - 1]) : 0;
                dp[i][j] = (prefix_dp[j] - prefix_dp[at] + dp[i - 1][at] +  MOD) % MOD;
                assert(dp[i][j] >= 0);
            }
        }
        cout << dp.back().back() << endl;
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
