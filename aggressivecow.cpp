#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N,C;
vector<int> stalls;

int checkN(int diff){
	int cows = C;
	int i;
	int result;
	int lastpos = 0;
	for(i = 0; i < N; i++){
		if(!cows)
			break;
		if(!lastpos){
			lastpos = stalls.at(i);
			cows--;
			continue;
		}

		if(stalls.at(i) - lastpos >= diff){
			cows--;
			lastpos = stalls.at(i);
		}
	}
	if(cows)
		return 0;
	else
		return 1;
}

int main(){
	int T;
	scanf("%d ", &T);
	while(T--){
		scanf("%d %d ", &N, &C);
		int i, max_stall = 0, stall;
		stalls.clear();
		for(i = 0; i < N; i++){
			scanf("%d ", &stall);
			stalls.push_back(stall);
			if(stalls[i] > max_stall)
				max_stall = stalls[i];
		}
		sort(stalls.begin(), stalls.end());
		int start = 0;
		int end = max_stall/(C - 1) + 1;
		int mid, final;
		while(end - start > 1){
			mid = (start + end)/2;
			if(checkN(mid)){
				start = mid;
				final = mid;
			}
			else
				end = mid;
		}
		printf("%d\n", final);

	}

	return 0;
}