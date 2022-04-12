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
    int64_t ans { 0 };
    vector<vector<int>> tree;
    vector<int> sub_tree_gcd;
    vector<int> parent_gcd;
    my::vector<int> A;
public:
    solution() {
        /*some_precomputation*/
    }

    void DFS(int at = 1, int parent = 1) {
        sub_tree_gcd[at] = A[at];
        for (auto child : tree[at]) {
            if (child != parent) {
                DFS(child, at);
                sub_tree_gcd[at] = __gcd(sub_tree_gcd[at], sub_tree_gcd[child]);
            }
        }
    }

    vector<int> get_adj_list(int C, int P) {
        vector<int> adj_list;
        for (auto& c : tree[C]) {
            if (c != P) {
                adj_list.push_back(c);
            }
        }
        return adj_list;
    }

    void max_damage(int C = 1, int P = -1) {
        int64_t damage { 0 };
        if (P != -1) {
            parent_gcd[C] = __gcd(A[C], parent_gcd[P]);
            damage += parent_gcd[P];
        } else {
            parent_gcd[C] = A[C];
        }
        vector<int> adj { get_adj_list(C, P) };
        vector<int> prefix_gcd(adj.size() + 1, parent_gcd[C]);
        vector<int> suffix_gcd(adj.size() + 1, parent_gcd[C]);

        for (auto i { 0UL }, j { adj.size() - 1 }; i < adj.size(); ++i, j = j - 1) {
            prefix_gcd[i + 1] = __gcd(prefix_gcd[i], A[adj[i]]);
            suffix_gcd[i + 1] = __gcd(suffix_gcd[i], A[adj[j]]);
        }

        for (int i { 0 }; i < adj.size(); ++i) {
            parent_gcd[C] = __gcd(prefix_gcd[i], suffix_gcd[adj.size() - i - 1]);
            damage += sub_tree_gcd[adj[i]];
            max_damage(adj[i], C);
        }
        ans = max(ans, damage);
    }


    void solve() {
        cin >> N;
        A = my::vector<int> { 0 };
        sub_tree_gcd = vector<int>(N + 1);
        tree = vector<vector<int>>(N + 1);
        parent_gcd = vector<int>(N + 1);
        for (int i { 1 }, a { 0 }, b { 0 }; i < N; ++i) {
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        A.push_input(N);

//# </DON'T PANIC RELAX>

        DFS();
        ans = 0;
        max_damage();
        cout << ans << nl;
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