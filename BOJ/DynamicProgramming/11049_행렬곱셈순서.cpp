#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int h[501] ={0};
int y[501] ={0};
int mem[501][501] = {0};
bool visited[501][501] = {false};

int n;
int Go(int start,int finish){
	//cout << endl;
	if(visited[start][finish] == true) return mem[start][finish];

	if(finish == start) return 0;
	else if(finish-start == 1) return h[start] * h[finish]*y[finish];
	int min = pow(2,31)-1;
	for(int i = 0; i < finish-start;i++){
		int now = Go(start,start+i)+Go(start+i+1,finish)+h[start]*y[finish]*y[start+i];
		if(now < min)min = now;
		//cout << min<<endl;
	}	

	mem[start][finish] = min;
	visited[start][finish] = true;
	return mem[start][finish];
}

int main()
{   
	int tmp;
	bool can = true;
	cin >> n; 
	for(int i = 0; i < n; i++){
		int a,b;
		cin >> a >> b;
		h[i] = a;
		y[i] = b;
		if(i >=1 && i<n-1){
			tmp = y[i-1];
			if(tmp != a) can == false; 
			tmp = a;
			if(tmp != b) can == false;
		}
	}
	if(can == false) cout << -1;
	else cout << Go(0,n-1);
	return 0;
}
