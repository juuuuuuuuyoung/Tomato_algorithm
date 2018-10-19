#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N,M;
int mem[9][9]; //원래 지도 배열
int mem2[9][9]; //새로 벽을 세운 후의 지도 배열
bool visited[9][9]={0}; //BFS에서 쓰일 viisted
vector<pair<int, int>> canmakewall; //벽을 세울 수 있는 곳
vector<pair<int, int>> now;//현재 새로 새운 벽의 위치

int maxnum = 0; //최대 안전영역

int BFS(vector<pair<int, int>> &now){	
	queue<pair<int, int>> virus;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			visited[i][j] = 0;  //visited초기화
			mem2[i][j] = mem[i][j]; //mem2에 복사
			if(mem2[i][j] == 2) virus.push(make_pair(i,j)); //바이러스시작점 queue에 넣기
		}
	}
	//now에서 고른 위치로 벽 세우기
	for(int i = 0; i < now.size(); i++){
		mem2[now[i].first][now[i].second]=1;
	}
	//바이러스 퍼트리기
	int dy[]={-1,1,0,0};
	int dx[]={0,0,-1,1};
	while(!virus.empty()){
		int y = virus.front().first;
		int x = virus.front().second;

		virus.pop();

		mem2[y][x] = 2;
		visited[y][x] = true;
		for(int i =  0; i < 4; i++){
			int ny = y+dy[i];
			int nx = x+dx[i];
			if(ny>=0 && ny<N && nx>=0 && nx<M){
				if(mem2[ny][nx]!=1 && !visited[ny][nx]){
					virus.push(make_pair(ny,nx));
				}
			}
		}

	}
	//안전영역 계산
	int ans = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(mem2[i][j] == 0) ans++;
		}
	}
	return ans;
}

void Go(int idx, int cnt){
	if(cnt == 3){//새로 세울 벽 3개 고르면, 안전영역 계산하기	
		maxnum = max(maxnum,BFS(now));//최솟값찾기
		return ;
	}
	if(idx+1<canmakewall.size()){ //벽3개 고르는 조합계산
		now.push_back(make_pair(canmakewall[idx+1].first,canmakewall[idx+1].second));
		Go(idx+1,cnt+1);
		now.pop_back();
		Go(idx+1,cnt);
	}
	return;
}
int main(){

	cin >> N >> M;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> mem[i][j];
			if(mem[i][j]==0)canmakewall.push_back(make_pair(i,j));
		}
	}
  
	now.push_back(make_pair(canmakewall[0].first,canmakewall[0].second));
	Go(0, 1);
	now.pop_back();
	Go(0, 0);

	cout << maxnum;
	return 0;
}
