#include<iostream>
using namespace std;

int N;
int mat[10001];

int mem[10001][3]; //몇번째잔까지 했는지, 몇잔째 마셨는지

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> mat[i];

	mem[0][0] = 0;
	mem[0][1] = mat[0];

	for(int i = 1; i < N; i++){
		mem[i][2] = mem[i-1][1] + mat[i];
		mem[i][1] = mem[i-1][0] + mat[i];
		mem[i][0] = max(max(mem[i-1][1],mem[i-1][2]),mem[i-1][0]);
	}
	cout<< max(max(mem[N-1][0],mem[N-1][1]),mem[N-1][2])<<endl;

	return 0;
}
