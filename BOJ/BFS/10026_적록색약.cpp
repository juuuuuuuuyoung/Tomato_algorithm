#include<iostream>
using namespace std;

struct pos{
	int y;
	int x;
	char c;
	pos(int Y, int X, char C){
		y = Y;
		x = X;
		c = C;
	}
};

int N;
char mem[101][101][2];
int visited[101][101][2] = {false};

void Go(int y, int x, char c,int t){

	int dx[4]={0,0,-1,1};
	int dy[4]={-1,1,0,0};
	
	for(int i = 0; i < 4; i++){
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if(nexty >= 0 && nextx>= 0 && nextx<N && nexty < N){
			if(!visited[nexty][nextx][t]&&mem[nexty][nextx][t] == c){
				visited[nexty][nextx][t] = true;
				Go(nexty, nextx, c,t);
			}
		}
	}

}


int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mem[i][j][0];
			mem[i][j][1] = mem[i][j][0];
			if(mem[i][j][0] == 'G') mem[i][j][1] = 'R';
		}
	}

	int good = 0;
	int bad = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j][0]){
				Go(i,j,mem[i][j][0],0);
				good++;
			}
			if(!visited[i][j][1]){
				Go(i,j,mem[i][j][1],1);
				bad++;
			}
		}
	}


	cout << good<<" "<< bad;

	return 0;
}
