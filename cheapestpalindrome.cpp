#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char buffer[50];

int min(int a, int b){
	return a < b ? a : b;
}

int palindrome(int start, int end){
	putchar('a');
	if(start == end)
		return buffer[start] - 'a';
	else if(start > end)
		return 0;
	if(buffer[start] == buffer[end])
		return buffer[start] - 'a' + buffer[end] - 'a' + palindrome(start + 1, end - 1);
	else
		return min(palindrome(start, end - 1) + buffer[end] - 'a' + buffer[end] - 'a', palindrome(start + 1, end) + buffer[start] - 'a' + buffer[start] - 'a');
}


int main(){
	while(scanf("%s", buffer) > 0){
	printf("%d\n", palindrome(0,strlen(buffer) - 1));
	}
	return 0;
}
