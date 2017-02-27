#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(){
  int T;
  scanf("%d ", &T);
  while(T--){
    int N;
    scanf("%d ", &N);
    int i;
    string word;
    string cookie = "cookie";
    string milk = "milk";
    int wasCookie = 0;
    int result = 1;
    for(i = 0; i < N; i++){
      cin >> word;
      if(word == cookie && wasCookie)
        result = 0;
      if(word == cookie)
        wasCookie = 1;
      else if(word == milk)
        wasCookie = 0;
    }

    if(result){
      if(wasCookie)
      printf("NO\n");
      else
      printf("YES\n");
    }
    else
      printf("NO\n");
  }
  return 0;
}
