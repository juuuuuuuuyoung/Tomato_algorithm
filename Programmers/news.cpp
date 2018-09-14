#include<iostream>
#include <string>
#include <vector>

using namespace std;

struct p{
	string s;
	bool visited;
	p(string t, bool b){
		s = t;
		visited = b;
	}

};

int solution(string str1, string str2) {
	int answer = 0;

	vector<p> st1, st2;
	if(str1[0]>=65 && str1[0]<=90) str1[0]+=32;
	if(str2[0]>=65 && str2[0]<=90) str2[0]+=32;

	for(int i = 1; i < str1.length(); i++){
		if(str1[i]>=65 && str1[i]<=90) str1[i]+=32;
		if(str1[i]>=97 && str1[i]<=122 && str1[i-1]>=97 && str1[i-1]<=122){
			string temp = "";
			temp = temp + str1[i-1];
			temp = temp + str1[i];
			st1.push_back(p(temp,0));
		}
	}
	for(int i = 1; i < str2.length(); i++){
		if(str2[i]>=65 && str2[i]<=90) str2[i]+=32;
		if(str2[i]>=97 && str2[i]<=122 && str2[i-1]>=97 && str2[i-1]<=122){
			string temp = "";
			temp = temp + str2[i-1];
			temp = temp + str2[i];
			st2.push_back(p(temp,0));
		}
	}

	
	int cnt = 0;

	for(int i=0; i < st1.size(); i++){
		for(int j = 0; j < st2.size(); j++){
			if(st1[i].s.compare(st2[j].s)==0) {
				if(st2[j].visited==0){//중복 처리....
					cnt++;
					st2[j].visited = true;
					break;
				}
			}
		}
	}

	if(st1.size()+st2.size()-cnt == 0 ) return 65536;
	else answer = (65536 * cnt) /(st1.size()+st2.size()-cnt);

	return answer;
}

int main(){
	cout << solution("aaaaaa","aa");
	return 0;
}
