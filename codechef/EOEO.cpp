
#include<iostream>


long long factors(long long TS){
    long long factor = 2;
    while(!(TS % 2)){
        factor *= 2;
        TS /= 2;
    }
    return factor ;
}



int main(){
    int tests;
    std::cin >> tests;
    while(tests--){
        long long TS, JS = 0;
        std::cin >> TS;
        if(TS & 1) 
            JS = (TS - 1)/2;
        else
            JS = TS/factors(TS);
        std::cout << JS << std::endl;
    }
    return 0;
}

