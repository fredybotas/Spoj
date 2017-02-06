#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min(x,y) (x > y ? y : x)


char buffer[6200];
int DP[6200][6200];


int palindrome(int begin, int end){
	if(DP[begin][end] != -1)
		return DP[begin][end];
	if(begin >= end)
		return DP[begin][end] = 0;
	if(buffer[begin] == buffer[end])
		return DP[begin][end] = palindrome(begin + 1, end - 1);
	else
		return DP[begin][end] = 1 + min(palindrome(begin + 1, end), palindrome(begin, end - 1));
}

int main(){
	int T;
	scanf("%d ", &T);
	while(T--){
		scanf("%s", buffer);
		memset(DP, -1, sizeof(DP));
		printf("%d\n", palindrome(0, strlen(buffer) - 1));
	}
	return 0;
}