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
        my::vector<int> Q;
        Q.push_input(M);

        //# </DON'T PANIC RELAX>

        vector<int> mp(N + 1);
		pair<int, int> window;
		int picked_count { 0 };
		for (int i { 0 }; i != M and picked_count != N; ++i) {
			picked_count += not(mp[Q[i]]);
			mp[Q[i]]++;
			window.sec = i;
		}
		int ans { window.sec + 1 };
		int final_ans { ans };
		for (int i { window.sec }, j { 0 }; i >= 0; i = i - 1) {
			mp[Q[i]] = mp[Q[i]] - 1;
			ans = ans - 1;
			if (mp[Q[i]] == 0) {
				picked_count = picked_count - 1;
				while (picked_count != N) {
					j = j - 1;
					mp[Q[j + M]]++;
					ans++;
					picked_count += (mp[Q[j + M]] == 1);
				}
			}
			final_ans = min(ans, final_ans);
		}
		cout << final_ans << nl;
		
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