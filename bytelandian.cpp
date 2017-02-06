#include <stdio.h>
#include <map>


using namespace std;

map<int, long long> a;

long long coin_exchange(int N){
	auto it = a.find(N);
	if(it != a.end())
		return it->second;
	else{
	if(N == 0)
		return 0;
	else if(N == 1)
		return 1;
	else if(N == 2)
		return 2;
	else if(N == 3)
		return 3;
	else if(N == 4)
		return 4;
	else{
		long long result =coin_exchange(N/2) + coin_exchange(N/3) + coin_exchange(N/4); 
		long long count = result > N ? result : N; 
		a.insert(make_pair(N, count));
		return count;
		}
	}
}
	

int main(){
	int N;
	while(scanf("%d ", &N) > 0){
		printf("%lld\n",coin_exchange(N));
	}

	return 0;
}