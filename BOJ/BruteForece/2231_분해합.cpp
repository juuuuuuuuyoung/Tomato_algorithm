//245 의 분해합 
//256 (=245+2+4+5)
//245는 256의 생성자

//N(1≤N≤1,000,000)

#include<iostream>
using namespace std;

int N;//216
int minN = 1000001;
bool check = false;

int main(){
	cin >> N;
	
	int now = N; //N부터 하나씩 작아지면서 생성자인지 확인할 숫자
	
	while(now>N/2){
		int sum = now; //분해합 확인할 합변수
		int nownum = now; //일의자리부터 자르고 남은 숫자
		while(nownum>0){
			if(sum>N)break;
			sum += nownum %10;
			nownum /=10;
		}
		if(sum==N) {
			check = true;
			if(minN>now) minN = now;
		}
		now--;
	}
	if(check == false) cout << 0;
	else cout << minN;
	return 0;
}
