#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include <limits.h>

using namespace std;


vector<vector<pair<int, int> > > neighbours;
vector<string> mesta;
vector<pair<string, string> > objectives;


int dijkstra(int start, int end){
	priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
	int distance[mesta.size() + 1], final[mesta.size() + 1];
	int i;
	for(i = 1; i <= mesta.size(); i++){
		distance[i] = INT_MAX;
		final[i] = 0;
	}
	distance[start] = 0;
	min_heap.push(make_pair(0, start));
	while(!min_heap.empty()){
		int min = min_heap.top().first;
		int min_index = min_heap.top().second;
		min_heap.pop();
		if(final[min_index])
			continue;
		if(min_index == end)
			break;

		vector<pair<int, int > > adjacency = neighbours.at(min_index);
		for(i = 0; i < adjacency.size(); i++){
			int weight = adjacency.at(i).first;
			int vertex = adjacency.at(i).second;
			if (distance[vertex] > distance[min_index] + weight){
                distance[vertex] = distance[min_index] + weight;
                min_heap.push(make_pair(distance[vertex], vertex));
            }
		}
		final[min_index] = 1;
	}
	return distance[end];
}

int getIndex(string a){
	int i;
	for(i = 0; i < mesta.size(); i++){
		if(mesta.at(i) == a)
			return i;
	}
}

int main(){
	int N,S;
	scanf("%d ", &S);
	while(S--){
		scanf("%d ", &N);
		int i;
		char temp[15];
		vector<pair<int, int> > a;
		neighbours.clear();
		mesta.clear();
		objectives.clear();
		neighbours.push_back(a);
		string ahoj;
		mesta.push_back(ahoj);
		for(i = 1; i <= N; i++){
			string mesto;
			scanf("%s ", temp);
			mesto = temp;
			mesta.push_back(mesto);
			int count, numbero, length;
			vector<pair<int, int> > b;
			neighbours.push_back(b);
			scanf("%d ", &count);
			while(count--){
				scanf("%d %d ", &numbero, &length);
				neighbours.at(i).push_back(make_pair(length, numbero));
			}
		}
		int R;
		scanf("%d ", &R);
		char temp1[15];
		string a1,b1;
		while(R--){
			scanf("%s %s ", temp, temp1);
			a1 = temp;
			b1 = temp1;
			printf("%d\n", dijkstra(getIndex(a1), getIndex(b1)));
		}
	}
	return 0;
}
