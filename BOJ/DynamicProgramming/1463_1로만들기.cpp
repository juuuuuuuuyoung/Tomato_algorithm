#include<iostream>
#include<cstring>
using namespace std;

int mem [(int)(1e6+1)];
int Go(int n, int cnt){
	if(n <= 1) return 0;
	if(mem[n] != -1) return mem[n];
	
	if(n/2>=0 && n/3 >=0 && n-1 >=0 && n%2 == 0 && n%3 == 0 ) {
		cnt = 1 + min(Go(n/2,cnt+1),min(Go(n/3,cnt+1),Go(n-1,cnt+1)));
	}	


	else if(n/2>=0 && n-1 >=0 &&n%2 == 0){
		cnt = 1 + min(Go(n/2,cnt+1),Go(n-1,cnt+1));
	}
	else if(n/3 >=0 && n-1 >=0 &&n%3 == 0) {
		cnt =  1 + min(Go(n/3,cnt+1),Go(n-1,cnt+1));
	}
	else{ 
		if(n-1 >=0)cnt =1+  Go(n-1,cnt+1);
	}
	mem[n] = cnt;
	return cnt ;
}

int main(){
	memset(mem,-1,sizeof(mem));
	int N;
	cin >> N;

	mem[2] = 1;
	mem[3] = 1;

	if(N==1) cout << 0;
	else if(N==2 || N==3) cout << 1;
	else {
		Go(N, 0);
		cout << mem[N];
	}
	return 0;
}
