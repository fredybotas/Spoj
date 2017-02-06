#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//7
// 0 1 2 3 4 5 6
// a b c d c b a

//8
// 0 1 2 3 4 5 6 7 
// a b c d d c b a

//7161391

char buffer[1000003];

int main(){
	int N;
	scanf("%d ", &N);
	while(N--){
		scanf("%s",buffer);
		int left,right,len = strlen(buffer);
		if(len % 2 == 1){
			left = len/2;
			right = len/2;
		}else{
			left = len/2 - 1;
			right = len/2;
		}
		int flag = -1;
		int edited = 0;
		while(left > -1){
			if(buffer[left] > buffer[right] && flag == -1)
				flag = 0;
			if(buffer[left] < buffer[right] && flag == -1)
				flag = 1;
			buffer[right] = buffer[left];
			left--;
			right++;
		}
		int remainder = 0;
		if(flag){
			if(len % 2 == 1){
				left = len/2;
				right = len/2;
			}else{
				left = len/2 - 1;
				right = len/2;
			}
			if(left == right){
				if(buffer[left] == '9'){
					remainder++;
					buffer[left] = '0';
				}
				else
					buffer[left] += 1;
			}else{
				if(buffer[left] == '9'){
					remainder++;
					buffer[left] = '0';
					buffer[right] = '0';
				}
				else{
					buffer[left] += 1;
					buffer[right] += 1;
				}
			}
			left--;
			right++;
			while(left > -1){
				if(remainder){
					remainder = 0;
					if(buffer[left] == '9'){
						remainder++;
						buffer[left] = '0';
						buffer[right] = '0';
					}
					else{
						buffer[left] += 1;
						buffer[right] += 1;
					}	
				}
			left--;
			right++;
			}
		}
		if(remainder){
			int i;
			putchar('1');
			for(i = 0;i < len - 1; i++)
				putchar('0');
			putchar('1');
			putchar('\n');
		}
		else
			printf("%s\n", buffer);
	}
	return 0;
}