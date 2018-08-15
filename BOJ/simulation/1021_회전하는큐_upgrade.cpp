#include <iostream>
#include<queue>
using namespace std;

queue<int> q;

int main(){
	int N, M;
	int num;
	int top;
	int turn=0;
	
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		q.push(i);
	}
	
	while(M--){
		int nowturncheck=0;
		cin >> num;
		while(num!=q.front()){
			top=q.front();
			q.pop();
			q.push(top);
			nowturncheck++;
		}
		turn+=min(nowturncheck,N-nowturncheck);
		q.pop();
		N--;
	}
	cout << turn;
}
