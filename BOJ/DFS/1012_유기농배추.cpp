#include<iostream>
#include<vector>
using namespace std;

int cnt = 0;
int mat[50][50]={false};
int T;
int M,N,K;
void dfs(int i, int j){
	mat[i][j] = 0;
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	int tx, ty;
	
	for(int k = 0; k < 4; k ++){
		tx = j + dx[k];
		ty = i + dy[k];
		if(tx>=0 && ty>=0 && tx<M && ty<N){
			if(mat[ty][tx]==1) dfs(ty,tx);
		}	
	}
}
void dfsAll(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(mat[i][j]==1){
				dfs(i,j);
				cnt++;
			}
		}
	}
}

int main(){
	scanf("%d", &T);	
	int y,x;	
	for(int s=0; s <T; s++){
		scanf("%d %d %d",&N,&M,&K);
		for(int i = 0; i < K; i++){
			scanf("%d %d",&y, &x);
			mat[y][x] = 1;
		}
		dfsAll();
		printf("%d\n",cnt);
		cnt = 0;
	}
}
