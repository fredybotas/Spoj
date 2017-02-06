#include <stdio.h>

int candies[10003];

int main(){
	int N;
	while(2){
		scanf("%d ", &N);
		if(N == -1)
			break;
		int i;
		int sum = 0;
		for(i = 0; i < N; i++){
			scanf("%d ", &candies[i]);
			sum += candies[i];
		}
		int result = 0;
		if(sum % N)
			printf("-1\n");
		else{
			int avg = sum / N;
			for(i = 0; i < N; i++){
				if(candies[i] < avg)
					result += avg - candies[i];
			}
			printf("%d\n", result);
		}
	}

	return 0;
}