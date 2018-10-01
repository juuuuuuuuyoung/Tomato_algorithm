#include <string>
#include <vector>
#include<algorithm>
using namespace std;

struct p{
	int id;
	string name;

	p(int i, string n){
		id = i;
		name = n;
	}
};
bool cmp(p a, p b){
	return a.id>b.id;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	if(cacheSize== 0) return cities.size() * 5;

	vector<p> citylist;


	//모두 대문자로 바꾸기
	for(int r = 0; r < cities.size(); r++){
		for(int c = 0; c < cities[r].size(); c++){
			if(cities[r][c]>=65 && cities[r][c]<=90) {
				cities[r][c] +=32;
			}
		}
	}



	int cnt = 0;
	for(int i = 0; i < cities.size(); i++){	

		string nowcity = cities[i];
		bool find = false;

		//있는지 없는지 확인 //아오 대소문자까지 확인
		int j=0;
		while( j < citylist.size()){
			if(nowcity.compare(citylist[j].name)==0){
				find = true;
				break;
			}
			j++;
		}
		//있으면
		if(find){ 
				citylist[j].id = i;
				answer += 1;
		}
		//없으면
		else {
			if(cnt < cacheSize){
				citylist.push_back(p(i,nowcity));	
				cnt++;
			}
			else{
				//제일 오랫동안 안불린거 없애고
				citylist.pop_back();
				///지금꺼 넣는다.
				citylist.push_back(p(i,nowcity));
				
			}
			answer += 5;
		}
		sort(citylist.begin(), citylist.end(),cmp);
	}

    return answer;
}
