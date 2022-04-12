


# include <bits/stdc++.h>
using namespace std;
namespace my {
    const std::string ws { " " };
    const char endl { '\n' };
    typedef long long ll;
    template < typename T >                inline bool compare_float(T a, T b) {    return (abs(a - b) < 1e-9) ? true : false;    }

    template < typename T > class vector : public std::vector<T> {    public:    
        vector()                            { }    
        vector(int n)                       {    this->reserve(n); }
        vector(std::initializer_list<T> ls) {    for (auto i : ls)	this->push_back(i); }
        void read_input(size_t n)           {    for (size_t i { 0ULL }; i != n; ++i) {    T store;	cin >> store;    this->push_back(store);    }}
    };

    void dbg_out() { cerr << endl; }
    template<typename Head, typename... Tail>    void dbg_out(Head H, Tail... T) {    cerr << ' ' << H;     dbg_out(T...);     }
}
#define dbg(ARG)                  cout << #ARG " = [ " << ARG << " ]" << '\n'; 
#define loop(i, start, till )     for(int i {(start)}; i != (till); ++i)
#define fir first
#define sec second
template < typename T >                istream& operator>>(istream& os, vector<T>& v) { T store;    os >> store;    v.push_back(store);    return os; }
template < typename A, typename B >    ostream& operator<<(ostream& os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }


template<class T>
void print(T container, string sep = " ", string end = "\n") {
    for (const auto& i : container) std::cout << i << sep;
    cout << end;
}

class solution {
    int T = 1;
    int k;
    int x;
    int size = 1000'007;
    vector<bool> primes;
    vector<int> factors;
    vector<int> store;
public:
    vector<bool> seive() {
        vector<bool> prime(size, true);
        prime[0] = prime[1] = false;
        for (int i = 2; i * i <= size; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= size; j += i) {
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    void factorize(int x) {
        for (int i { 2 }; i <= x; ++i) {
            if (primes[i] and !(x % i)) {
                int fact { i };
                while (x % (fact * i) == 0) {
                    fact *= i;
                    // dbg(fact);
                }
                factors.push_back(fact);
                // dbg(fact);
            }
        }
        // print(factors);
    }

    bool okay(int counter) {
        int count { 0 };
        for (int i { 0 }; i < 31; ++i) {
            if (counter & (1ULL << i)) count++;
        }
        return count == 2;
    }
    
    void func(vector<int> v, int& min_sum) {
        if (k == (int)v.size()) {
            int sum { accumulate(v.begin(), v.end(), 0) };
            if (sum < min_sum) {
                min_sum = sum;
                store.clear();
                // cout << "found : ";
                for (int i : v) {
                    store.push_back(i);
                    // cout << i << my::ws;
                }
                // cout << my::endl;
            }
            return;
        } else {
            int sub_sets { 1 << v.size() };
            for (int counter { 1 }; counter < sub_sets; counter++) {
                if (okay(counter)) {
                    vector<int> sub_fact;
                    int merge { 1 };
                    for (size_t j { 0 }; j < v.size(); ++j) {
                        if (counter & (1ULL << j)) {
                            merge *= v[j];
                        } else {
                            sub_fact.push_back(v[j]);
                        }
                    }
                    sub_fact.push_back(merge);
                  
                    func(sub_fact, min_sum);
                }
            }
        }
    }
        
    
    solution() { 
        primes = seive();
    }

    void read() {  
        factors.clear();
        store.clear();
        cin >> k >> x;
    }

    void solve() {    
        int min_sum { INT_MAX };
        factorize(x);
        // cout << "factors : ";
        // print(factors);
        long long workers { 0 };
        long long factor_sum = accumulate(factors.begin(), factors.end(), 0LL);
        if ( k >= static_cast<long long>( factors.size() ) ) {
            workers = factor_sum;
            // dbg(workers);
            workers += (k - factors.size());
        } else {
            func(factors, min_sum);
            workers = min_sum;
        }
        // cout << "factors : ";
        // print(factors);
        cout << workers << my::endl;
    }

    void operator()() {
        std::cin >> T;
        while (T--) {    read();    solve();    }
    }
};


int main() {
    // ios::sync_with_stdio(0);
    solution()();
    return 0;
}

