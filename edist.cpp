#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define min(a,b,c) (a < b && a < c ? a : ((b < c) ? b : c))

int DP[3002][3002];
char str1[3002];
char str2[3002];


int rec(int pos1, int pos2, int len1, int len2){
	if(DP[pos1][pos2] != -1)
		return DP[pos1][pos2];
	if(pos1 > len1 || pos2 > len2)
		return abs(pos1 - pos2) + abs(len1 - len2);
	if(str1[pos1] == str2[pos2])
		return DP[pos1][pos2] = rec(pos1 + 1, pos2 + 1, len1, len2);
	else
		return DP[pos1][pos2] = 1 + min(rec(pos1 + 1, pos2 + 1, len1, len2), rec(pos1, pos2 + 1, len1, len2), rec(pos1 + 1, pos2, len1, len2));
}

int main(){
	int T;
	scanf("%d ", &T);
	while(T--){
		scanf("%s %s ", str1, str2);
		memset(DP, -1 , sizeof(DP));
		printf("%d\n", rec(0,0,strlen(str1) - 1, strlen(str2) - 1));
	}
	return 0;
}