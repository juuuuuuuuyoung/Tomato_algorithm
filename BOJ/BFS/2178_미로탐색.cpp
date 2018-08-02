#include<iostream>
#include<queue>
using namespace std;

int miro[102][102];
bool visited[102][102] = {0};

struct point{
	int y;
	int x;
	int cnt;
	point(int Y, int X, int C){
		x = X;
		y = Y;
		cnt = C;
	}
};
queue<point> q;

int main(){
	int N,M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++ ){
			scanf("%1d",&miro[i][j]);
		}
	}

	q.push(point(1,1,1));
	visited[1][1] = true;

	while(!q.empty()){
		point now = q.front();
		q.pop();
		if(now.y == N && now.x == M) {cout << now.cnt; break;}

		int dx[4] = {-1,1,0,0};
		int dy[4] = {0,0,1,-1};

		for(int i = 0; i < 4; i++){
			if(now.y+dy[i]<=N &&now.x+dx[i]<=M &&now.x+dx[i]>=1 && now.y+dy[i]>=1){
				if(miro[now.y+dy[i]][now.x+dx[i]] == true && visited[now.y+dy[i]][now.x+dx[i]] ==false) {
					visited[now.y+dy[i]][now.x+dx[i]]= true;
					q.push(point(now.y+dy[i],now.x+dx[i],now.cnt+1));
					
				}
			}
		}
	}
	return 0;
}
