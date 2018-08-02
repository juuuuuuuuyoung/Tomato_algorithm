#include<iostream>
using namespace std;

int M, N;
int mem[501][501];
int ans[501][501]={0};

bool visited[501][501] = {false};

int Go(int y, int x){
	if(y == M-1 && x == N-1) return 1;
	if(visited[y][x]) return ans[y][x];
	
	int dx[4]={-1,0,0,1};
	int dy[4]={0,-1,1,0};
	
	for(int k = 0; k < 4; k++){
		int nexty = y+dy[k];
		int nextx = x+dx[k];
		if(nextx>=0 && nexty>=0 && nextx<N && nexty<M){
			if(mem[y][x]>mem[nexty][nextx]){
				ans[y][x] += Go(nexty,nextx);
				visited[y][x] = true;
			}
		}
	}
	return ans[y][x];
}


int main(){
	cin >> M>> N;
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			cin >> mem[i][j];
		}
	}
	cout << Go(0,0);

	return 0;
}
