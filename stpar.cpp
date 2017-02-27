#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>

using namespace std;



int main(){
  int N;
  int i, a;
  int expecting = 1;
  while(scanf("%d", &N) > 0){
    if(N == 0)
      break;
      stack<int> street;
    queue<int> cars;
    for(i = 0; i < N; i++){
      scanf("%d ", &a);
      cars.push(a);
    }
    expecting = 1;
    int change = 1;
    while(change){
      change = 1;

      if(!cars.empty() && cars.front() == expecting){
        cars.pop();
        expecting++;
      }
      else if(!street.empty() && street.top() == expecting){
        street.pop();
        expecting++;
      }
      else if(!cars.empty()){
        street.push(cars.front());
        cars.pop();
      }else
        change = 0;
    }

    if(street.empty() && cars.empty())
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
