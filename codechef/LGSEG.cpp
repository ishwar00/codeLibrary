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
    int S;
    int LOG;
    vector<vector<int>> up;
public:
    solution() {
        /*some_precomputation*/
    }

    void binary_lifting() {
        for (int j { 1 }; j < LOG; ++j) {
            for (int i { 0 }; i < N; ++i) {
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }

    void solve() {
        cin >> N >> K >> S;
        my::vector<int> A;
        A.push_input(N);

        //# </DON'T PANIC RELAX>

        LOG = 0;
        while ((1 << LOG) <= K) LOG++;

        up = vector<vector<int>>(N + 1, vector<int>(LOG));
        vector<int64_t> prefix_sum;
        for (int64_t i { 0 }, s { 0 }; i < N; ++i) {
            s += A[i];
            prefix_sum.push_back(s);
        }

        up[N] = vector<int>(LOG, N);
        for (int i { 0 }; i < N; ++i) {
            int64_t next_segment { prefix_sum[i] - A[i] + S };
            auto it = std::upper_bound(
                prefix_sum.begin(),
                prefix_sum.end(),
                next_segment
            );
            int at = std::distance(prefix_sum.begin(), it);
            up[i][0] = at;
        }
        

        binary_lifting();
        auto jump = [&](int at) -> int {
            for (int i { 0 }; i < 30; ++i) {
                if (K & (1 << i)) {
                    at = up[at][i];
                }
            }
            return at;
        };

        int ans { 0 };
        for (int i { 0 }; i < N; ++i) {
            ans = max(ans, jump(i) - i);
        }
        cout << ans << nl;

    }

    void operator()() {
        #warning MULTIPLE TEST CASES WILL BE EXECUTED
        std::cin >> T;
        while (T--) {
#ifdef DEBUG
            clock_t begin, end;
            double time_spent;
            begin = clock();
#endif
            solve();
#ifdef DEBUG
            end = clock();
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            cout << "\nTime Taken :" <<  time_spent << nl << nl;
#endif // DEBUG
        }
    }

};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}


