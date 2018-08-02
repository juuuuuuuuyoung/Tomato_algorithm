#include<iostream>
#include<string>
#include<list>
using namespace std;

int mem[1001][1001] = {0};
string t1;
string t2;
list<char> result;

int main(){
	cin >> t1;
	cin >> t2;

	for(int i = 0; i < t1.size();i++){
		for(int j = 0; j < t2.size(); j++){
			if(t1[i] == t2[j]) {
				mem[i+1][j+1] = mem[i][j]+1;
			}
			else mem[i+1][j+1] = max(mem[i][j+1],mem[i+1][j]);
		}
	}

	int ans = mem[t1.size()][t2.size()];
	cout <<ans<<endl;


	int a = t1.size();
	int b = t2.size();

	while(1){
		if(mem[a][b] == 0) break;
		if(mem[a][b] == mem[a-1][b]){
			a--;
		}
		else if(mem[a][b]==mem[a][b-1]){
			b--;
		}
		else {	
			a--;
			b--;
			result.push_front(t1[a]);	
		}
	}
	for(auto temp : result) cout << temp;

	return 0;
}
