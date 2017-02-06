#include <stdio.h>
#include <math.h>

int rec(int N, int K){
	if(N == 0 && K == 0)
		return 1;
	if(N == 0)
		return 0;
	return rec(N - 1, K - 1) + rec(N - 1, K);
}

int main(){
	int T,a,b;
	scanf("%d ", &T);
	while(T--){
		scanf("%d %d ", &a, &b);
		printf("%d", rec(a,b));
		printf("%d\n", (int)((rec(a, b) / pow(6, b)) * 100));

	}

	return 0;
}