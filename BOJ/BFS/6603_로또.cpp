#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<int> mem;
list<int> lotto;

void Go(int idx,int cnt){
	if(cnt == 6) {
		//ans++; 
		for(auto temp:lotto){
			cout << temp<<" ";
		}
		cout << endl;
		return ;
	}
	if(idx>=mem.size()) return;

	lotto.push_back(mem[idx]);
	Go(idx+1,cnt+1);
	lotto.pop_back();
	Go(idx+1,cnt);

}

int main(){
	int k;

	while(1){
		cin >> k;
		if(k== 0) break;
		
		for(int i = 0; i < k; i++){
			int a;
			cin >> a;
			mem.push_back(a);	
		}
		Go(0,0);

		mem.clear();
		cout << endl;
	}

	return 0;
}
