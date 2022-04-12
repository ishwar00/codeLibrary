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
    int M;
public:
    solution() {
        /*some_precomputation*/
    }

    void solve() {
        cin >> N >> M;
        vector<vector<int>> graph(N + 1);
        for (int i { 0 }, x { 0 }, y { 0 }; i < M; ++i) {
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }


//# </DON'T PANIC RELAX>

        multiset<pair<int, int>> Set;
        vector<int> count(N + 1);

        int maxDi { 0 };
        for (int i { 1 }; i <= N; ++i) {
            Set.insert({ graph[i].size(), i });
            count[i] = graph[i].size();
        }

        vector<int> ans(N);

        while (Set.empty() != true) {
            auto it { Set.begin() };
            auto [_, v] { *it };
            Set.erase(it);
            ans[v - 1] = N;
            N = N - 1;
            int D { 0 };
            for (const int& a : graph[v]) {
                auto it { Set.find({count[a], a}) };
                if (it != Set.end()) {
                    D = D + 1;
                    Set.erase(it);
                    count[a] = count[a] - 1;
                    Set.insert({ count[a], a });
                }
            }
            maxDi = max(maxDi, D);
        }

        cout << maxDi << nl;
        print(ans);

        


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