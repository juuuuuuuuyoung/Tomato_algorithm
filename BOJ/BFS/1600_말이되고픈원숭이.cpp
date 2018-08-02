#include<iostream>
#include<queue>
using namespace std;

struct pos{
	int y;
	int x;
	int k;
	int cnt;
	pos(int Y, int X, int K, int C){
		y = Y;
		x = X;
		k = K;
		cnt = C;
	}
};

int K;
int W, H;
int mem[201][201];
bool visited[201][201][31] = {false};
int main(){
	cin >> K;
	cin >> W >> H;
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> mem[i][j];
		}
	}

	queue<pos> q;
	q.push(pos(0,0,0,0));
	visited[0][0][0] = true;

	while(!q.empty()){
		pos now = q.front();
		q.pop();

		if(now.x == W-1 && now.y == H-1){
			cout << now.cnt;
			return 0;
		}


		if(now.k<K){
			int dx[8]={-2,-1,1,2,-2,-1,1,2};
			int dy[8]={-1,-2,-2,-1,1,2,2,1};
			for(int i = 0; i < 8; i++){
				int nexty = now.y + dy[i];
				int nextx = now.x + dx[i];
				if(nexty>=0 && nextx>=0 && nexty<H && nextx<W){
					if(!visited[nexty][nextx][now.k+1] && mem[nexty][nextx] == 0){
						visited[nexty][nextx][now.k+1] = true;
						q.push(pos(nexty, nextx, now.k+1, now.cnt+1));
					}
				}
			}
		}
		int ddx[4]={-1,1,0,0};
		int ddy[4]={0,0,-1,1};

		for(int i = 0; i < 4; i++){
			int nexty = now.y + ddx[i];
			int nextx = now.x + ddy[i];
			if(nexty>=0 && nextx>=0 && nexty<H && nextx<W){
				if(!visited[nexty][nextx][now.k] && mem[nexty][nextx] == 0){
					visited[nexty][nextx][now.k] = true;
					q.push(pos(nexty, nextx, now.k, now.cnt+1));
				}
			}
		}
	}
	cout << -1;
	return 0;
}
