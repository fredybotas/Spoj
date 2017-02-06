#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26

char buffer[10002];
long long DP[10002];

long long rec(int pos, int size){
	if(pos > size)
		return 1;
	if(buffer[pos] == '0')
		return 0;
	if(DP[pos] != -1)
		return DP[pos];
	if(pos + 1 <= size && (buffer[pos] - '0') * 10  + buffer[pos + 1] - '0' <= MAX)
		return DP[pos] = rec(pos + 1, size) + rec(pos + 2, size);
	else
		return DP[pos] = rec(pos + 1, size);
}


int main(){

	while(1){
		scanf("%s ", buffer);
		if(buffer[0] == '0')
			break;
		memset(DP, -1, sizeof(DP));
		long long result = rec(0, strlen(buffer) - 1);
		printf("%lld\n", result);
	}

	return 0;
}