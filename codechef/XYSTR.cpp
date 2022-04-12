#include<iostream>
#include<string>

int main(){
    int tests;
    std::cin >> tests;
    while(tests--){
        std::string students;
        std::cin >> students;
        int count = 0, flag = 1;
        char pre_student = students[0];

        for(int i = 0; i < students.length(); ++i){
            if(pre_student == students[i])
                flag = 0;
            else
                flag = 1;
        if(flag){ 
            count++;
            i++ ;
        }
        pre_student = students[i];
        }

        std::cout << count << std::endl;
    }
    return 0;
}