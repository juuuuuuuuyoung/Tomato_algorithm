#include <iostream>
#include <vector>
using namespace std;

int D; //1< days <= 1000
vector<int> price;

int p = 0;
int main() {
	cin >> D;
	for(int i = 0; i < D; i++) {
		int a;
		cin >> a;
		price.push_back(a);
	}
	
	int max = price[D-1];
	int nowsum = 0; //현재까지 팔기로 한거

	for(int i = D-2; i >=0; i--){//뒤에서부터 계산
		if(price[i]<=max) { //가격 내려갈때 
			nowsum += max-price[i];//팔아야함
			if(i==0){ //마지막일때 계산
				if(nowsum - 1 >0){
					p += nowsum-1;
				}
			}
		}
		else{
			if(nowsum != 0){
				if(nowsum - 1 >0){
					p += nowsum-1;
				}
				nowsum = 0;
			}
			if(price[i]>price[i+1]){ //가격 오를때 = 아무것도 안해야함
				max = price[i];	
			}
		}
	}
	cout << p;
	return 0;
}
