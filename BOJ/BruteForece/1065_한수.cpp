#include<iostream>
using namespace std;

int N;
int mem[1001]={0};

int main(){
	cin >> N;
	mem[110] = 99;

	if(N <= 99) cout << N;
	else if(N<=110) cout << 99;	
	else{
		int n3,n2,n1;
		int now;
		
		for(int i = 111; i <=N; i++){
			now = i;
			n3 = now%10;
			now = now/10;
			n2 = now%10;
			n1 = now/10;

			if((n3-n2 )== (n2-n1)) mem[i] = mem[i-1]+1;
			else mem[i]= mem[i-1];
		}
		cout << mem[N];
	}

	return 0;
}
