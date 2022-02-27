/*
 *
 * problem link: https://atcoder.jp/contests/dp/tasks/dp_l
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
public:
    solution() {
        /*some_precomputation*/
    }

    void solve() {
        my::vector<int> a;
        cin >> N;
        a.push_input(N);

//# </DON'T PANIC RELAX>

        auto dp = vector<vector<int64_t>>(N + 1, vector<int64_t>(N + 1));
        vector<int64_t> prefix_sum(N + 1);
        dp[0][0] = prefix_sum[1] = a.front();
        for (int i = 1; i < N; ++i) {
            dp[i][i] = a[i];
            prefix_sum[i + 1] = prefix_sum[i] + a[i];
        }
        
        for (int i = 1; i < N; ++i) {
            for (int j = i - 1; j >= 0; j = j - 1) {
                int64_t store = prefix_sum[i + 1] - prefix_sum[j];
                dp[j][i] = max(
                    store - dp[j][i - 1],
                    store - dp[j + 1][i]
                );
            }
        }
        int64_t store = prefix_sum.back() - dp[0][N - 1];
        cout << dp[0][N - 1] - store << endl;
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
