#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	int T;
	int a;
	int b;
	scanf("%d ", &T);
	while(T--){
		scanf("%d %d ", &a, &b);
		vector<int> digits;
		int curr = a % 10;
		if(b == 0){
			printf("1\n");
			continue;
		}
		do{
			digits.push_back(curr);
			curr = (curr * a) % 10;
		}while(curr != a % 10);
		int result = digits.at((b % digits.size() - 1) % digits.size());
		
		printf("%d\n", result);
	}
	return 0;
}