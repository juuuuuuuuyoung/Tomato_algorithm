#include <string>
#include<vector>
using namespace std;

int solution(string dartResult) {
  int answer = 0;
	vector<int> numlist; //라운드별 점수판
	numlist.resize(3);
  
	bool beforenum = false;//10인지 아닌지 check
	int i=0, id = -1; //id는 numlist의 index
	
	while(i<dartResult.size()){
		
		//숫자일때
		if(dartResult[i]>=48 && dartResult[i]<=57){
			id +=1;
			if(beforenum){
				id-=1;
				numlist[id] = 10;
				beforenum = false;
			}
			else{
				numlist[id] = dartResult[i]-48;
				beforenum = true;
			}
		}
		//숫자아닐때
		else{
			beforenum = false;
			if(dartResult[i]=='D'){
				numlist[id]=numlist[id]*numlist[id];
			}
			else if(dartResult[i]=='T'){
				numlist[id]= numlist[id]*numlist[id]*numlist[id];
			}
			else if(dartResult[i]=='*'){
				numlist[id] *=2;
				if(id-1>=0) numlist[id-1] *=2;
			}
			else if(dartResult[i]=='#'){
				numlist[id] *=-1;
			}			
		}
		i++;
	}
  //점수합산
	for(int j = 0;j < numlist.size(); j++){
		answer += numlist[j];
	}

 return answer;
}
