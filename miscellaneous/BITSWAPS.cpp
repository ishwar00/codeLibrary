/*
 *
 *
 * problem link:  https://www.codechef.com/FEB222B/problems/BITSWAPS
 *
 * **/



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
        my::vector<int> A;
        cin >> N;
        A.push_input(N);

//# </DON'T PANIC RELAX>

        vector<int> mask(33);
        auto replace = [&](int const& destination, int const& source) -> void {
            for (int i = 0; i < 32; ++i) {
                if (mask[i] == destination) mask[i] = source;
            }
        };

        auto match_any_group = [&](int const& e) -> int {
            for (int i = 0; i < 32; ++i) {
                if (e & (1LL << i) and mask[i] != 0) {
                    return mask[i];
                }
            }
            return 0;
        };

        for (auto const& a : A) {
            int group = match_any_group(a);
            if (group == 0) group = ++mask.back();
            for (int i = 0; i < 32; ++i) {
                if (a & (1LL << i)) {
                    if (mask[i] == 0) {
                        mask[i] = group;
                    } else if(mask[i] != group){
                        replace(mask[i], group);
                    }
                }
            }
        }

        auto connected = [&](int const& a, int const& b) -> bool {
            int g0 = match_any_group(a);
            int g1 = match_any_group(b);
            return g0 == g1;
        };

        auto grouped = [&]() -> void {
            for (int const& a : A) {
                int group = match_any_group(a);
                for (int i = 0; i < 32; ++i) {
                    if (a & (1LL << i)) {
                        if (group != mask[i]) {
                            replace(mask[i], group);
                        }
                    }
                }
            }
        };
        grouped();
        
        vector<int> sorted = A;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < N; ++i) {
            if ((sorted[i] == 0 and A[i] != 0) or (A[i] != sorted[i] and not connected(A[i], sorted[i]))) {
                cout << "NO" << nl;
                return;
            }
        }
        cout << "YES" << nl;
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
