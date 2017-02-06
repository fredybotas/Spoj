#include <stdio.h>
#include <math.h>


int doable(long long num, long long a){
	long long b2 = num - a*a;
	if(sqrt(b2) * sqrt(b2) >= b2)
		return 1;
	else
		return 0;
}


int main(){
	int T;
	long long num;
	scanf("%d ", &T);
	while(T--){
		scanf("%llu ", &num);
		long long min = 1, high = sqrt(num);
		while(min < high){
			long long mid = (min + high) / 2;
			if(doable(num, mid) == 0)
				high = mid;
			else
				min = mid + 1;
		}

	}
	return 0;
}