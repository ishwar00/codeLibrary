#include <iostream>
using namespace std;

int main() {
	int T = 0;
	cin >> T;
	
	int X = 0;
	int Y = 0;
	int A = 0;
	int B = 0;
	int K = 0;
	
	for(int i = 0; i < T; ++i) {
	    
	    cin >> X >> Y >> A >> B >> K;
	    
	    int petrol_price = X + A * K;
	    int desiel_price = Y + B * K;
	    
	    if(petrol_price > desiel_price) 
	    {
	        cout << "DIESEL" << endl;
	    }
	    else if(desiel_price > petrol_price) 
	    {
	        cout << "PETROL" << endl;
	    } 
	    else 
	    {
	        cout << "SAME PRICE" << endl;
	    }
	}
	return 0;
}
