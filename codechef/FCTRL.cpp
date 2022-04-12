#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i,start,end)     for(int i = start; i < end ; ++i)
#define loops                   while(true)
#define compare_float(a,b)    (abs(a - b) < 1e-9) ? true:false
#define SQ(a)                 (a)*(a)
#define CUBE(a)               (a)*(a)*(a)



ll Z(ll N){
    ll factor = 5, zeroes = 0;
    loops {
        int quotient = N/factor;
        if(quotient) { 
            zeroes += quotient;
            factor *= 5;
            continue;
        }
        return zeroes;
    }
}

void solve(){
    ll N;
    scanf("%lld", &N);
    printf("%lld\n", Z(N));
}



int main(){
    test solve();
    return 0;
}