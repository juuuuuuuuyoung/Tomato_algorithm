#include <iostream>
#include <vector>
using namespace std;

struct item{
	int idx;
	int order;
	item(int i, int o){
		idx = i;
		order = o;
	}	
};
vector<item> mem;

int main() {

	int cnt = 0;
	bool no = true;
	int a;
	
	while(scanf("%d",&a)==1){
		

		bool pushok= false;
		int small = 101;
		int smallidx = 0;
		
		for(int i = 0; i < mem.size(); i++){
			if(a==mem[i].idx) {
				pushok= true;
				mem[i].order = cnt;
				break;
			}
			if(mem[i].order<small) {
				small = mem[i].order;
				smallidx = i; 
			}
		}
		
		if(!pushok){
			if(mem.size()<3) mem.push_back(item(a,cnt));
			else{
				no = false;
				cout << mem[smallidx].idx << endl;
				mem[smallidx].idx = a;
				mem[smallidx].order = cnt;	
			}
		}
		cnt++;
	}
	
	if(no) cout << 0;
	
	return 0;
}
