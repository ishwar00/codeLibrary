#include <bits/stdc++.h>
# define test int x; cin >> x; while (x--)
# define loop(i, start, end)   for (int i = start; i < end; ++i)
# define inf                   while (true)
# define dbg(ARG) cout << #ARG " = [ " << ARG << " ]" << '\n';
# define ws " " 
# define endl '\n'
typedef long long ll;
using namespace std;
template < class T > inline bool compare_float(T a, T b) {
    return (abs(a - b) < 1e-9) ? true : false;
}
template < class T > inline T SQ(T a) {
    return (a) * (a);
}
template < class T > inline T CUBE(T a) {
    return (a) * (a) * (a);
}


void solution() {
    int n;
    std::string s;
    std::cin >> n >> s;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[n - 1]) {
            std::cout << "YES\n";
            return;
        }
    }
    std::cout << "NO\n";
}


int main() {
    test solution();
    return 0;
}




