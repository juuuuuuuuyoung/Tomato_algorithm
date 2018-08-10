#include<iostream>
using namespace std;


int visited[5] = {0};
int mem[5][9]={-1};

int ans = 0;
int K;
void change(int target, int way){	
	if(visited[target] == 1) return;
	visited[target]=1;
	if(target-1>=1 && mem[target][7] != mem[target-1][3]) change(target-1,way*(-1)); //왼쪽
	if(target+1<=4 && mem[target][3] != mem[target+1][7]) change(target+1,way*(-1)); //오른쪽
	
	if(way == 1){//시계
		int first = mem[target][8];
		for(int i = 8; i >=2; i--){
			mem[target][i] =mem[target][i-1]; 
		}
		mem[target][1] = first;
	}
	else{ //반시계
		int last = mem[target][1];
		for(int i = 1; i <=7; i++){
			mem[target][i] =mem[target][i+1]; 
		}
		mem[target][8] = last;
	}
}


int main(){
	//init()
	for(int i = 1; i <=4; i++){
		for(int j = 1; j <= 8; j++){
			scanf("%1d",&mem[i][j]);
		}
	}
	
	cin >> K;

	//function()
	for(int i = 0; i < K; i++){
		int target;
		int way;
		cin >> target >> way;
		change(target,way);
		
		for(int i = 0; i <5; i++){ visited[i] = 0;}
	}

	
	//calc()
	
	if(mem[1][1] == 1) ans = ans + 1;
	if(mem[2][1] == 1) ans = ans + 2;
	if(mem[3][1] == 1) ans = ans + 4;
	if(mem[4][1] == 1) ans = ans + 8;

	cout << ans;
	return 0;
}
