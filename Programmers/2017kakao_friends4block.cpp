#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool visited[31][31]={false};

	int i = 0;
	int	j = 0;
	bool lastcheck = true;
	while(1){		
		if(board[i][j]!='0' &&board[i][j]==board[i][j+1] && board[i][j]== board[i+1][j] && board[i][j]== board[i+1][j+1]){
			lastcheck = false;
			if(!visited[i][j]){
				answer++;
				visited[i][j] = true;
			}
			if(!visited[i][j+1]){
				answer++;
				visited[i][j+1] = true;
			}
			if(!visited[i+1][j]){
				answer++;
				visited[i+1][j] = true;
			}
			if(!visited[i+1][j+1]){
				answer++;
				visited[i+1][j+1] = true;
			}
		}
		if(j==n-2){
			if(i==m-2) {
				if(lastcheck) break;
				else {
					i=0;
					j=0;
					lastcheck = true;

					for(int r= 0; r<m;r++){
						for(int c = 0; c<n; c++){
							if(visited[r][c]==1) board[r][c]='0';
							visited[r][c] = false;
						}
					}

					for(int c= 0; c<=n-1;c++){
						for(int r = 0; r<=m-1; r++){
							if(board[r][c]=='0'){
								for(int k = r; k>0; k--){
									board[k][c] = board[k-1][c];
								}
								board[0][c] = '0';
							}
						}
					}
					for(int r= 0; r<m;r++){
						for(int c = 0; c<n; c++){
							visited[r][c] = false;
							cout << board[r][c];
						}
						cout << endl;
					}
					cout << endl;

				}
			}
			else{
				i++;
				j=0;
			}
		}
		else j++;
	}
	return answer;
}

int main(){
	vector<string> map;
	map.push_back("CCBDEE");
	map.push_back("AAADEE");
	map.push_back("AAABFE");
	map.push_back("CCBBFE");
	solution(4,6,map);
	return 0;
}
