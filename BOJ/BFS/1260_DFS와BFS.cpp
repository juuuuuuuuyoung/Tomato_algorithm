#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N,M,V;

bool visited[1001] = {false,};
bool graph[1001][1001] = {false,};


void dfs(int current)
{
	if(!visited[current]){ 
		cout<<current<<" ";
		visited[current] = true;
		for(int i = 1; i <= N; ++i)
		{
			if(!visited[i] && graph[current][i])
				dfs(i);
		}
	}
}

void bfs(int start){
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int current = q.front();
		q.pop();
		if(!visited[current])
		{
			cout<<current<<" ";
			visited[current] = true;

			for(int i = 1; i <= N; ++i)
				if(!visited[i] && graph[current][i])
					q.push(i);
		}
	}
}

int main(void){
	cin>>N>>M>>V;
	for(int i = 1; i <= M; ++i){
		int a,b;
		cin>>a>>b;
		graph[a][b] = graph[b][a] = true;
	}
	dfs(V);
	cout<<'\n';
	memset(visited, false, sizeof(visited));
	bfs(V);
	return 0;
}
