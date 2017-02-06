#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[10003];
int visited[10003];
int root;

int isTree(){
	int i;
	for(i = 0; i < 10003; i++)
		visited[i] = 0;
	visited[root] = 1;
	int counter = 1;
	stack<int> stack;
	stack.push(root);
	while(!stack.empty()){
		int curr = stack.top();
		stack.pop();
		int i;
		for(i = 0; i < graph[curr].size(); i++){
			if(!visited[graph[curr].at(i)]){
				visited[graph[curr].at(i)] = 1;
				counter++;
				stack.push(graph[curr].at(i));
			}

		}
	}
	return counter;
}


int main(){
	int E,N;
	scanf("%d %d ", &N, &E);
	int i = E;
	while(i--){
		int a,b;
		scanf("%d %d ", &a, &b);
		root = a;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if(isTree() == N && N == E + 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}