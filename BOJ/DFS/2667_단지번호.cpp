#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int cnt = 1;
int ground[26][26];
bool visited[26][26]={false};

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
vector<int> ans;

int dfs(int y, int x){
	visited[y][x] = true;
	for(int i = 0; i < 4; i++){
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if(nexty>=0 && nexty<N && nextx>=0 && nextx<N){
			if(!visited[nexty][nextx]&&ground[nexty][nextx]==1){
				 dfs(nexty,nextx);
				 cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d",&ground[i][j]);
		}
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j <N; j++){
			if(!visited[i][j]&&ground[i][j]==1){
				int t = dfs(i,j);
				if(t>0) ans.push_back(t);
			}
			cnt = 1;
		}
	}
	sort(ans.begin(),ans.end());
	cout << ans.size()<<endl;
	for(int i = 0; i < ans.size();i++) 
		cout << ans[i] << endl;


	return 0;
}
