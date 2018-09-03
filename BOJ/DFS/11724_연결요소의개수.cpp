#include<iostream>
#include<vector>
using namespace std;

int N, M;
int mem[1001][1001]={0};
int visited[1001]={0};

void Go(int n){
	if(visited[n]) return ;
	visited[n] = true;
	
	for(int i = 1; i <=N; i++){
		if(mem[n][i] && !visited[i]){
			Go(i);
		}
	}
}
int main(){
	cin >> N >> M;
	int cnt = 0;
	for(int i = 0; i < M; i++){
		int a,b;
		cin >> a >> b;
		mem[a][b] = 1;
		mem[b][a] = 1;
	}

	for(int i = 1; i <=N; i++){
		if(!visited[i]){
			Go(i);	
			cnt++;
		}
		
	}
	
	cout << cnt;
	return 0;
}
