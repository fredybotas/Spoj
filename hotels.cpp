#include <stdio.h>
#include <deque>
#include <limits.h>

using namespace std;

int main(){
	int N, M;
	scanf("%d %d ", &N, &M);
	int num;
	int sum = 0;
	int max = 0;

	deque<int> sequence;
	
	while(N--){
		scanf("%d ", &num);
		sequence.push_back(num);
		sum += num;
		
		while(sum > M){
			sum -= sequence.front();
			sequence.pop_front();	
		}

		if(sum > max)
			max = sum;
	}
	printf("%d\n", max);
	return 0;
}