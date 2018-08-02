#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int T;
int L;
int visited[301][301]={false};
vector<int> result;
struct pos{
	int x;
	int y;
	int cnt;
	pos(int X, int Y,int c){
		x = X;
		y = Y;
		cnt = c;
	}
};

void chess(){
	cin >> L;
	int startx, starty, lastx, lasty;
	cin >> startx >> starty;
	cin >> lastx >> lasty;

	queue<pos> q;
	q.push(pos(startx,starty,0));
	visited[startx][starty] = true;
	
	while(!q.empty()){
		pos now = q.front();
		q.pop();
		if(now.x == lastx && now.y == lasty) {result.push_back( now.cnt); break;}

		int dx[8]={-1,1,2,2,1,-1,-2,-2};
		int dy[8]={2,2,1,-1,-2,-2,-1,1};
		for(int i = 0; i < 8; i++){
			int nextx = now.x+dx[i];
			int nexty = now.y+dy[i];
			if(nextx>=0 && nextx<L && nexty >=0 && nexty<L){
				if(!visited[nextx][nexty]){
					q.push(pos(nextx,nexty,now.cnt+1));
					visited[nextx][nexty] = true;
				}
			}
		}

	}
	for(int i = 0; i <L; i++)
		for(int j = 0; j < L; j++)
			visited[i][j] = false;
}

int main(){
	cin >> T;
	for(int i = 0; i < T; i++)chess();
	for(int i = 0; i < result.size(); i++) cout << result[i]<<endl;
	return 0;
}
