#include <iostream>
#include <queue>
using namespace std;

int mem[101][101];
bool visited[101][101]={false};


int main(){
	int n;

	//입력
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> mem[i][j];
		}
	}

//수행
	queue<int> q;
	for(int start = 0; start < n; start++){ //위에 부터 한줄씩!
		q.push(start);
		while(!q.empty()){
			int s= q.front();
			q.pop();
			for(int i = 0; i < n; i++){
				if(!visited[start][i] && mem[s][i]){
					mem[start][i] = true;
					visited[start][i] = true;	
					q.push(i);
				}
			}
		}
	}

	//출력
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << mem[i][j]<<" ";
		cout << endl;
	}
	return 0;

}
