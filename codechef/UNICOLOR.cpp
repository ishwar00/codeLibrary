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
#define r second
#define l first
/*******************************************************</Utilities>********************************************************/         




class solution {
    int T = 1;
    int N;
    int M;
    int C;
    uint64_t m = 998'244'353;
    vector<int> parent;
    vector<int> rank;
public:
    solution() {
        
    }

    int find_parent(int a) {
        if (parent[a] != 0) {
            parent[a] = find_parent(parent[a]);
            return parent[a];
        }
        return a;
    }

    void Union(int a, int b) {
        int arep { find_parent(a) };
        int brep { find_parent(b) };
        if (arep != brep) {
            if (rank[arep] < rank[brep]) {
                parent[arep] = brep;
            } else if (rank[arep] > rank[brep]) {
                parent[brep] = arep;
            } else {
                parent[arep] = brep;
                rank[brep]++;
            }
        }
    }

    long long binpow(long long a, long long b) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    void solve() {
        cin >> C >> N >> M;
        vector<pair<pair<int, int>, int>> intervals;
        for (int i { 0 }, x; i < C; ++i) {
            cin >> x;
            for (int j { 0 }, l, r; j < x; ++j) {
                cin >> l >> r;
                intervals.push_back({ {l, r}, x });
            }
        }

//# </DON'T PANIC RELAX>

        sort(intervals.begin(), intervals.end());
        parent = vector<int>(C + 1);
        rank = vector<int>(C + 1, 1);
        int non_club_members { 0 };
        auto prev_club { intervals.front() };
        // dbg(intervals);
        for (uint64_t i { 1 }; i < intervals.size(); ++i) {
            auto club { intervals[i] };
            if (club.first.l <= prev_club.first.r) {
                Union(club.second, prev_club.second);
                // dbg(disjoint_sets);
            } else {
                non_club_members += (club.first.l - prev_club.first.r) - 1;
                // dbg(non_club_members);
            }
            prev_club = club.first.r < prev_club.first.r ? prev_club : club;
        }
        // dbg(disjoint_sets);

        int R { 0 };
        int disjoint_sets { 0 };

        non_club_members += (intervals.front().first.l - 1);
        for (auto it : intervals) {
            R = max(R, it.first.r);
            if (not(parent[it.second])) {
                if (parent[it.second] != -1) {
                    if (not(parent[it.second])) {
                        disjoint_sets++;
                        parent[it.second] = -1;
                    }
                }
            }
        }
        non_club_members += (N - R);
        // dbg(non_club_members);
        // dbg(disjoint_sets);
        cout << binpow(M, non_club_members + disjoint_sets) << nl;
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