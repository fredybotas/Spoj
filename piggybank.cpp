#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define min(a,b) (a > b ? b : a)

int weights[502];
int values[502];
int DP[10005];
int T, N;

int rec(int weight){
	if(weight == 0)
		return DP[weight] = 0;
	if(DP[weight] != -1)
		return DP[weight];
	int i;
	int curr_min = INT_MAX;
	for(i = 0; i < N; i++){
		if(weight >= weights[i])
			curr_min = min(curr_min, values[i] + rec(weight - weights[i]));
	}
		if(curr_min == INT_MAX)
			return DP[weight] = 5000001;
		else 
			return DP[weight] = curr_min;
}


int main(){
	int min, max;
	scanf("%d ", &T);
	while(T--){
		scanf("%d %d ", &min, &max);
		scanf("%d ", &N);
		int i;
		memset(DP, -1, sizeof(DP));
		for(i = 0; i < N; i++)
			scanf("%d %d ", &values[i], &weights[i]);
		int result = rec(max - min);
		if(DP[0] != 0)
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n", result);

	}
	return 0;
}