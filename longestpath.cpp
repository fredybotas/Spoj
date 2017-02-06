#include <stdio.h>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <limits.h>

/*

		a
 	b 	\	c
d		e\		f


*/

using namespace std;
int root = INT_MAX;
vector<int> graph[10001];
int visited[10001];

int longestPath(){
	queue<pair<int, int > > queue;
	int i;
	for(i = 0; i < 10001; i++)
		visited[i] = 0;
	queue.push(make_pair(root,0));
	int max_height = 0;
	while(!queue.empty()){
		int curr = queue.front().first;
		int height = queue.front().second;
		queue.pop();
		if(max_height < height){
			root = curr;
			max_height = height;
		}
		for(i = 0; i < graph[curr].size(); i++){
			if(!visited[graph[curr].at(i)]){
				queue.push(make_pair(graph[curr].at(i), height + 1));
				visited[graph[curr].at(i)] = 1;
			}
		}
	}
	return max_height;
}

int main(){
	int N;
	scanf("%d ", &N);
	int i, i1;
	for(i = 0; i < N - 1; i++){
		int a,b;
		scanf("%d %d ", &a, &b);
		if(a < root)
			root = a;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
		longestPath();
		printf("%d\n", longestPath());
	return 0;
}
