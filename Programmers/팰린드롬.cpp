#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> ch;
int solution(int n, int m) {
    int answer = 0;
  
    if(m<=9)return  m-n+1;
	else if(n<=9 && m>9){
		answer += 10-n;
		n= 10;
	}
	bool check = true;
	for(int i= n; i <=m; i++){
		int now = i;
		while(now>0){

			int c = now%10;
			ch.push_back(c);
			now /=10;
		}

		for(int  k= 0; k <ch.size()/2; k++){
			if(ch[k]!=ch[ch.size()-1-k]) {
				check = false;
				break;
			}
		}
		if(check){
			answer++;
			
		}
		check = true;
		ch.clear();

	}
    return answer;
}
