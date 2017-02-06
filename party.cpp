#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define max(a,b) (a > b ? a : b)


int price[105];
int fun[105];
int DP[105][505];

int rec(int N, int B){
	if(N < 0)
		return 0;
	if(DP[N][B] != -1)
		return DP[N][B];
	if(B < price[N])
		return DP[N][B] = rec(N - 1, B);
	else
		return DP[N][B] = max(fun[N] + rec(N - 1, B - price[N]), rec(N - 1, B));
}


int main(){
	int N, B;
	while(1){
		scanf("%d %d ", &B, &N);
		if(B == 0 && N == 0)
			break;
		int i, i1, i2;
		for(i = 0; i < N; i++)
			scanf("%d %d ", &price[i], &fun[i]);
		memset(DP, -1, sizeof(DP));
		int fun = rec(N - 1, B);
		int min = 0;
		int high = B;
		while(min < high){
			int curr = (min + high) / 2;
			if(rec(N - 1, curr) < fun)
				min = curr + 1;
			else
				high = curr;
		}
		printf("%d %d\n", high, fun);

	}
	return 0;
}


