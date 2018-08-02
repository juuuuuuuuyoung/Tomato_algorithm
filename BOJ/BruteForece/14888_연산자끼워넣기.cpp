#include<iostream>
#include<vector>
using namespace std;

int T;
int N;
vector<int> result;
int num[13] = {-10000};

int maxN = -10000000000;
int minN = 10000000000 ;


void go(int sum, int cnt,int visited[4]){

	if(cnt == N){
		if(sum >= maxN) maxN = sum;
		if(sum <= minN) minN = sum;
		return ;
	}
	for(int i = 0; i < 4; i++){
		if(visited[i]>0){
			visited[i]--;
			switch(i){
			case 0 : 
				go(sum + num[cnt],cnt+1,visited);
				break;
			case 1:
				go(sum - num[cnt],cnt+1,visited);
				break;
			case 2:
				go(sum * num[cnt],cnt+1,visited);
				break;
			case 3:
				go(sum / num[cnt],cnt+1,visited);
				break;
			default:
				break;
			}
			visited[i]++;
		}
	}

}

void testcase(){
	int ans = 0;
	int calc[4] = {0};
	cin >> N;

	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	for(int i = 0; i < 4; i++){
		cin >> calc[i];
	}

	go(num[0],1,calc);
	ans = maxN- minN;

}

int main(){
	testcase();
	//for(int i = 0; i < T; i++)cout << "#"<< i+1<<" "<<result[i]<<endl;
	cout << maxN << endl << minN<<endl;
	return 0;
}
