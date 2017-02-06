#include <stdio.h>
#include <set>
#include <string>

using namespace std;

int main(){
	int N;
	scanf("%d ", &N);
	int i, i1;
	set<string> set;
	for(i = 1; i <= N; i++){
		for(i1 = 1; i1 <= N/i; i1++){

			string rekt = i < i1 ? to_string(i) + ',' + to_string(i1) : to_string(i1) + ',' + to_string(i);
			set.insert(rekt); 
		}
	}
	printf("%lu\n", set.size());
	return 0;
}