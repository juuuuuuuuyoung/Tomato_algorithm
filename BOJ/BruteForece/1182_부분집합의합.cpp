#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, S;
int cnt = 0;
vector<int> mem;

void Go(int i,int sum, int num){	
	if(i== N-1){
		if(sum + mem[i] == S) cnt++;
		if(sum == S && num != 0)cnt++;
		return ;
	}
		Go(i+1,sum,num);//선택안하고 넘김
		Go(i+1,sum+mem[i],num+1);//선택하고 넘김
}

int main(){
	cin >> N >> S;

	for(int i = 0; i<N; i++){
		int n;
		cin >> n;
		mem.push_back(n);
	}
	sort(mem.begin(),mem.end());

	Go(0,0,0);

	cout << cnt;
	return 0;
}
