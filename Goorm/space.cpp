#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> result;
int mem[10][10]={0};
bool visited[10][10]={false};

int cnt;

void Go(int y, int x){
	visited[y][x] = true;
	cnt ++;
	int dx[4]={-1,1,0,0};
	int dy[4]={0,0,-1,1};
	
	for(int i = 0; i <4 ;i++ ){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(ny>=0 && ny <N && nx >=0 && nx<N){
			if(mem[ny][nx] && !visited[ny][nx]){
					Go(ny, nx);	
			}
		}		
	}
	return ;
}

int main() {

	cin >> N;
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mem[i][j];	
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(!visited[i][j] && mem[i][j]){
				cnt = 0;
				Go(i,j);
				result.push_back(cnt);
			}
		}
	}
	
	sort(result.begin(), result.end());
	if(result.size()==0) cout << 0;
	else {
		cout << result.size()<<endl;
		for(int i = 0; i < result.size(); i++) cout << result[i]<< " ";	
	}
	return 0;
}
