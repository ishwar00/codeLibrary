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
/*******************************************************</Utilities>********************************************************/




class solution {
    int T = 1;
    int N;
    vector<int> ans;
    vector<bool> prime_ref;
public:
    
    vector<bool> Fck() {
        long long n { 1000000 };
        vector<bool> pri(n + 1, true);
        pri[0] = pri[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (pri[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    pri[i] = false;
            }
        }
        return pri;
    }
    
    solution() {
        prime_ref = Fck();
        ans = vector<int> { 0, 0, 0 };
        int count_at_i { 0 };
        for (int i { 3 }; i <= 1000000; ++i) {
            if (prime_ref[i - 2] and prime_ref[i]) {
                count_at_i++;
            }
            ans.push_back(count_at_i);
        }
    }

    void solve() {
        cin >> N;

        /********************************************************</>****************************************************************/

        cout << ans[N] << nl;

    }

    void operator()() {
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
            cout << "\nTime Taken :" << time_spent << nl;
#endif // DEBUG
        }
    }

        };


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}