# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {    public:    
        vector()                            { }    
        vector(int n)                       {    this->reserve(n); }
        vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
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
template<typename Ostream, typename ...Ts>   Ostream&      operator<<(Ostream& os, const pair<Ts...>& p)       {    return os << "{" << p.first << ", " << p.second << "}";               }
template < typename T >                      inline bool   compare_float(T a, T b)                             {    return (abs(a - b) < 1e-9) ? true : false;                                  }
template < typename T >                      istream&      operator>>(istream& os, vector<T>& v)               {    T store;    os >> store;    v.push_back(store);    return os;               }
template < typename T >                      void          print(T container, string sep = " ", string end = "\n") {    for (const auto& i : container) std::cout << i << sep; cout <<end; }

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

    void fix(vector<int32_t>& A, vector<vector<int32_t>>& operation) {
        for (uint16_t i { 2 }; i <= N; ++i) {
            if (A[i - 1] > A[i]) {
                operation.push_back(vector<int32_t> { 2, i, abs(A[i] - A[i - 1])  });
            }
        }
    }

    void solve() {
        cin >> N;
        my::vector<int32_t> A { 0 };
        A.read_input(N);

/********************************************************</>****************************************************************/

        vector<vector<int32_t>> operation;
        int cnt { 0 };
        for (int i { 2 }; i <= N; ++i) {
            if (A[i - 1] > A[i]) cnt++;
        }
        if (cnt <= N / 2) {
            fix(A, operation);
        } else {
            int32_t flip { (1 << 30) - 1 };
            for (auto& i : A) i ^= flip;
            operation.push_back(vector<int32_t> { 4, 1, flip });
            fix(A, operation);
        }
        cout << operation.size() << nl;
        for (auto i : operation)    print(i);
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