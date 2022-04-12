
#include<iostream>

int main(){
    int tests;
    scanf("%d", &tests);
    while(tests--){
        int N, pay, coins[3] = {0} , flag = 1;
        scanf("%d", &N);

        for(int i = 0; (i < N); ++i){
            scanf("%d",&pay);
            if(!flag) continue;
            int change = pay - 5;
            ++coins[change/5];
            //printf("crossed1\n");
            switch(change){
            case 0:
                break;
            case 5:
                if(coins[change/5 - 1]){
                    --coins[change/5 - 1];
                }else
                    flag = 0;
                //printf("crossed 2\n");
                break;
            case 10:
                if(coins[change/5 - 1]){
                    --coins[change/5 - 1];
                }else if(coins[change/5 - 2] > 1){
                    coins[change/5 - 2] -= 2;
                }else
                    flag = 0;    
               // printf("crossed 3\n");
            }
        }
        if(flag) 
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}
