#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int one, two, three;
int visited[201][201][201] ={false};

struct state{
	int a;
	int b;
	int c;
	state(int A, int B, int C){
		a = A;
		b = B;
		c = C;
	}
};
vector<int> result;

int main(){
	cin >> one >> two >> three;

	queue<state> q;
	q.push(state(0,0,three));
	visited[0][0][three] = true;

	while(!q.empty()){
		state now = q.front();
		q.pop();
		if(now.a == 0 ){//첫번째가 비어있을 때
			result.push_back(now.c);
		}

		//물 옮기기//한 물통이 비거나, 다른 한 물통이 가득 찰 때까지
		if(now.a != 0){
			if(now.b<two) {
				if(now.a <= two-now.b ) {
					if(!visited[0][now.b+now.a][now.c]){
						q.push(state(0,now.b+now.a,now.c));
						visited[0][now.b+now.a][now.c]= true;
					}
				}
				else  {
					if(!visited[now.a-(two-now.b)][two][now.c]){
						q.push(state(now.a-(two-now.b),two,now.c));
						visited[now.a-(two-now.b)][two][now.c]=true;
					}
				}
			}
			if(now.c<three) {
				if(now.a <= three-now.c) {
					if(!visited[0][now.b][now.c+now.a]){
						q.push(state(0,now.b,now.c+now.a));
						visited[0][now.b][now.c+now.a] = true;
					}
				}
				else  {
					if(!visited[now.a-(three-now.c)][now.b][three]){
						q.push(state(now.a-(three-now.c),now.b,three));
						visited[now.a-(three-now.c)][now.b][three] = true;
					}
				}
			}
		}
		if(now.b != 0){
			if(now.a<one) {
				if(now.b <= one-now.a) {
					if(!visited[now.a+now.b][0][now.c]){
						q.push(state(now.a+now.b,0,now.c));
						visited[now.a+now.b][0][now.c] = true;
					}
				}
				else  {
					if(!visited[one][now.b-(one-now.a)][now.c]){
						q.push(state(one,now.b-(one-now.a),now.c));
						visited[one][now.b-(one-now.a)][now.c] = true;
					}
				}
			}
			if(now.c<three) {
				if(now.b <= three-now.c){
					if(!visited[now.a][0][now.c+now.b]){
						q.push(state(now.a,0,now.c+now.b));
						visited[now.a][0][now.c+now.b] = true;
					}
				}
				else { 
					if(!visited[now.a][now.b-(three-now.c)][three]){
						q.push(state(now.a,now.b-(three-now.c),three));
						visited[now.a][now.b-(three-now.c)][three] = true;
					}

				}
			}
		}
		if(now.c != 0){
			if(now.a<one) {
				if(now.c <= one-now.a) {
					if(!visited[now.a+now.c][now.b][0]){
						q.push(state(now.a+now.c,now.b,0));
						visited[now.a+now.c][now.b][0] = true;
					}
				}
				else { 
					if(!visited[one][now.b][now.c-(one-now.a)]){
						q.push(state(one,now.b,now.c-(one-now.a)));
						visited[one][now.b][now.c-(one-now.a)] = true;

					}
				}
			}
			if(now.b<two) {
				if(now.c <= two-now.b){ 
					if(!visited[now.a][now.b + now.c][0]){
						q.push(state(now.a,now.b + now.c,0));
						visited[now.a][now.b + now.c][0] = true;
					}
				}
				else  {
					if(!visited[now.a][two][now.c-(two-now.b)]){
						q.push(state(now.a,two,now.c-(two-now.b)));
						visited[now.a][two][now.c-(two-now.b)] = true;
					}
				}
			}
		}

	}
	sort(result.begin(),result.end());
	for(int i = 0; i < result.size();i++) cout << result[i]<<" ";
	return 0;
}
