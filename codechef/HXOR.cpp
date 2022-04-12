// # include <bits/stdc++.h>
// using namespace std;
// namespace my {
//     const std::string ws { " " };
//     const char endl { '\n' };
//     typedef long long ll;
//     template < typename T >                inline bool compare_float(T a, T b) {    return (abs(a - b) < 1e-9) ? true : false;    }
//     template < typename T >                istream& operator>>(istream& os,  vector<T>& v) {    T store;    os >> store;    v.push_back(store);    return os;  }
//     template < typename A, typename B >    ostream& operator<<(ostream& os, const pair<A, B>& p) {     return os << '(' << p.first << ", " << p.second << ')';  }

//     template < typename T > class vector : public std::vector<T> {    public:    
//         vector()                            { }    
//         vector(int n)                       {    this->reserve(n); }
//         vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
//         void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
//     };

//     void dbg_out() { cerr << endl; }
//     template<typename Head, typename... Tail>    void dbg_out(Head H, Tail... T) {    cerr << ' ' << H;     dbg_out(T...);     }
// }
// #define dbg(ARG)                  cout << #ARG " = [ " << ARG << " ]" << '\n'; 
// #define loop(i, start, till )     for(int i {(start)}; i != (till); ++i)
// #define fir first
// #define sec second

// template<class T>
// void print(T container, string sep = " ", string end = "\n") {
//     for (const auto& i : container) std::cout << i << sep;
//     cout << end;
// }

// class solution {
//     int T = 1;
//     int N;
//     int X;
//     my::vector<int> A;
// public:
//     solution() { 
//         /*some_precomputation*/
//     }
    
//     void read() {
//         A.clear();
//         cin >> N >> X;
//         A.read_input(N);
//     }
    
//     int left_most_set_bit(int a) {
//         for (int i { 31 }; i != -1; --i) {
//             if (a & (1ULL << i)) {
//                 return i;
//             }
//         }
//         return -1;
//     }
    
    
//     int search(int set_bit, int j) {
//         for (int i { j + 1 }; i < N; ++i) {
//             if (A[i] & (1ULL << set_bit)) {
//                 return i;
//             }
//         }
//         return -1;
//     }
    
    
//     void solve() {    
//         bool flag { true };
//         for (int j { 0 }; flag ;) {
//             int left_set_bit { left_most_set_bit(A[j]) };
//             if (left_set_bit != -1) {
//                 int i { search(left_set_bit, j) };
//                 if (i != -1) {
//                     A[j] = A[j] ^ (1ULL << left_set_bit);
//                     A[i] = A[i] ^ (1ULL << left_set_bit);
//                 } else {
//                     A[N - 1] = A[N - 1] ^ (1ULL << left_set_bit);
//                     A[j] = A[j] ^ (1ULL << left_set_bit);
//                 }
//                 X = X - 1;
//                 if (!X) flag = false;
//             } else {
//                 if (j == N - 1) {
//                     if (X & 1) {
//                         A[N - 1] = A[N - 1] ^ (1ULL << 0);
//                         A[N - 2] = A[N - 2] ^ (1ULL << 0);
//                     }
//                     flag = false;
//                 }
//                 j += 1;
//             }
//         }
//         for(int i : A){
//             cout << i << my::ws;
//         }
//         cout << my::endl;
//     }
    
//     void operator()() {
//         std::cin >> T;
//         while (T--) {    read();    solve();    }
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
    const std::string ws { " " };
    const char endl { '\n' };
    typedef long long ll;
    template < typename T >                inline bool compare_float(T a, T b) { return (abs(a - b) < 1e-9) ? true : false; }
    template < typename T >                istream& operator>>(istream& os, vector<T>& v) { T store;    os >> store;    v.push_back(store);    return os; }
    template < typename A, typename B >    ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

    template < typename T > class vector : public std::vector<T> {
    public:
        vector() { }
        vector(int n) { this->reserve(n); }
        vector(std::initializer_list<T> ls) { for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n) { for (size_t i { 0ULL }; i != n; ++i) { T store;	cin >> store;    this->push_back(store); } }
    };

    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>    void dbg_out(Head H, Tail... T) { cerr << ' ' << H;     dbg_out(T...); }
}
#define dbg(ARG)                  cout << #ARG " = [ " << ARG << " ]" << '\n'; 
#define loop(i, start, till )     for(int i {(start)}; i != (till); ++i)
#define fir first
#define sec second

template<class T>
void print(T container, string sep = " ", string end = "\n") {
    for (const auto& i : container) std::cout << i << sep;
    cout << end;
}

class solution {
    int T = 1;
    int N;
    int X;
    my::vector<int> A;
public:
    solution() {
        /*some_precomputation*/
    }

    void read() {
        A.clear();
        cin >> N >> X;
        A.read_input(N);
    }

    int left_most_set_bit(int a) {
        for (int i { 31 }; i != -1; --i) {
            if (a & (1ULL << i)) {
                return i;
            }
        }
        return -1;
    }


    int search(int set_bit, int j) {
        for (int i { j + 1 }; i < N; ++i) {
            if (A[i] & (1ULL << set_bit)) {
                return i;
            }
        }
        return -1;
    }


    void solve() {
        // cout << left_most_set_bit(1);
        bool flag { true };
        // dbg(T);
        for (int j { 0 }; flag;) {
            // if (j == N) j = 0;
            // dbg(A[0]);
            // dbg(A[1]);
            int left_set_bit { left_most_set_bit(A[j]) };
            if (left_set_bit != -1 and j != N - 1) {
                // dbg(left_set_bit);
                int i { search(left_set_bit, j) };
                // dbg(i);
                if (i != -1) {
                    A[j] = A[j] ^ (1ULL << left_set_bit);
                    A[i] = A[i] ^ (1ULL << left_set_bit);
                    // dbg(A[j]);
                    // dbg(A[i]);
                } else {
                    A[N - 1] = A[N - 1] ^ (1ULL << left_set_bit);
                    A[j] = A[j] ^ (1ULL << left_set_bit);
                }
                X = X - 1;
                // dbg(X);
                if (!X) flag = false;
            } else {
                if (j == N - 1) {
                    // dbg(j);
                    if (X & 1 and N == 2) {
                        A[N - 1] = A[N - 1] ^ (1ULL << 0);
                        A[N - 2] = A[N - 2] ^ (1ULL << 0);
                    }
                    flag = false;
                }
                j += 1;
            }
        }
        for (int i : A) {
            cout << i << my::ws;
        }
        cout << my::endl;
    }

    void operator()() {
        std::cin >> T;
        while (T--) { read();    solve(); }
    }
};


int main() {
    ios::sync_with_stdio(0);
    solution()();
    return 0;
}