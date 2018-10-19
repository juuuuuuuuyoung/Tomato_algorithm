#include<iostream>
#include<vector>
using namespace std;

int N;
int hp[21][21]={0};
vector<int> team1;
vector<int> team2;
int minnum = 987654321;
void Go(int idx, int cnt){
	if(cnt==N){//계산	
		int t1point = 0;
		int t2point = 0;
		for(int i = 0; i < team1.size() ; i++){
			for(int j = 0; j < team1.size(); j++){
				if(i==j)continue;
				t1point += hp[team1[i]][team1[j]];
			}
		}
		for(int i = 0; i < team2.size() ; i++){
			for(int j = 0; j < team2.size(); j++){
				if(i==j)continue;
				t2point += hp[team2[i]][team2[j]];
			}
		}
		minnum = min(minnum,abs(t1point-t2point));
		return;
	}
	if(idx+1 < N){
		team1.push_back(idx+1);
		Go(idx+1,cnt+1);
		team1.pop_back();
		team2.push_back(idx+1);
		Go(idx+1,cnt+1);
		team2.pop_back();
	}
	return ;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin>> hp[i][j];
		}
	}
	team1.push_back(0);
	Go(0,1);
	team1.pop_back();
	team2.push_back(0);
	Go(0,0);
	team2.pop_back();
	cout << minnum;
	return 0;
}
