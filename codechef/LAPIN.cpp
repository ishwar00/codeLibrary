#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define test                  int x; cin >> x; while(x--) 
#define loop(i, n)            for(int i = 0; i < n ; ++i)
#define inf                   while(true)
#define compare_float(a, b)   (abs(a - b) < 1e-9) ? true:false
#define SQ(a)                 (a)*(a)

int length(char a[]){
    int count = 0, i = -1;
    while(a[++i])   ++count;
    return count;
}    

int check(char a[], char b[]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void solve(){
    char S[1000];
    scanf("%s", &S);
    char frequency1[26] = {0}, frequency2[26] = {0};
    
    int len = length(S);
    for (int i = 0; i < len/2; ++i)    ++frequency1[S[i]-'a'];
    if (len&1) ++len;
    for (int i = len/2; i < len; ++i)   ++frequency2[S[i]-'a'];

    int c = check(frequency1, frequency2);
    if(c) 
        printf("YES\n");
    else
        printf("NO\n");
}

int main(){
    test solve();
    return 0;
}
