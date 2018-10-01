#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct fail{
	int level;
	double f;
	fail(int l, int fa){
		level = l;
		f = fa;
	}
};

bool cmp(fail a, fail b){
	if(a.f==b.f)return a.level<b.level;
	return a.f > b.f;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
	vector<fail> faillist;
	faillist.push_back(fail(0.0,-10));
	for(int i = 1; i <= N+1; i++){
		faillist.push_back(fail(i,0.0));
	}

	for(int i = 0; i < stages.size(); i++){
		faillist[stages[i]].f ++;
	}
	//계산
	faillist.pop_back();

	int already = 0;
	for(int i = 1; i <=N; i++ ){
		double now  = faillist[i].f;
		if(stages.size()-already == 0){
			faillist[i].f = 0.0;
		}
		else if(now == 0) faillist[i].f = 0.0;
		else{
			faillist[i].f = now/(stages.size()-already);
			already +=now;
		}
	}

	sort(faillist.begin(), faillist.end(),cmp);
	for(int i = 0; i < faillist.size()-1; i++){
		answer.push_back (faillist[i].level);
	}
    return answer;
}
