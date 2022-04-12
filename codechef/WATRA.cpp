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
    int M;
    int K;
    array<int, 4> dy;
    array<int, 4> dx;
    map<char, int> Alp;
    string direction[405];
    int city[405][405];
public:
    solution() :
                dy { -1, 0, +1, 0 },
                dx { 0, 1, 0, -1 },
                Alp {
                    {'U', 0},
                    {'R', 1},
                    {'D', 2},
                    {'L', 3}
                }{ }

    // class lambda {
    //     bool operator(array<int, 2> a, array<int, 2> b) {
            
    //     }
    // };
    

    bool flow(int edge) {
        vector<vector<int>> d(N + 1, vector<int>(M + 1, INT32_MAX));
        auto Hi = [&](array<int, 2> a, array<int, 2> b) -> bool {
            return d[a[0]][a[1]] > d[b[0]][b[1]];
        };
        d[0][0] = 0;
        priority_queue < array<int, 2>, vector<array<int, 2>>, decltype(Hi)> PQ (Hi);
        array<int, 2> buffer {0, 0};
        PQ.push(buffer);
        while (PQ.empty() != true) {
            buffer = PQ.top();
            int x { buffer[0] };
            int y { buffer[1] };
            int cap { city[x][y] };
            int D { Alp[direction[x][y]] };
            PQ.pop();
            for (int32_t cost { 0 }; cost < 4 and (cap - cost) >= edge; ++cost, ++D) {
                D %= 4;
                int i { x + dy[D] };
                int j { y + dx[D] };
                if (i >= 0 and i < N and j >= 0 and j < M) {
                    int new_d { d[x][y] + cost };
                    if (new_d < d[i][j]) {
                        d[i][j] = new_d;    
                        PQ.push(array<int, 2> {i, j});
                    }
                }
            }
        }
        if (d[N - 1][M - 1] != INT32_MAX and d[N - 1][M - 1] <= K) {
            return true;
        }
        return false;
    }

    void solve() {
        int max_capacity { INT32_MIN };

        cin >> N >> M >> K;
        for (int32_t i { 0 }; i < N; ++i) {
            for (int j { 0 }; j < M; ++j) {
                cin >> city[i][j];
                max_capacity = max(city[i][j], max_capacity);
            }
        }
        for (int i { 0 }; i < N; ++i) {
            cin >> direction[i];
        }

        /********************************************************</string>****************************************************************/

        auto mid = [](int a, int b) {
            return (a + b) / 2;
        };
        
        int l { 1 };
        int h { max_capacity };
        int ans { 0 };
        while (l <= h) {
            int m { mid(l, h) };
            if (flow(m)) {
                l = m + 1;
                ans = m;
            } else {
                h = m - 1;
            }
        }
        cout << ans << nl;
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
    cin.tie(0);
    cout.tie(0);
    solution()();
    return 0;
}