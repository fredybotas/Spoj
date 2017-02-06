#include <stdio.h>
#include <math.h>


int main(){

	int T,a;
	scanf("%d ", &T);
	while(T--){
		scanf("%d ", &a);
		int sum = 0;
		int i = 1;
		while(a / (int)pow(5, i) >= 1){
			sum += a / pow(5, i);
			i++;
		}
		printf("%d\n", sum);
	}
}