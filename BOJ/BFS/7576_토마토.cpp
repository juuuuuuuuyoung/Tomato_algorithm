/*
box내에 
1 : 익은거
0 : 안익은거
-1 : 없음
ans
-1 : 토마토중에 다 못익은거
0 : 하루만에 다 익음
*/
#include<iostream>
#include<queue>
using namespace std;

int M,N;
int visited[1001][1001] = {false};
int box[1001][1001]; 

struct tomato{
	int y;
	int x;
	int day;
	tomato(int Y, int X, int d){
		y = Y;
		x = X;
		day = d;
	}
};

int main(){
	cin >> M >> N;
	queue<tomato> q;

	int tomatocnt = M*N;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> box[i][j];
			if(box[i][j] == 1) {q.push(tomato(i,j,0)); tomatocnt-=1; visited[i][j] = true;}
			else if(box[i][j] == -1) tomatocnt -=1;
		}
	}
	
	if(tomatocnt == 0) {
		cout << 0;
		return 0;
	}

	int lastday;

	while(!q.empty()){
		tomato now = q.front();
		q.pop();

		lastday = now.day;

		int dx[4] = {-1,1,0,0};
		int dy[4] = {0,0,-1,1};

		for(int i = 0; i < 4; i++){
			int nexty = now.y+dy[i];
			int nextx = now.x+dx[i];
			if(nexty>=0 && nexty <N && nextx>=0 && nextx<M){
				if(box[nexty][nextx] == 0 && visited[nexty][nextx] == false){
					q.push(tomato(nexty, nextx, now.day+1));
					visited[nexty][nextx] = true;
					tomatocnt-=1;
				}
			}
		}
		
	}
	if(tomatocnt != 0) cout << -1;
	else cout << lastday;
	return 0;
}
