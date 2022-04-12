#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i,start,end)     for(int i = start; i < end ; ++i)
#define inf                   while(true)
#define compare_float(a,b)    (abs(a - b) < 1e-9) ? true:false
#define SQ(a)                 (a)*(a)

void solve(){
    int N;
    scanf("%d", &N);
    int max_spds[N];
    loop(i,0,N) scanf("%d", &max_spds[i]);
    
    int max_spd_crs = 0, cur_max_spd = INT_MAX;
    loop(i,0,N){
        if(max_spds[i] <= cur_max_spd){
            cur_max_spd = max_spds[i];
            max_spd_crs++;
        }
    }
    printf("%d\n", max_spd_crs);
}

int main(){
    test solve();
    return 0;
}