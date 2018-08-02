#include<iostream>
#include<vector>
using namespace std;

struct box{
	int x1;
	int y1;
	int x2;
	int y2;
	box(int X1, int Y1, int X2, int Y2){
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
	}
};
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	line(int X1, int Y1, int X2, int Y2){
		x1 = X1;
		y1 = Y1;
		x2 = X2;
		y2 = Y2;
	}
};
vector<line> linea;
vector<line> lineb;
int N;
vector<box> boxes;
bool visited[1001]={false};

bool check(box a, box b){
	linea.clear();
	lineb.clear();

	linea.push_back(line(a.x1,a.y1,a.x1,a.y2));//a1
	linea.push_back(line(a.x1,a.y2,a.x2,a.y2));//a2 
	linea.push_back(line(a.x2,a.y1,a.x2,a.y2));//a3
	linea.push_back(line(a.x1,a.y1,a.x2,a.y1));//a4

	lineb.push_back(line(b.x1,b.y1,b.x1,b.y2));//a1
	lineb.push_back(line(b.x1,b.y2,b.x2,b.y2));//a2
	lineb.push_back(line(b.x2,b.y1,b.x2,b.y2));//a3
	lineb.push_back(line(b.x1,b.y1,b.x2,b.y1));//a4


	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= 4; j++){
			line a = linea[i-1];
			line b = lineb[j-1];
			if((i+j)%2 == 0){ //같은방향끼리 비교	 
				if(a.x1== b.x1){//세로로 같을 때
					if(a.y1>=b.y1 && a.y2<=b.y2) return true;//a가 아래에 있을 때
					else if(a.y2>=b.y1 && a.y2<=b.y2) return true;//a가 위에 있을 때
				}
				else if(a.y1 == b.y2){ //가로로 같을 때
					if(a.x1>=b.x1 && a.x2<=b.x2) return true;
					else if(a.x2>=b.x1 && a.x2<=b.x2) return true;
				}
			}
			else{ //서로 엇갈리게 비교
				if(a.x1>=b.x1 && a.x1<=b.x2 && b.y1>=a.y1 &&b.y1<=a.y2) return true;
				else if(b.x1>=a.x1 && b.x1<=a.x2 && a.y1>=b.y1 &&a.y1<=b.y2)return true;
			}
		}
	}
	return false;
}
void Go(int idx){
	if(visited[idx]) return;
	visited[idx] = true;
	
	box now = boxes[idx];

	for(int i = 1; i <= N; i++){
		if(i==idx) continue;
		else if(check(now,boxes[i])){
			Go(i);
		}
	}
}
int main(){
	cin >> N;
	
	boxes.push_back(box(0,0,0,0));

	for(int i = 0; i < N; i++){
		int x1,y1,x2,y2;
		cin >> x1>>y1>>x2>>y2;
		//왼쪽위 오른쪽 아래로 맞춰놓기//처음 시작 같은 곳 있는지 확인
		if(x2<x1 && y2<y1) {
			boxes.push_back(box(x2,y2,x1,y1));
		}
		else if(x1<x2 && y1>y2){
			boxes.push_back(box(x1,y2,x2,y1));
		}
		else if(x1>x2 && y1<y2) {
			boxes.push_back(box(x2,y1,x1,y2));
		}
		else {
			boxes.push_back(box(x1,y1,x2,y2));
		}
	}


	int cnt = -1;

	//dfsAll
	for(int i = 0; i <= N; i++){
		if(!visited[i]){	
			Go(i);
			cnt++;
		}
	}
	cout << cnt<<endl;


	return 0;
}
