#include <stdio.h>
#include <queue>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct pos{
	int x;
	int y;
	int k;
};

int visited[10][10];

int inBoard(int x, int y){
	if(x >= 0 && x <= 7 && y>= 0 && y <= 7)
		return 1;
	return 0;
}

pos create(int a, int b, int c){
	pos K;
	K.x = a;
	K.y = b;
	K.k = c;
	return K;
}

int main(){
	int T;
	scanf("%d ", &T);
	char src[5], dest[5];
	while(T--){
		scanf("%s %s ", src, dest);
		pos start, end;
		start.x = src[0] - 'a'; 
		start.y = src[1] - '0' - 1;
		start.k = 0;
		end.x = dest[0] - 'a';
		end.y = dest[1] - '0' - 1;
		queue<pos> queue;
		queue.push(start);
		memset(visited, -1 ,sizeof(visited));
		visited[start.x][start.y] = 1;
		int result = -1;
		while(!queue.empty()){
			pos curr = queue.front();
			queue.pop();
			if(curr.x == end.x && curr.y == end.y)
				result = curr.k;
			if(inBoard(curr.x + 2, curr.y + 1) && visited[curr.x + 2][curr.y + 1] == -1){
				queue.push(create(curr.x + 2, curr.y + 1, curr.k + 1));
				visited[curr.x + 2][curr.y + 1] = 1;
			}

			if(inBoard(curr.x - 2, curr.y + 1) && visited[curr.x - 2][curr.y + 1] == -1){
				queue.push(create(curr.x - 2, curr.y + 1, curr.k + 1));
				visited[curr.x - 2][curr.y + 1] = 1;
			}

			if(inBoard(curr.x + 2, curr.y - 1) && visited[curr.x + 2][curr.y - 1] == -1){
				queue.push(create(curr.x + 2, curr.y - 1, curr.k + 1));
				visited[curr.x + 2][curr.y - 1] = 1;
			}

			if(inBoard(curr.x - 2, curr.y - 1) && visited[curr.x - 2][curr.y - 1] == -1){
				queue.push(create(curr.x - 2, curr.y - 1, curr.k + 1));
				visited[curr.x - 2][curr.y - 1] = 1;
			}
			if(inBoard(curr.x + 1, curr.y + 2) && visited[curr.x + 1][curr.y + 2] == -1){
				queue.push(create(curr.x + 1, curr.y + 2, curr.k + 1));
				visited[curr.x + 1][curr.y + 2] = 1;
			}

			if(inBoard(curr.x - 1, curr.y + 2) && visited[curr.x - 1][curr.y + 2] == -1){
				queue.push(create(curr.x - 1, curr.y + 2, curr.k + 1));
				visited[curr.x - 1][curr.y + 2] = 1;
			}

			if(inBoard(curr.x + 1, curr.y - 2) && visited[curr.x + 1][curr.y - 2] == -1){
				queue.push(create(curr.x + 1, curr.y - 2, curr.k + 1));
				visited[curr.x + 1][curr.y - 2] = 1;
			}

			if(inBoard(curr.x - 1, curr.y - 2) && visited[curr.x - 1][curr.y - 2] == -1){
				queue.push(create(curr.x - 1, curr.y - 2, curr.k + 1));
				visited[curr.x - 1][curr.y - 2] = 1;
			}

		}
		printf("%d\n",result);
	}
	return 0;
}