#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t t, n, k;

    cin >> t;
    while (t--)     {
        cin >> n >> k;

        set<pair<size_t, size_t> > arr;

        for (size_t i { 0 }, p; i <= n; i++) {
            cin >> p;
            arr.insert({ p, i });
        }

        for (size_t i = 0; i < n; i++) {
            auto left { *(arr.begin()) };
            auto right { *arr.rbegin() };
            auto req { k - left.first };
            cout << left.second << " " << left.first << " " << right.second << " " << req << endl;
            arr.erase(arr.begin());
            auto it { arr.end()   };
            arr.erase(--it);
            arr.insert({ right.first - req, right.second });
        }

    }

    return 0;
}