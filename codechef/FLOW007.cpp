#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i, n)            for(int i = 0; i < n ; ++i)
#define inf                   while(true)
#define compare_float(a, b)   (abs(a - b) < 1e-9) ? true:false
#define SQ(a)                 (a)*(a)

char reverse(){
    char c = getchar();
    if (c == '\n' || c == EOF)    return -1;
    if (reverse() == -1 && c == '0') {    return -1;    }
    cout << c ;
    return 0;
}

void solve(){
    reverse();
    cout << '\n';
}


int main(){
    test solve();
    solve();
    return 0;
}
