#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node{
	int direct;
	int distance;
	node(int d1, int d2){
		direct = d1;
		distance = d2;
	}
};

vector<vector<node>> map1;
bool visited[10000][10000][4]={0};

int main() {
    int n;
    cin >> n;
	
	for(int i = 0; i < n; i++){
		vector<node> temp1;		
		temp1.resize(n,node(0,0));
		map1.push_back(temp1);
	}

	
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            string node;
            cin >> node;
			     
            if(node[0]==70)map1[y][x].direct = 0;
			      else if(node[0]==82) map1[y][x].direct = 1;
			      else if(node[0]==76) map1[y][x].direct = 2;
			      else if(node[0]==66) map1[y][x].direct = 3;
		      	
            map1[y][x].distance = node[1]-48;
        }
    }
    
	int nowy = 0;
	int nowx = 0;
	int befored= 3; //시작방향
	int nextx=0,nexty=0,nextd=0;
	int nowd = 0;
	
	while(1){
		nowd = map1[nowy][nowx].direct;
		visited[nowy][nowx][nowd]=true;

		if(befored == 0){
			if(nowd == 0)nextd = 0;
			else if(nowd == 1) nextd = 1;
			else if(nowd == 2) nextd = 2;
			else if(nowd == 3) nextd = 3;
		}
		else if(befored == 1){
			if(nowd == 0)nextd = 1;
			else if(nowd == 1) nextd = 3;
			else if(nowd == 2) nextd = 0;
			else if(nowd == 3) nextd = 2;
		}
		else if(befored == 2){
			if(nowd == 0)nextd = 2;
			else if(nowd == 1) nextd = 0;
			else if(nowd == 2) nextd = 3;
			else if(nowd == 3) nextd = 1;
		}
		else if(befored == 3){
			if(nowd == 0)nextd = 3;
			else if(nowd == 1) nextd = 2;
			else if(nowd == 2) nextd = 1;
			else if(nowd == 3) nextd = 0;
		}	

		if(nextd == 0){
			nexty= nowy-map1[nowy][nowx].distance;
		}
		else if(nextd ==1){
			nextx= nowx+map1[nowy][nowx].distance;
		}
		else if(nextd ==2){
			nextx= nowx-map1[nowy][nowx].distance;
		}
		else if(nextd ==3){
			nexty= nowy+map1[nowy][nowx].distance;
		}
		
		if(visited[nexty][nextx][nextd]){
			cout << nowx << " "<<nowy<<endl;
			break;
		}
		else {
			nowy = nexty;
			nowx = nextx;
			befored = nextd;
		}
	}
    return 0;
}
