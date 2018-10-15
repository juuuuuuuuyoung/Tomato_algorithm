//r,c
//x,y

#include<iostream>
using namespace std;

int dice[7]={0};
int mem[21][21]={0};

int dy[4]={0,0,-1,1};
int dx[4]={1,-1,0,0};

int N, M, K;
int x, y;


void Go(int k){
	int temp;
	if(k==0){ //오른쪽
		temp = dice[1];
		dice[1]=dice[4];
		dice[4]=dice[6];
		dice[6]=dice[3];
		dice[3]=temp;
	}
	else if(k==1){ //왼쪽
		temp = dice[1];
		dice[1]=dice[3];
		dice[3]=dice[6];
		dice[6]=dice[4];
		dice[4]=temp;
	}
	else if(k==2){ //북
		temp = dice[1];
		dice[1]=dice[5];
		dice[5]=dice[6];
		dice[6]=dice[2];
		dice[2]=temp;
	}
	else{ //남
		temp = dice[1];
		dice[1]=dice[2];
		dice[2]=dice[6];
		dice[6]=dice[5];
		dice[5]=temp;
	}
}


int main(){	
	cin >> N >> M >> y >> x >> K;
	for(int i = 0; i <N; i++ ){
		for(int j = 0; j <M ; j++){
			cin >> mem[i][j];
		}
	}

	int k;
	for(int i = 0; i < K; i++){
		cin >> k;
		k--;
		int nx = x+dx[k];
		int ny = y+dy[k];
		
		if(nx>=0 && nx<M && ny >=0 && ny<N){
			Go(k);
			if(mem[ny][nx]==0){
				mem[ny][nx] = dice[6];
			}
			else{
				dice[6]=mem[ny][nx];
				mem[ny][nx] = 0;
			}
			cout << dice[1]<<endl;
			x = nx;
			y = ny;
		}
	}
	return 0;
}
