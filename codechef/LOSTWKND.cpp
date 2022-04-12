#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while(cases--){
	    int tot_eq_hours = 0, A;
	    for(int i = 0; i < 5; ++i){
	        cin >> A;
	        tot_eq_hours += A; 
	    }
	    int p;
	    cin >> p;
	    tot_eq_hours *= p;
	    if(tot_eq_hours <= 120)
	        printf("No\n");
	    else
	        printf("Yes\n");
	}
	return 0;
}
