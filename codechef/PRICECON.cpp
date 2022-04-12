#include <iostream>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	
	while(tests--){
	    int lost_revenu = 0, size, K;
	    cin >> size >> K;
	    for(int i = 0; i < size ; ++i){
	        int price;
	        cin >> price;
	        if((price - K) > 0){
	            lost_revenu += (price - K); 
	        }
	    }
	    cout << lost_revenu << "\n";
	}
	return 0;
}
