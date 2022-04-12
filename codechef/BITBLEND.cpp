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
    

    bool proceed(vector<int> const& A) {
        for (int const& i : A) {
            if (i & 1) { return true; }
        }
        return false;
    }

    pair<int, int> changing_cost(vector<int> const& A, bool begin) {
        int cost = 0;
        int at = -1;
        for (int i = 0; i < A.size(); ++i) {
            int const& a = A[i];
            if ((a & 1) != begin) {
                cost = cost + 1;
            } else if (begin == 1) {
                at = i;
            }
            begin = !begin;
        }
        return { cost, at };
    }

    void solve() {
        my::vector<int> A;
        cin >> N;
        A.push_input(N);   

//# </DON'T PANIC RELAX>


        if (proceed(A)) {
            auto begin_one = changing_cost(A, 1);
            auto begin_zero = changing_cost(A, 0);

            bool begin_with;
            pair<int, int> begin;
            if (begin_zero < begin_one) {
                begin = begin_zero;
                begin_with = 0;
            } else if (begin_zero > begin_one) {
                begin = begin_one;
                begin_with = 1;
            } else {
                begin = begin_zero.second != -1 ? begin_zero : begin_one;
                if (begin_zero.second != -1) {
                    begin_with = 0;
                } else {
                    begin_with = 1;
                }
            }

            bool perfect = true;
            if (begin.second == -1) {
                perfect = false;
                for (int i = 0; i < A.size(); ++i) {
                    if (A[i] & 1) { begin.second = i; }
                }
            }
            // dbg(perfect);
            // dbg(begin_with);

            
            cout << begin.first + !perfect << endl;
            for (int i = 0; i < N; ++i) {
                // dbg(i);
                // dbg((A[i] & 1));
                // dbg(begin_with);
                if (i != begin.second and (A[i] & 1) != begin_with) {
                    
                    cout << i + 1 << sp << begin.second + 1 << nl;
                }
                begin_with = !begin_with;

            }

            if (not perfect) {
                if (begin.second - 1 >= 0 and (A[begin.second] & 1)) {
                    cout << begin.second << sp << begin.second + 1 << endl;
                } else {
                    cout << begin.second + 1 << sp << begin.second + 2 << endl;
                }
            }
        } else {
            cout << -1 << endl;
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