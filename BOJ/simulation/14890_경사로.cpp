#include<iostream>
using namespace std;

int runway[101][101]={50};
int n;
int x;


int check(){
	int cnt = 0;
	for(int i= 0; i < n; i++){
		for(int j = 0;j < n; j++){
			cin >> runway[i][j];
		}
	}
	int ncnt=1;
	int lowcount = 0;
	int ccount = 0;
	bool lowstate = false;
	//가로
	for(int i = 0; i < n; i++){
		for(int j = 0; j <n-1; j++){
			int now = runway[i][j];
			int next = runway[i][j+1];

			if(next - now >=2 || next - now <=-2) ccount -= 100;
			else if(next > now){
				if(lowstate && lowcount < x*2) ccount -= 100;
				else if(ncnt >= x) ccount++;
				else ccount -= 100;
				lowstate = false;
				ncnt = 1;
			}
			else if(next < now){
				lowstate = true;
				if(lowcount>=1 && lowcount >=x) {
					ccount++;
				}
				else if(lowcount>=1 && lowcount <x) ccount -=100;

				ncnt = 1;
				lowcount = 1;
			}
			else {
				ncnt++;
				if(lowstate)lowcount++;
			}
		}//한줄 탐색 완료

		//마지막처리
		if(lowstate == true && lowcount<x) ccount -=100;
		else if(ncnt >= x) ccount++;
		if(ccount >=0) cnt++;

		//init();
		lowstate = false;
		lowcount = 0;
		ccount = 0;
		ncnt = 1;
	}

	//세로
	for(int i = 0; i < n; i++){
		for(int j = 0; j <n-1; j++){
			int now = runway[j][i];
			int next = runway[j+1][i];

			if(next - now >=2 || next - now <=-2) ccount -= 100;

			else if(next > now){	
				if(lowstate && lowcount < x*2) ccount -= 100;
				else if(ncnt >= x) ccount++;
				else ccount -= 100;
				lowstate = false;
				ncnt = 1;
			}
			else if(next < now){
				lowstate = true;
				if(lowcount>=1 && lowcount >=x) {
					ccount++;
				}
				else if(lowcount>=1 && lowcount <x) ccount -=100;

				ncnt = 1;
				lowcount = 1;
			}
			else {
				ncnt++;
				if(lowstate)lowcount++;
			}
		}//한줄 탐색 완료

		//마지막처리
		if(lowstate == true && lowcount<x) ccount -=100;
		else if(ncnt >= x) ccount++;
		if(ccount >=0) {
			cnt++;
		}

		//init();
		lowstate = false;
		lowcount = 0;
		ccount = 0;
		ncnt = 1;
	}
	return cnt;
}

int main(){
	cin >> n >> x;
	cout << check();
	return 0;
}
