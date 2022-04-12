#include<stdio.h>

int main(){
	int cases, max = 0, dish;
	scanf("%d", &cases);

	while(cases--){
		int lenght;
		int freq[10001] = {0};
		scanf("%d", &lenght);
		
		int input = 0, count = 1, pre_input;
		scanf("%d", &pre_input);

		for(int j = 0; j < lenght; j++){
		    if(j < lenght - 1){
		        scanf("%d", &input);
            }
			if(input == pre_input){
				count++;
				if(j != (lenght - 1)){
					continue;
				}
				count--;
			}
			freq[pre_input] += (count%2 + count/2);
			count = 1;
			
			if(max == freq[pre_input] && dish > pre_input){
				dish = pre_input;
			}else if(max < freq[pre_input]){
				max = freq[pre_input];
				dish = pre_input;
			}
			pre_input = input;
		}
		max = 0;
		printf("%d\n", dish);
	}
}