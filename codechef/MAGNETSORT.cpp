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
        string S;
        cin >> N;
        A.push_input(N);
        cin >> S;

//# </DON'T PANIC RELAX>


        if (std::is_sorted(A.begin(), A.end())) { 
            cout << 0 << nl;
        } else {

            pair<int, int> block_A;
            pair<int, int> block_B;
            pair<int, int> block_C;

            vector<int> sorted_A = A;
            sort(sorted_A.begin(), sorted_A.end());

            int i = 0;
            for (; i < N; ++i) {
                if (sorted_A[i] == A[i]) {
                    block_A.first +=  (S[i] == 'S');
                    block_A.second += (S[i] == 'N');
                } else {
                    break;
                }
            }
            
            int j = N - 1;
            for (; j >= 0; j = j - 1) {
                if (A[j] == sorted_A[j]) {
                    block_C.first  += (S[j] == 'S');
                    block_C.second += (S[j] == 'N');
                } else {
                    break;
                }
            }

            assert(i != N and j >= 0);
            if (S[i] != S[j]) {
                cout << 1 << endl;
                return;
            } else {
                if (S[i] == 'N') {
                    if (block_A.first > 0 or block_C.first > 0) {
                        return (void)(cout << 1 << endl);
                    } 
                } else {
                    if (block_A.second > 0 or block_C.second > 0) {
                        return (void)(cout << 1 << endl);
                    }
                }
            }

            for (; i <= j; i++) {
                block_B.first  += (S[i] == 'S');
                block_B.second += (S[i] == 'N');
            }

            if (block_A.first > 0 and block_C.second > 0) {
                cout << 1 << nl;
            } else if (block_A.second > 0 and block_C.first > 0) {
                cout << 1 << nl;
            } else {
                if (block_B.first > 0 and block_B.second > 0) {
                    cout << 2 << nl;
                } else {
                    cout << -1 << nl;
                }
            }
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