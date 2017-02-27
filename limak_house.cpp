#include <stdio.h>
#include <string.h>

int main(){
  //najdi spodok
  char buffer[20];
  int curr, i, low = 0, high = 1000;
  while(low < high){
    curr = (low + high) / 2;
    printf("? %d %d\n", curr, 0);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      low = curr + 1;
    else
      high = curr;
  }

  for(i = curr - 3; i < curr + 4; i++){
    if(i == 1000){
      curr = 1000;
      break;
    }
    printf("? %d %d\n", i, 0);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      continue;
    else{
      curr = i - 1;
      break;
    }
  }
  int x_square = curr*2;
  //trojuholnik
  low = x_square/2;
  high = 1000;
  while(low < high){
    curr = (low + high) / 2;
    printf("? %d %d\n", curr, x_square);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      low = curr + 1;
    else
      high = curr;
  }
  for(i = curr - 3; i < curr + 4; i++){
    if(i == 1000){
      curr = 1000;
      break;
    }
    printf("? %d %d\n", i, x_square);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      continue;
    else{
      curr = i - 1;
      break;
    }
  }
  int x_triangle = curr*2;
  low = x_square;
  high = 1000;
  while(low < high){
    curr = (low + high) / 2;
    printf("? %d %d\n", 0, curr);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      low = curr + 1;
    else
      high = curr;
  }

  for(i = curr - 3; i < curr + 4; i++){
    if(i == 1000){
      curr = 1000;
      break;
    }
    printf("? %d %d\n", 0, i);
    fflush(stdout);
    scanf("%s", buffer);
    if(!strcmp(buffer, "YES"))
      continue;
    else{
      curr = i - 1;
      break;
    }
  }
  int height = curr;
  printf("! %d\n", x_square*x_square + x_triangle*(height - x_square)/2);
  fflush(stdout);
  return 0;
}
