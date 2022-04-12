#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define       test  int x;    cin >> x; while (x--)
#define       loop(i, start, end)  for(int i = start; i < end; ++i)
#define       inf while (true)
#define       compare_float(a, b) (abs(a - b) < 1e-9) ? true : false;
#define       SQ(a) (a) * (a)
#define       CUBE(a) (a) * (a) * (a)

const int size = 1e6;

std::vector<bool> primes(size+1, true);

void seive(){
    primes[0] = primes[1] = false; 
    for(int i = 2; i*i <= size; ++i){
        if(primes[i]){
            for(int j = i*i; j <= size; j += i){
                primes[j] = false;
            }
        }
    }
}

std::vector<long long> prime_count(size+1);
void preprocess(){
    long long count_prime = 0;
    for(int i = 2; i <= size; ++i){
        if(primes[i])   count_prime++;
        prime_count[i] = count_prime;
    }
}

void solve() {
    int n;
    std::cin >> n;
    int seconds = 0;
    if(n == 1) seconds = 0;
    else if(n == 2) seconds = 1;
    else  seconds = prime_count[n] + n - 3;
    std::cout << seconds << "\n";
}

int main() {
    seive();
    preprocess();
    test solve();
    return 0;
}