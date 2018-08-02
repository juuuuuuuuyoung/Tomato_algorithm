#include<iostream>
#include<queue>
using namespace std;

bool visited[100001]={false};
int N, K;

struct state{
	int pos;
	int time;
	state(int p, int t){
		pos = p;
		time = t;
	}
};
int main(){
	cin >> N >> K;

	queue<state> q;
	q.push(state(N,0));
	visited[N] = true;
	while(!q.empty()){
		state now = q.front();
		q.pop();
		if(now.pos == K){
			cout << now.time;
			break;
		}
		if(now.pos+1>=0 && now.pos+1<=100000){
			if(visited[now.pos+1]==false){
				q.push(state(now.pos+1,now.time+1));
				visited[now.pos+1]=true;
			}
		}
		if(now.pos-1>=0 && now.pos-1<=100000){
			if(visited[now.pos-1]==false){
				q.push(state(now.pos-1,now.time+1));
				visited[now.pos-1]=true;
			}
		}
		if(now.pos*2>=0 && now.pos*2<=100000){
			if(visited[now.pos*2]==false){
				q.push(state(now.pos*2,now.time+1));
				visited[now.pos*2]=true;
			}
		}
	}

	return 0;
}
