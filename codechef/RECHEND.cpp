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
        my::vector<pair<int, int>> B;
        cin >> N;
        B.push_input(N);

        //# </DON'T PANIC RELAX>

        sort(B.begin(), B.end(), [](auto a, auto b) { return a.second < b.second; });

        auto F = [&](int at) -> int {
            auto [R, C] { B[at] };
            R = R - 1;
            C = C + 1;
            int length { 1 };
            while (R > 0 and R <= N and C > 0 and C <= N) {
                at = at + 1;

                assert(at != N);
                if (B[at] != pair<int, int>{ R, C }) {
                    return length;
                } else {    
                    length = length + 1;
                }
                R = R - 1;
                C = C + 1;
            }
            return length;
        };

        for (int i { 0 }; i < N; ++i) {
            auto [R, C] { B[i] };
            if (C == 1) {
                dbg(i)
                if (F(i) == R) {
                    return void(cout << "NO" << nl);
                }
            } else if (R == N) {
                dbg(i);
                if (F(i) == N - C + 1) {
                    return void(cout << "NO" << nl);
                }
            }
        }
        cout << "YES" << nl;



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