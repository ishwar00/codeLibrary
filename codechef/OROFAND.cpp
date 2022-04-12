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
    uint32_t N;
    uint32_t Q;
    uint32_t X;
    uint32_t V;
public:
    solution() {
        /*some_precomputation*/
    }

    void solve() {
        cin >> N >> Q;
        my::vector<uint32_t> A { 0 };
        A.push_input(N);

//# </DON'T PANIC RELAX>

        uint32_t array_value { 0 };
        vector<int> bit_count(33);

        for (auto i : A) {
            array_value |= i;
            for (int j { 0 }; j < 32; ++j) {
                if (i & (1ULL << j)) {
                    bit_count[j]++;
                }
            }
        }

        cout << array_value << nl;
        for (int i { 0 }; i < Q; ++i) {
            cin >> X >> V;
            for (uint32_t j { 0 }; j < 32; ++j) {
                if (A[X] & (1ULL << j)) {
                    if (bit_count[j] == 1) {
                        array_value ^= 1UL << j;
                    }
                    bit_count[j]--;
                }
            }
            array_value |= V;
            A[X] = V;
            for (int j { 0 }; j < 32; ++j) {
                if (V & (1ULL << j)) {
                    bit_count[j]++;
                }
            }
            cout << array_value << nl;
        }

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