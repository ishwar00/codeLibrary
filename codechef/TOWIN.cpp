#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define       test  int x;    cin >> x; while (x--)
#define       loop(i, start, end)  for(int i = start; i < end; ++i)
#define       inf while (true)
#define       compare_float(a, b) (abs(a - b) < 1e-9) ? true : false;
#define       SQ(a) (a) * (a)
#define       CUBE(a) (a) * (a) * (a)

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for(int& el : v){
        std::cin >> el;
    }
    std::sort(v.rbegin(), v.rend());
    long long p1 = 0;
    long long p2 = 0;

    if(n >= 3){
        p1 = v[0];
        p2 = v[1] + v[2];
        bool flag = 1;
        for(int i = 3; i < v.size(); ++i){
            if(flag){
                p1 += v[i];

            }else{
                p2 += v[i];
            }
            flag = !flag;
        }
    }else{
        if(n == 1){
            p1 = v[0];
        }else{
            p1 = v[0];
            p2 = v[1];
        }
    }
    if(p1 > p2){
        std::cout << "first" << std::endl;
    }else if (p1 < p2){
        std::cout << "second" << std::endl;
    }else{
        std::cout << "draw" << std::endl;
    }

}

int main() {
    test solve();
    return 0;
}