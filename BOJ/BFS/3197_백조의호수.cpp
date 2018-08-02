#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

int R,C;
char lake[1501][1501];

struct pos{
	int y;
	int x;
	int cnt;
	pos(int Y, int X, int c){
		 y = Y;
		 x = X;
		 cnt = c;
	}
};

vector<pos> swan;

bool swanvisit[1501][1501]={false};
bool visited2[1501][1501]={false};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
// 처음만나는것의 얼음을 visited는 하는데 큐에 넣지는 않는다.
queue<pos> q;

bool meet(){
	pos	swan1 = swan[0];
	while(!q.empty()){
		pos now = q.front();
		q.pop();
		if(now.x == swan1.x && now.y == swan1.y) return true;
		for(int i = 0;i < 4; i++){
			int nexty = now.y+dy[i];
			int nextx = now.x+dx[i];
			if(nexty>=0 &&nexty<R && nextx>=0 &&nextx<C){
				if(lake[nexty][nextx]!='X'&&!swanvisit[nexty][nextx]){
					q.push(pos(nexty,nextx,0));
					swanvisit[nexty][nextx] = true;
				}
				//
				else if(lake[now.y][now.x]!='X'&&lake[nexty][nextx]=='X'&&!swanvisit[nexty][nextx]){
					swanvisit[nexty][nextx] = true;
				}
			}
		}
	}
	return false;
}
int main(){
	cin >> R>>C;
	
	queue<pos> meltqueue;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++){
			cin >> lake[i][j];
			if(lake[i][j]=='L')swan.push_back(pos(i,j,0));
			if(lake[i][j] !='X'){
				meltqueue.push(pos(i,j,1));
				visited2[i][j] = true;
			}
		}

	pos swan2 = swan[1];
	q.push(swan2);
	swanvisit[swan2.y][swan2.x]=true;

	while(!meltqueue.empty()){
		pos now = meltqueue.front();
		meltqueue.pop();
		if(meet()==true){
			cout << now.cnt;
			break;
		}
		for(int i = 0; i < 4; i++){
			pos next= pos(now.y+dy[i],now.x+dx[i],now.cnt+1);
			if(next.y>=0 && next.y<R && next.x>=0 && next.x<C){
				if(lake[next.y][next.x]=='X'&& !visited2[next.y][next.x]){
					meltqueue.push(next);
					if(swanvisit[next.y][next.x] == true){
						q.push(pos(next.y,next.x,0));
					}
					lake[next.y][next.x] = '.';
					visited2[next.y][next.x]=true;
				}
			}
		}
	}
	return 0;
}
