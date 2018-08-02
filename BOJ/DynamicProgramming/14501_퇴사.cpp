#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int mem[1001]={0};
struct consulting{
	int start;
	int end;
	int pay;
	consulting(int s, int e, int p){
		start = s;
		end = e;
		pay = p;
	}
};
vector<consulting> meeting;
bool cmp(consulting a, consulting b){
	if(a.end==b.end)return a.start>b.start;
	return a.end<b.end;

}
int main(){
	int max = 0;
	cin >> N;
	meeting.push_back(consulting(-1,-1,-1));
	for(int i = 1; i <=N; i++){
		int t, p;
		cin >> t >> p;
		meeting.push_back( consulting(i,i+t,p));
		if(i+t>max)max = i+t;
	}
	sort(meeting.begin()+1,meeting.end(),cmp);
	for(int i = 1; i <= N; i++){
		if(meeting[i].end>N+1) continue;
		else if(mem[meeting[i].start] + meeting[i].pay > mem[meeting[i].end]){
			for(int j = meeting[i].end; j<=max;j++){
				mem[j] = meeting[i].pay + mem[meeting[i].start];
			}
		}
	}
	cout << mem[max];
	return 0;
}
