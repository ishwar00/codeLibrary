#include<iostream>
using namespace std;
typedef long long ll;

void solve(){
    int N, flag = 0;
    cin >> N;
   
    ll Evens = 2, Odds = 1;
    for(int i = 1; i <= N*N; ++i){
        if(flag){ 
            printf("%lld", Evens);
            Evens += 2;
        }else{
            printf("%lld", Odds);
            Odds += 2;
        }
        flag = !flag;
        if(!(i%N)){
            if(!(N&1)) 
                flag = !flag;
            printf("\n");
        }else{
            printf(" ");
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}