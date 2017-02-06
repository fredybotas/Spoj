#include <stdio.h>

int sums[1000000008];
int done = 1;

void fib(int n){
	sums[n] = (sums[n-1] + sums[n-2]) % 1000000007;
	done = n;
}

int main(){
	int T, i;
	int N, M;
	int sum;
	scanf("%d ", &T);
	sums[0] = 0;
	sums[1] = 1;
	while(T--){
		sum = 0;
		scanf("%d %d ", &N, &M);
		while(done < M)
			fib(done + 1);
		for(i = N; i <= M; i++)
			sum += sums[i] % 1000000007;
		printf("%d\n", sum);
	}

	return 0;
}