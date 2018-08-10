/*
현재 위치를 청소한다.
현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
  왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
  왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
  네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
  네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다
*/

#include<iostream>
using namespace std;

int N, M;//3<=N,M>=50
int dy[4]={-1,0,1,0}; //북동서남
int dx[4]={0,1,0,-1};
int mem[60][60];
int cnt = 0; //청소하는칸 개수
int r, c, d;
//빈칸 0 
//벽 1
//청소 2


void Go(int y, int x, int d,bool check){
	if(y<0 || y>=N || x<0 || x>=M) return; 
	if(check == true){ //청소
		mem[y][x] = 2;
		cnt ++;
	}

	for(int i = 0; i < 4; i++){
		d = (d+3)%4;//왼쪽으로 한칸씩
		int nexty = y+dy[d];
		int nextx = x+dx[d];
		if(nexty>=0 && nexty<N && nextx>=0 && nextx<M){
			if(mem[nexty][nextx] == 0 ){	
				Go(nexty, nextx, d, true);
				return;
			}
		}
	}

	//후진시킬때
	int backy = y + dy[(d+2)%4]; 
	int backx = x + dx[(d+2)%4];

	if(backy>=0 && backy<N && backx>=0 && backx<M){
		if(mem[backy][backx]!=1){
			Go(backy, backx, d, false);
			return;
		}
	}
	return;
}


int main(){
	cin>> N >> M;
	cin >> r >> c >> d;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin>>mem[i][j];
		}
	}

	Go(r,c,d,true);
	cout << cnt;
	return 0;
}
