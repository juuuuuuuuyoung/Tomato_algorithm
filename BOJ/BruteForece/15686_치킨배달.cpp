//4:20 // 4:44
#include<iostream>
#include<vector>
using namespace std;

int N, M;
int mem[51][51]={0};
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

vector<pair<int, int>> nowchicken;


int minnum=987654321;

int calcmindistance(vector<pair<int, int>> &nowchicken){
	int ans=0;

	for(int i = 0; i < home.size(); i++){
		int hd = 987654321; //그 집에서 치킨집까지 최소 거리
		for(int j = 0; j < nowchicken.size(); j++){
			int nhd = abs(home[i].first-nowchicken[j].first) + abs(home[i].second-nowchicken[j].second); //그 집에서 현재 치킨집까지 거리
			hd = min(hd,nhd);
		}
		ans += hd;
	}
	return ans;
}

void Go(int idx, int cnt){
	if(cnt == M){ //M개 고르면
		//최소 치킨거리 구하기
		int nowmin = calcmindistance(nowchicken);
		if(minnum>=nowmin) minnum = nowmin;
		return;
	}
	
	for(int i = idx+1; i < chicken.size(); i++){
		nowchicken.push_back(make_pair(chicken[i].first,chicken[i].second));
		Go(i,cnt+1);
		nowchicken.pop_back();
		Go(i,cnt);
	}
	 return;
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < N; j++){
			cin >> mem[i][j];
			if(mem[i][j]==1)home.push_back(make_pair(i,j));
			else if(mem[i][j]==2)chicken.push_back(make_pair(i,j));
		}
	}

	nowchicken.push_back(make_pair(chicken[0].first,chicken[0].second));
	Go(0,1);
	nowchicken.pop_back();
	Go(0,0);

	cout << minnum;
	return 0;
}
