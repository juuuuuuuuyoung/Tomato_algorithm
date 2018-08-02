#include<iostream>
using namespace std;

int N;
int K;
int mat[101]; //동전 가지를 저장한 배열
int mem[10001]; //합의 경우의 수를 더한결과 저장 배열

int main(){
	cin >>N >>K;
	for(int i = 0; i < N; i++)
		cin>>mat[i];

	mem[0]=1;

	for(int i = 0;i < N; i++){
		for(int j=mat[i]; j <=K; j++)
			mem[j] += mem[j-mat[i]];
	}
	cout<<mem[K] <<endl;
	return 0;
}
