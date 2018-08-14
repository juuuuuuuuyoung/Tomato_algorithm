/*
1 : 한쪽
2 : 180도 두방향
3 : 90도 두방향
4 : 세방향
5 : 네방향
끝까지 쭉 검사 단 벽이 나오면 그만

0 : 빈칸
6 : 벽
# : 감시할 수 있는영역

CCTV의 최대 개수는 8개를 넘지 않는다.
*/
#include<iostream>
#include<vector>
using namespace std;

struct pos{     
	int y;
	int x;
	int type;
	pos(int Y, int X, int T){
		y = Y;
		x = X;
		type = T;
	}
};//cctv위치랑 type(방향)정보가 있는 구조체
int N, M;//세로 가로 //1<=N,M=>8
vector<pos> cctv; //cctv정보 담은 vector
int minispace =65; //사각지대 최솟값
int map[9][9]={0}; //사무실 정보 //변하지 않음
int visited[9][9]; //방문한곳 = cctv촬영되는 곳

//위,오른쪽,아래,왼쪽 순으로 체크
void function(int d, int y, int x, int check){
	switch(d){
	case 0: //위
		for(int i = y; i <N; i++ ){
			if(map[i][x]==6) break;
			if(check == 0) visited[i][x]++;
			else visited[i][x]--;		
			
		}
		break;
	case 1://오른쪽
		for(int i = x; i <M; i++ ){
			if(map[y][i]==6) break;
			if(check == 0) visited[y][i]++;
			else visited[y][i]--;	
		}
		break;
	case 2: //아래
		for(int i = y; i >=0; i-- ){
			if(map[i][x]==6) break;
			if(check == 0) visited[i][x]++;
			else visited[i][x]--;	
		}
		break;
	case 3: //왼쪽
		for(int i = x; i >=0; i-- ){
			if(map[y][i]==6) break;
			if(check == 0) visited[y][i]++;
			else visited[y][i]--;	
		}
		break;
	}

}

void Go(int index){
	
	if(index==cctv.size()){//cctv 한turn 다 검사해봤을 때
		int nowmin = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(map[i][j]==0 && visited[i][j]==0)nowmin++;
			}
		}

		if(minispace>nowmin)minispace = nowmin;
		return ;
	}

	pos now = cctv[index];
	int y = now.y;
	int x = now.x;
	int type = now.type;


	if(type == 5){
		for(int i = 0; i < 4; i++)function(i,y,x,0);
		Go(index+1);	
		for(int i = 0; i < 4; i++)function(i,y,x,1);//다돌고나면 visited에 흔적지워주기
	}
	else if(type == 4){
		for(int i = 0; i < 4; i++){
			function(i,y,x,0);
			function((i+1)%4,y,x,0);
			function((i+2)%4,y,x,0);
			Go(index+1);
			function(i,y,x,1);
			function((i+1)%4,y,x,1);
			function((i+2)%4,y,x,1);
		}
	}
	else if(type == 3){
		for(int i = 0; i < 4; i++){
			function(i,y,x,0);
			function((i+1)%4,y,x,0);
			Go(index+1);
			function(i,y,x,1);
			function((i+1)%4,y,x,1);
		}
	}
	else if(type == 2){
		for(int i = 0; i < 2; i++){
			function(i,y,x,0);
			function((i+2)%4,y,x,0);
			Go(index+1);
			function(i,y,x,1);
			function((i+2)%4,y,x,1);
		}
	}
	else if(type == 1){
		for(int i = 0; i < 4; i++){
			function(i,y,x,0);
			Go(index+1);
			function(i,y,x,1);
		}
	}
}

int main(){
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j]; 
			if (map[i][j]== 0) minispace++;
			else if(map[i][j]>=1 && map[i][j]<=5)cctv.push_back(pos(i,j,map[i][j]));
		}
	}

	//갯수 새기
	Go(0);
	cout << minispace;
	return 0;
}
