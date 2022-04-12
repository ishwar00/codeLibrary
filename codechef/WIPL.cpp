// # include <bits/stdc++.h>
// using namespace std;
// namespace my {
//     template < typename T > class vector : public std::vector<T> {    public:    
//         vector()                            { }    
//         vector(int n)                       {    this->reserve(n); }
//         vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
//         void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
//     };
// }

// int recur_depth = 0;
// #ifdef DEBUG
// #define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
// #else
// #define dbg(x)
// #endif
// template<typename Ostream, typename Cont>
// typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(Ostream& os, const Cont& v) {
//     os << "[";
//     for (auto& x : v) { os << x << ", "; }
//     return os << "]";
// }
// template<typename Ostream, typename ...Ts>   Ostream& operator<<(Ostream& os, const pair<Ts...>& p)       {    return os << "{" << p.first << ", " << p.second << "}";             }
// template < typename T >                      inline bool compare_float(T a, T b)                          {    return (abs(a - b) < 1e-9) ? true : false;                          }
// template < typename T >                      istream& operator>>(istream& os, vector<T>& v)               {    T store;    os >> store;    v.push_back(store);    return os;       }
// template < typename T >                      void print(T container, string sep = " ", string end = "\n") {    for (const auto& i : container) std::cout << i << sep; cout << end; }

// const std::string  sp  { " " };
// const char         nl  { '\n' };
// #define sec second
// #define fir first
// /*******************************************************</Temlate>********************************************************/         




// class solution {
//     int T = 1;
//     vector<long long> dp;
// public:
//     solution() {
//         dp.resize(1000);
//     }

//     long long s(long long n) {
//         if (n < 0)  return 0;
//         if (n == 0 or n == 1)  return 1;
//         if (dp[n]) {
//             return dp[n];
//         } else {
//             return dp[n] = s(n - 1) + s(n - 3) + s(n - 5);
//         }
//     }

//     void solve() {
//         long long n;
//         cin >> n;

// /********************************************************</All The Best>****************************************************************/

//         cout << s(n) << nl;

//     }

//     void operator()() {
//         std::cin >> T;
//         while (T--) {
// #ifdef DEBUG
//             clock_t begin, end;
//             double time_spent;
//             begin = clock();
// #endif
//             solve();
// #ifdef DEBUG
//             end = clock();
//             time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//             cout << "\nTime Taken : " << time_spent << nl;
// #endif // DEBUG
//         }
//     }

// };


// int main() {
//     ios::sync_with_stdio(0);
//     solution()();
//     return 0;
// }


# include <bits/stdc++.h>
using namespace std;
namespace my {
    template < typename T > class vector : public std::vector<T> {
    public:
        vector() { }
        vector(int n) { this->reserve(n); }
        vector(std::initializer_list<T> ls) { for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n) { for (size_t i { 0ULL }; i != n; ++i) { T store;	cin >> store;    this->push_back(store); } }
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
template<typename Ostream, typename ...Ts>   Ostream& operator<<(Ostream& os, const pair<Ts...>& p) { return os << "{" << p.first << ", " << p.second << "}"; }
template < typename T >                      inline bool compare_float(T a, T b) { return (abs(a - b) < 1e-9) ? true : false; }
template < typename T >                      istream& operator>>(istream& os, vector<T>& v) { T store;    os >> store;    v.push_back(store);    return os; }
template < typename T >                      void print(T container, string sep = " ", string end = "\n") { for (const auto& i : container) std::cout << i << sep; cout << end; }

const std::string  sp { " " };
const char         nl { '\n' };
#define sec second
#define fir first
/*******************************************************</Temlate>********************************************************/




class solution {
    int T = 1;
    int N;
    int K;
public:
    solution() {
        /*some_precomputation*/
    }

    void optimize(vector<int>& left, vector<int>& taken, vector<int> H, long long& T1) {
        // reverse(left.begin(), left.end());
        for (int& i : taken) {
            for (int& j : left) {
                if (H[i] > H[j]) {
                    long long store { T1 - H[i] + H[j] };
                    if (store >= K) {
                        int t { i };
                        i = j;
                        j = t;
                        T1 = store;
                        if(T1 == K) return;
                    }
                }
            }
        }
    }
    
    vector<int> search_space(const vector<int>& H){
        long long sum {0};
        vector<int> space;
        for(int i {0}; i < N; ++i){
            if(sum <  2 * K){
                sum += H[i];
                space.push_back(H[i]);
            }else{
                break;
            }
        }
        return space;
    }


    pair<int, int> UL_LL(const vector<int>& space){
        pair<int, int> window {0, 0};
        long long      sum { space.front() };
        // vector<pair<int, int>> Limits;
        pair<int, int> Opt { 0, 0 };
        int alpha { INT_MAX };
        int beta { INT_MAX };
        while(window.first < space.size()){
            if(sum >= K){
                int store { window.first - window.second + 1 + sum - K};
                if (store < alpha or sum == K) {
                    Opt.second = window.second;
                    Opt.first = window.first;
                    alpha = store;
                    beta = sum - K;
                } 
                    
                // Limits.push_back({window.second, window.first});
                sum -= space[window.second];
                window.second++;
            }else{
                if(++window.first < space.size())    sum += space[window.first];
            }
        }
        return Opt;
    }

    pair<vector<int>, vector<int>> max_vec(vector<int>& H) {
        pair< vector<int>, vector<int> > alt_vec;
        long long T1 { 0 };
        for (int i { 0 }; i < N; ++i) {
            if (!(i & 1)) {
                if (T1 < K) {
                    T1 += H[i];
                    alt_vec.first.push_back(i);
                    continue;
                }
            }
            alt_vec.second.push_back(i);
        }
        return alt_vec;
    }

    long long f(vector<int>& H_, long long& T2) {
        long long count { 0 };
        for (int i : H_) {
            if (i != -1 and T2 < K) {
                T2 += i;
                count++;
            }
            if (T2 >= K) break;
        }
        return count;
    }

    void solve() {
        cin >> N >> K;
        my::vector<int> H;
        H.read_input(N);

        /********************************************************</All The Best>****************************************************************/

        sort(H.begin(), H.end(), [](int a, int b) -> bool { return a > b; });
        long long Sum { accumulate(H.begin(), H.end(), 0LL) };
        if(Sum >= 2 * K){
            vector<int>                            space { search_space(H) };
            pair<int, int>                         L { UL_LL(space) };
            pair<vector<int>, vector<int>>         alt_vec { max_vec(H) };
            vector<pair<vector<int>, vector<int>>> pos_vec;
            
            pair<int, int> TT { 0, 0 };
            long long ans { LONG_MAX };
                
            // dbg(L);
            pair<vector<int>, vector<int>> Opt_vec;
            for (int j { 0 }; j < N; ++j) {
                if (j >= L.second and j <= L.first) {
                    Opt_vec.first.push_back(j);
                } else {
                    Opt_vec.second.push_back(j);
                }
            }
            pos_vec.push_back(Opt_vec);
            pos_vec.push_back(alt_vec);
            for (size_t i { 0 }; (i < pos_vec.size()); ++i) {
                long long T1 { 0 };
                for (int j : pos_vec[i].first) T1 += H[j];

                optimize(pos_vec[i].second, pos_vec[i].first, H, T1);
                long long boxe { pos_vec[i].first.size() };
                
                long long T2 { 0 };

                vector<pair<int, int>> restore;
                for (int j : pos_vec[i].first) {
                    restore.push_back({ j, H[j] });
                    H[j] = -1;
                }
                // dbg(H);

                boxe += f(H, T2);
                if (T1 >= K and T2 >= K) {
                    if (ans > boxe) {
                        ans = boxe;
                        TT.first = T1;
                        TT.second = T2;
                        if (T1 == K and T2 == K) break;
                    }
                }
                
                for (auto j : restore) {
                    H[j.first] = j.second;
                }
            }

            if (TT.first >= K and TT.second >= K) {
                cout << ans << nl;
            } else {
                cout << -1 << nl;
            }
        }else{
            cout << -1 << nl;            
        }
    }    
        void operator()() { std::cin >> T;    while (T--) solve(); }
};

int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}

