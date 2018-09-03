#include <iostream>
#include<vector>
#include<queue>
using namespace std;


vector<vector<int> > solution(int n, vector<vector<int> > signs){
	
	int visited[101][101]= {false};
	
	queue<int> q;

	for(int start = 0; start < n; start++){ //위에 부터 한줄씩!
		q.push(start);
		while(!q.empty()){
			int s= q.front();
			q.pop();
			for(int i = 0; i < n; i++){
				if(!visited[start][i] && signs[s][i]){
					signs[start][i] = true;
					visited[start][i] = true;	
					q.push(i);
				}
			}

		}
	}
	
	return signs;
}
