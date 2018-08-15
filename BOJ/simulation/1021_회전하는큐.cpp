//1:20
//양방향 원형 큐 
//연산은 첫번째꺼 뽑기, 오른쪽으로 한칸씩, 왼쪽으로 한칸씩
//인덱스는 1부터..
#include<iostream>
#include<vector>
using namespace std;

vector<int> que;

int N;//50보다 작음
int M;//몇개뽑을지
int minTurn = 0;//2번 3번;
int nowMax;//현재 큐에 있어야하는 갯수

void changeleft(int n){
	for(int i = 0; i < N; i++){
		if(que[i]==-100) continue;
		else {
			que[i]=(que[i]+n)%nowMax;
		}
	}
}
void changeright(int n){
	for(int i = 0; i < N; i++){
		if(que[i]==-100) continue;
		else if(que[i]-n<0)que[i]=que[i]-n+nowMax;//
		else que[i]=que[i]-n;
	}
}
void pickup(int num){
	if(que[num]==0) {
		que[num]= -100;
		nowMax--;
		changeright(1);
		return;
	}
	int turn = que[num]; //minTurn에 더할 횟수
	if(turn<=nowMax-turn) {
		changeright(turn);
		minTurn = minTurn+turn;
	}
	else {
		changeleft(nowMax-turn);
		minTurn = minTurn+(nowMax-turn);
	}
	pickup(num);
	return;
}

int main(){
	cin >> N>>M;
	for(int i = 0; i < N; i++){
		que.push_back(i);
	}
	nowMax = N;

	for(int i = 0; i < M; i++) {
		int nowpick;
		cin >> nowpick;
		pickup(nowpick-1); //인덱스가 1부터라서..
	}
	cout << minTurn;
	return 0;
}
