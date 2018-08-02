#include<iostream>
#include<string>
using namespace std;

int mem[1001][1001] = {0};
string t1;
string t2;

int main(){
	cin >> t1;
	cin >> t2;

	bool same = false;
	for(int i = 0; i < t1.size();i++){
		if(same == true) mem[i][0] = 1;
		else  {
			if((t2[0] == t1[i])){
			same = true;
			mem[i][0] = 1;
			}
		}
	}
	same = false;
	for(int i = 0; i < t2.size();i++){
		if(same == true) mem[0][i] = 1;
		else {
			if(t1[0] == t2[i]){
			same = true;
			mem[0][i] = 1;
			}
		}
	}

	for(int i = 1; i < t1.size();i++){
		for(int j = 1; j < t2.size(); j++){
			if(t1[i] == t2[j]) {
				mem[i][j] = mem[i-1][j-1]+1;
			}
			else mem[i][j] = max(mem[i-1][j],mem[i][j-1]);
		}
	}

	int ans = mem[t1.size()-1][t2.size()-1];
	cout <<ans<<endl;
	return 0;
}
