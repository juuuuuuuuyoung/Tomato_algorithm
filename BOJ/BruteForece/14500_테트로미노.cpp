
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,M;// (4 ≤ N, M ≤ 500)

int map[501][501]={0};
int maxnum= 0;


void Go1(){
	int sum = 0;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M-3; j++){
			sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i][j+3];	
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}

	for(int i = 0; i < N-3; i++){
		for(int j = 0; j < M; j++){
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
}
void Go2(){
	int sum = 0;
	
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i][j+1] + map[i+1][j] + map[i+1][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}

}
void Go3(){
	int sum = 0;
	//ㄴ
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+2][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㄴ2
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅢ
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅢ2
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㄱ
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㄱ2
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i+2][j] + map[i][j+1] + map[i+1][j+1] + map[i+2][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅣ-
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i+1][j] + map[i][j] + map[i][j+1] + map[i][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅣ-2
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+1][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
}
void Go4(){
	int sum = 0;
	//세로1
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i+1][j] + map[i+1][j+1] + map[i+2][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//세로2
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j+1] + map[i+1][j+1] + map[i+1][j] + map[i+2][j];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//가로
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i+1][j] + map[i+1][j+1] + map[i][j+1] + map[i][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//가로2
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i][j] + map[i][j+1] + map[i+1][j+1] + map[i+1][j+2];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}

}
void Go5(){
	int sum = 0;
	//ㅜ
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅏ
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅗ
	for(int i = 0; i < N-1; i++){
		for(int j = 0; j < M-2; j++){
			sum = map[i+1][j] + map[i+1][j+1] + map[i+1][j+2] + map[i][j+1];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
	//ㅓ
	for(int i = 0; i < N-2; i++){
		for(int j = 0; j < M-1; j++){
			sum = map[i][j+1] + map[i+1][j+1] + map[i+2][j+1] + map[i+1][j];
			if(sum > maxnum) maxnum = sum;
			sum = 0;
		}
	}
}


int main(){
	cin >> N >> M;
	for(int i = 0; i < N ; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}


	Go1();
	Go2();
	Go3();
	Go4();
	Go5();

	cout << maxnum;
	return 0;
}

