#include <iostream>
using namespace std;

int mem[101][101];
bool visited[101][101]={0};

int N;

void go(int first,int start,int end){
    
	mem[first][end] = 1;	
	visited[first][end] = true;
   
	for(int i=0; i<N; i++)  {
        if(!visited[first][i] && mem[end][i])
            go(first,end,i);
    }
}


int main(){
	//입력
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> mem[i][j];
    //함수
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
           if(!visited[i][i] && mem[i][j])
               go(i,i,j);
        }
    }
   //출력
	for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cout << mem[i][j]<<" ";
        cout << endl;
    }
    return 0;

}
