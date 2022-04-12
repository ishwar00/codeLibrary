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
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    vector<int> city(N, false);
    city[X] = true;
    for (int i = X; !city[Y];) {
        i = (i + K) % N;
        if(!city[i]){ 
            city[i] = true;
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    test solution();
    return 0;
}




