#include <bits/stdc++.h>
typedef long long ll;
# define test int x; cin >> x; while (x--)
# define loop(i, start, end)   for (int i = start; i < end; ++i)
# define inf                   while (true)
# define dbg(ARG) cout << #ARG " = [ " << ARG << " ]" << '\n';
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
    ll n, k;
    cin >> n >> k;
    vector<ll> Q(n);
    for (ll& i : Q)  cin >> i;
    ll left = 0;
    ll i = 0;
    for (; i < n; ++i) {
        if (Q[i] + left - k >= 0) {
            left += Q[i] - k;
        } else {
            cout << i + 1 << '\n';
            return;
        }
    }
    if (left % k) {
        cout << i + static_cast<ll>(ceil(static_cast<double>(left) / k)) << '\n';
    } else {
        cout << i + left / k + 1 << '\n';
    }
}

int main() {
    test solution();
    return 0;
}




