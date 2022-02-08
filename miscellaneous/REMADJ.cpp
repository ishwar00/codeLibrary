/*
 *
 * problem link: https://www.codechef.com/problems/REMADJ
 *
 */


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
    vector<int64_t> prefix_sum;
public:
    solution() {
        /*some_precomputation*/
    }

    int validate(int64_t const& A) {
        int M = 1;
        for (int i = 1; i <= N and M < (prefix_sum[N] / A); ++i) {
            if (prefix_sum[i] == A * M) {
                M = M + 1;
            }
        }
        if (M != prefix_sum[N] / A) {
            M = 1;
        }
        return N - M;
    }

    void solve() {
        my::vector<int> A;
        cin >> N;
        A.push_input(N);

//# </DON'T PANIC RELAX>

        prefix_sum = vector<int64_t>(N + 1);
        int zero_count = 0;
        for (int i = 1; i <= N; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
            zero_count += (not prefix_sum[i]);
        }

        int sign = prefix_sum[N] < 0 ? -1 : 1;
        int64_t const& S = abs(prefix_sum[N]);
        int min_ops = (S != 0 ? N - 1: N - zero_count);
        for (int64_t i = 1; i * i <= S; ++i) {
            if (S % i == 0) {
                min_ops = min(min_ops,
                    min(validate(i * sign), validate((S / i) * sign))
                );
            }
        }
        cout << min_ops << endl;
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



