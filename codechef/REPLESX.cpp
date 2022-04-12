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
    int n, x, p, k;
    cin >> n >> x >> p >> k;
    vector<int> A(n);
    for (int& i : A) cin >> i;
    sort(A.begin(), A.end());
    if ( k == p ) {
        if (x < A[p - 1]) {
            int count = 0;
            for (int i = p - 1; i >= 0 and A[i] > x ; i--)   count++;
            cout << count << "\n";
        } else if (x > A[p - 1]) {
            int count = 0;
            for (int i = p - 1; i < n and A[i] < x; ++i) count++;
            cout << count << "\n";
        } else {
            cout << "0\n";
        }
    } else if (p < k) {
        if (A[p - 1] < x) {
            cout << "-1\n";
        } else {
            int count = 0;
            for (int i = p - 1;i >= 0 and A[i] > x; --i) count++;
            cout << count << "\n";
        }
    } else {
        if (A[p - 1] <= x) {
            int count = 0;
            for (int i = p - 1; i < n and A[i] < x; ++i)   count++;
            cout << count << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

int main() {
    test solution();
    return 0;
}




