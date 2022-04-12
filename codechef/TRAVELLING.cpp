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


    int run_dijkstra(vector<vector<pair<int, int>>> const& G) {
        set<pair<int, int>> S;
        vector<bool> done(N + 1);
        vector<int> distance(N + 1, INT32_MAX);
        distance[1] = 0;
        S.insert({ 0, 1 });
        while (S.empty() != true) {
            auto const [cost, s] = (*S.begin());
            S.erase(S.begin());
            done[s] = true;
            for (auto const& a : G[s]) {
                int vertex = a.first;
                int weight = a.second;
                if (not done[vertex]) {
                    distance[vertex] = min(distance[vertex], weight + distance[s]);
                    S.insert({ distance[vertex], vertex });
                }
            }
        }
        return distance[N];
    }

    void solve() {
        cin >> N >> M;
        vector<vector<pair<int, int>>> graph(N + 1);
        for (int i = 0, u = 0, v = 0; i < M; ++i) {
            cin >> u >> v;
            graph[u].push_back({ v, 0 });
            graph[v].push_back({ u, 0 });
        }

//# </DON'T PANIC RELAX>

        for (int i = 1; i < N; ++i) {
            graph[i].push_back({ i + 1, 1 });
            graph[i + 1].push_back({ i, 1 });
        }

        cout << run_dijkstra(graph) << nl;
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