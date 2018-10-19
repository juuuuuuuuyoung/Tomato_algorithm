#include<iostream>
#include<set>
using namespace std;

int mem[5][5];
set<int> result;

void Go(int y, int x, int now ,int cnt){
	if(cnt == 5){
		result.insert(now);
		return;
	}
	int dx[4]={0,0,-1,1};
	int dy[4]={-1,1,0,0};
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && ny>= 0 && nx<5 && ny<5){
			Go(ny,nx,now*10+mem[ny][nx],cnt+1);
		}
	}
	return ;

}

int main(){
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> mem[i][j];

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			Go(i,j,mem[i][j],0);

	cout << result.size();
	return 0;
}
