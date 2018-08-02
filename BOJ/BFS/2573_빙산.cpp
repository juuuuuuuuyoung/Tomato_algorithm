#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int N,M;
int mat[301][301]={0};
bool visited[301][301]={false};
int meltnum[301][301]={0};
int year=0;

void melting(){
	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	int tx, ty;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(mat[i][j]!=0){
				//0개수세고 빼기 ... 이건따로 빼야겠다.
				int count = 0; //근처 0개수
				for(int k = 0; k < 4; k ++){
					tx = j + dx[k];
					ty = i + dy[k];	
					if(tx>=0 && ty>=0 && tx<M && ty<N){
						if(mat[ty][tx]==0) count++;
					}	
				}
				meltnum[i][j] = count;
			}
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			mat[i][j] -= meltnum[i][j];
			if(mat[i][j]<0) mat[i][j] = 0;
		}
	}
	memset(meltnum,0,sizeof(meltnum));
}
void dfs(int i, int j){
	visited[i][j]=true;

	int dx[4]={0,1,0,-1};
	int dy[4]={1,0,-1,0};
	int tx, ty;

	//빙산개수
	for(int k = 0; k < 4; k ++){
		tx = j + dx[k];
		ty = i + dy[k];

		if(tx>=0 && ty>=0 && tx<M && ty<N){
			if(mat[ty][tx]!=0 && visited[ty][tx]==false) {
				visited[ty][tx]=true;	
				dfs(ty,tx);
			}
		}	
	}
}
void dfsAll(){
	year++;
	melting();
	int cnt = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if((mat[i][j]!=0)&& (visited[i][j]==false) ){
				dfs(i,j);
				cnt++;
			}
		}
	}

	if(cnt == 1) {
		memset(visited,false,sizeof(visited));
		dfsAll();
	}
	else if(cnt == 0){
		year = 0;
	}
}

int main(){	
	cin >> N>>M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> mat[i][j];
		}
	}
	dfsAll();
	cout << year;
}
