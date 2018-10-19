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
		int hd = 987654321;
		for(int j = 0; j < nowchicken.size(); j++){
			int nhd = abs(home[i].first-nowchicken[j].first) + abs(home[i].second-nowchicken[j].second);
			hd = min(hd,nhd);
		}
		ans += hd;
	}
	return ans;
}

void Go(int idx, int cnt){
	if(cnt == M){ //M개 고르면 ,최소 치킨거리 구하기
		minnum = min(minnum,calcmindistance(nowchicken));
		for(auto temp : nowchicken){
			cout << "[" << temp.first<<","<<temp.second<<"] ";
		}
		cout << endl;
		return;
	}
	//1)
	
	if(idx+1<chicken.size()){
		nowchicken.push_back(make_pair(chicken[idx+1].first,chicken[idx+1].second));
		Go(idx+1,cnt+1);
		nowchicken.pop_back();
		Go(idx+1,cnt);
	}
	
	//2) 이렇게 풀면 반복되는 것이 많아서 시간이 오래걸린다.
	/*
	for(int i = idx+1; i < chicken.size(); i++){
		nowchicken.push_back(make_pair(chicken[i].first,chicken[i].second));
		Go(i,cnt+1);
		nowchicken.pop_back();
		Go(i,cnt);
	}
	*/
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
