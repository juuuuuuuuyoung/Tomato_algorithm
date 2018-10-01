#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
	int idx;
	long long time;
	node(int i, long long t){
		idx = i;
		time = t;
	}
};

bool cmp1(node a, node b){
	return a.time<b.time;
}

bool cmp2(node a, node b){
	if(a.time != 0 && b.time != 0) return a.idx < b.idx;
	else if(a.time == 0 && b.time != 0)return b.time < a.time;
}

int solution(vector<int> food_times, long long k) {
	int finishfood = 0;

	vector<node> timetable;

	for(int i = 0; i < food_times.size(); i++){
		timetable.push_back(node(i,food_times[i]));
	}

	sort(timetable.begin(), timetable.end(),cmp1);
	

	long long deletedtime= 0LL;
	for(int i= 0; i < timetable.size();i++){
		long long multime = (timetable[i].time-deletedtime) * (timetable.size()-i);

		if(multime<=k){
			deletedtime = timetable[i].time;
			timetable[i].time = 0LL;
			k -= multime;
			finishfood++;
		}
		else break;
	}

	if(finishfood == timetable.size()) return -1;

	sort(timetable.begin(), timetable.end(), cmp2);
	k= k%(timetable.size()-finishfood);
	return timetable[k].idx + 1;
}


int main(){
	vector<int> n;
	n.push_back(3);
	n.push_back(1);
	n.push_back(2);
	cout << solution(n,5);
}
