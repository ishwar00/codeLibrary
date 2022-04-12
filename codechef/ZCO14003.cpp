#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i,start,end)     for(int i = start; i < end ; ++i)
#define inf                   while(true)
#define compare_float(a,b)   (abs(a - b) < 1e-9) ? true:false
#define SQ(a)                 (a)*(a)

void solve(){
    ll N;
    scanf("%lld", &N);
    int cust[N];
    loop(i,0,N)    scanf("%d", &cust[i]);
    sort(cust, N+cust);
    ll revenue = 0;
    loop(i,0,N){
        ll cur_rev;
        cur_rev = cust[i]*(N-i);
        if(cur_rev > revenue){
            revenue = cur_rev;
        }
    }
    printf("%lld",revenue); 
}

int main(){
    solve();
    return 0;
}