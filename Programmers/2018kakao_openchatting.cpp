#include<iostream>
#include<map>
#include <string>
#include <vector>

using namespace std;
//닉네임은 알파벳 대문자, 소문자를 구별

struct id{
	string uid;
	string name;

	id(string i, string n){
		uid = i;
		name = n;
	}
};
vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector<id> rec; 
	map<string, string> idlist;
	int n=0; //record index number

	//record 분석
	while(n<record.size()){
		string now = record[n];
		string nowid="";
		string nowname="";
		char o; 

		int k=0;
		if(now[0]=='E'){
			o = 'E';
			k = 6;
		}
		else if(now[0]== 'L'){
			k=6;
			o='L';
		}
		else if(now[0]=='C'){
			o = 'C';
			k=7;
		}
		//명령어 분석
		bool idfinish = false;
		while(k<now.size()){
			if(now[k]==' '&& idfinish == false) {
				idfinish = true;
				if(o=='L') break;
			}
			else if(now[k]!=' '&& idfinish == false)nowid = nowid+ now[k];
			else if(idfinish){
				nowname =nowname + now[k];
			}
			k++;
		}
		string txt = "";
		txt += o;
		rec.push_back(id(nowid,txt));

		if(o=='E' || o=='C'){
			idlist[nowid] = nowname;
		}
		n++;
	}//while문 끝

	n = 0;
	
	while(n<rec.size()){
		string nowname="";
		//아이디로 이름찾기
		nowname = idlist.find(rec[n].uid)->second;
		if(rec[n].name.compare("E")==0){		
			answer.push_back(nowname+"님이 들어왔습니다.");
		}
		else if(rec[n].name.compare("L")==0){
			answer.push_back(nowname +"님이 나갔습니다.");
		}
		n++;
	}
	return answer;
}


int main(){
	vector<string> n;
	n.push_back("Enter uid1234 Muzi");
	n.push_back("Enter uid4567 Prodo");
	n.push_back("Leave uid1234");
	n.push_back("Enter uid1234 Prodo");
	n.push_back("Change uid4567 Ryan");

	vector<string> u = solution(n);
	for(int i = 0; i < u.size(); i++) cout << u[i]<<endl;
	
	return 0;
}
