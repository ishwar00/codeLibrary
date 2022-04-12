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

    long long diff_names(vector<bool>& a, vector<bool>& b) {
        long long a_alp { 0 };
        long long b_alp { 0 };
        
        for (int i { 0 }; i < 26; ++i) {
            if (a[i]) a_alp++;
            if (b[i]) b_alp++;
        }
        
        for (int i { 0 }; i < 26; ++i) {
            if (a[i] and b[i]) {
                a_alp--;
                b_alp--;
            }
        }
        if (a_alp <= 0 or b_alp <= 0) {
            return -1;
        }
        return a_alp * b_alp;
    }
    
    void solve() {
        cin >> N;
        my::vector<string> s;
        s.read_input(N);

/********************************************************</>****************************************************************/

        map<string, vector<bool>> string_class;
        for (string si : s) {
            if (string_class.count(si.substr(1))) {
                string_class[si.substr(1)][si.front() - 'a'] = true;
            } else {
                vector<bool> alp(26, false);
                alp[si.front() - 'a']= true;
                string_class.insert({ si.substr(1), alp });
            }
        }
        long long names { 0 };
        
        for (auto a : string_class) {
            for (auto b : string_class) {
                long long store { diff_names(a.sec, b.sec) };
                if (store != -1) {
                    names += store;
                }
            }
        }
        cout << names << nl;
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