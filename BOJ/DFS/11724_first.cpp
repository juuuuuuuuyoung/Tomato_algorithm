#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> result;
int parents[1001]={0};

int main(){
	cin >> N >> M;

	for(int i = 0; i <= N; i++){
		vector<int> item;
		item.push_back(1);
		result.push_back(item);
	}

	for(int i = 0; i < M; i++){
		int s, f;
		int pidx,changeidx;
		cin >> s >> f;

		//한번도 안나온 숫자
		if(parents[s]==0) {
			parents[s] = s;
			result[s].push_back(s);
		}
		if(parents[f]==0) {
			parents[f] = f;
			result[f].push_back(f);

		}
		//한묶음이 아닐때
		if(parents[s]!= parents[f]){
			//부모가 빠른걸로 선택하기
			if(parents[s]<parents[f]) {
				pidx = parents[s];
				changeidx = parents[f];
			}
			else {
				pidx = parents[f];
				changeidx = parents[s];
			}

			//합치기
			for(int i= 1; i <=result[changeidx][0]; i++ ){
				parents[result[changeidx][i]] = pidx;
				result[pidx].push_back(result[changeidx][i]);
			}
			//원래꺼 지우기
			for(int i= 1; i <=result[changeidx][0]; i++ ){
				result[changeidx].pop_back();
			}
			result[pidx][0]+=result[changeidx][0];
			result[changeidx][0]=0;
		}
	}
	//총 몇묶음인지
	int cnt = 0;
	for(int i = 1; i <= N; i++){
		if(result[i][0]!=0)cnt++;
	}
	cout << cnt;
	return 0;
}
