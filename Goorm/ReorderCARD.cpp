#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//10 <= C <= 1000
//0 <= P <= 1000
//1 <= N < ceil(C / 2), N은 정수 (ceil: 주어진 숫자보다 크거나 같은 숫자 중 가장 작은 정수)

int C, P;
vector <int> nn;
vector <int> mem;
vector <int> newmem;
int main(){
	cin >> C >> P;
	for(int i = 0; i < P; i++){
		int a;
		cin >>a;
		nn.push_back(a);
	}
	//mem에 순서대로 넣기
	for(int i = 0; i < C; i++){
		mem.push_back(i+1);
	}
	newmem.resize(C);

	int cnt = 0;
	int N ;
	int cardnum = C;
	
	for(int i = 0; i < cardnum; i++){
			newmem[i] = mem[i];
	}

	while(cnt < P){
		N= nn[cnt];

		for(int i = 0; i < cardnum-(2*N); i++){
			newmem[i] = mem[i+N];
		}
		int k = 0;
		for(int i = cardnum-(2*N); i<cardnum-N; i++){
			newmem[i] = mem[k];
			k++;
		}
		cardnum= cardnum-(2*N);

		if(cardnum<=2*N) {
			cnt++; 
			cardnum = C;
		}
		for(int i = 0; i < C; i++){
			mem[i] = newmem[i];
		}
	}

	for(int i = 0; i < 5; i++){
		cout << mem[i]<<endl;
	}

	return 0;
}
