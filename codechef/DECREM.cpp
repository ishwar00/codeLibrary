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
    long long L, R;
    std::cin >> L >> R;
    if (2L * L - 1 >= R) {
        std::cout << R << endl;
    } else {
        puts("-1");
    }
}


int main() {
    test solution();
    return 0;
}




