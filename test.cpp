#include <stdio.h>

int main(){
	int a = 0;
	while(a != 42){
		scanf("%d ", &a);
		if(a != 42)
			printf("%d\n", a);
	}
	return 0;
}