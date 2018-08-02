#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int map[501][501]={0};
bool visited[501][501]={false};
int mem[501][501]={0};
int maxcount = 0;
struct point{
	int y;
	int x;
	int amount;
	point(int Y, int X, int m){
		y= Y;
		x= X;
		amount = m;
	}
};
vector <point> manylist;
bool cmd(point A, point B){
	return A.amount < B.amount;
}
int Go(int y, int x, int day){
	if(y<0 || y>=n || x < 0 || x>=n) return 0;
	if(visited[y][x] == true) return mem[y][x];

	int dx[4] = {-1,1,0,0};
	int dy[4] = {0,0,1,-1};
	int max = 0;
	for(int i = 0; i < 4; i++){ 
		int ty = y + dy[i];
		int tx = x + dx[i];
		if(tx >=0 && ty>=0 && tx<n&& tx<n){	
			if(map[ty][tx]>map[y][x] ) {
				int now = Go(ty,tx,day+1);
				//cout << "now : "<<now <<endl;
				if(now>max){
					max = now;
					//cout << "max : " << max<<endl;
				}
			}
		}
	}
	visited[y][x] = true;
	mem[y][x] =1 + max;
	return mem[y][x];
}
int main(){
	cin >> n;
	int a;
	for(int i = 0; i < n;i++){
		for(int j=0; j < n;j++){
			cin >> a;
			map[i][j] = a;
			manylist.push_back(point(i,j,a));
		}
	}
	sort(manylist.begin(),manylist.end(),cmd);

	//cout << endl;

	for(int i = 0; i < manylist.size();i++){
		int now = Go(manylist[i].y,manylist[i].x,1);
		if(now > maxcount) {
			maxcount = now;
			//cout << "("<<manylist[i].y<<","<<manylist[i].x<<") : "<<now<<endl;
		}
	}
	cout << maxcount;
	return 0;
}
