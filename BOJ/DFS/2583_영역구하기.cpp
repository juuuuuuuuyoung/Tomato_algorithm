  //0:35
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int M, N, K;
bool visited[101][101]={0};
vector<int> result;
int sqcount= 0;
int cnt = 0;

void dfs(int y, int x){
	visited[y][x] = true;
	cnt ++;
	
	int dy[4]={-1,1,0,0};
	int dx[4]={0,0,-1,1};
	
	for(int i = 0; i < 4; i++){
		
		int nexty = y+dy[i];
		int nextx = x+dx[i];
		
		if(nexty>=0 && nexty<M && nextx>=0 && nextx<N){
			if(visited[nexty][nextx]==false){
				dfs(nexty,nextx);
			
			}
		}
	}
	return ;
}

int main(){
	cin >> M >> N>> K;
	int rx, ry, lx, ly ; 


	for(int i = 0; i < K; i++){
		cin >> lx >>ly>>rx>>ry;
		
		for(int j = ly; j<ry ; j++){
			for(int k = lx; k<rx; k++){
				visited[j][k] = true;
			}
		}
	}

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(visited[i][j]==true)continue;
			else{
			dfs(i,j);
			result.push_back(cnt);
			cnt = 0;
			sqcount++;
			}
		}
	}
	
	cout << sqcount<<endl;
	sort(result.begin(),result.end());
	for(auto temp : result) cout << temp << " ";

	return 0;
}
