//드래곤 커브 // 방향을 기억해야함
//x,y,d,g //d=시작방향,  g는세대

#include<iostream>
#include<vector>
using namespace std;

int pp[101][101] = {0}; //점찍힌배열
int N; //1이상 20이하
vector<int> dir; //드래곤커브방향기억 벡터
int dy[4]={0,-1,0,1}; //0123방향
int dx[4]={1,0,-1,0};

void Go(int x,int y, int g,int ng,int num){ //ng 현재세대
	if(ng>g) return ;

	int beforesize = dir.size(); //방향벡터에 새로 기억시킬꺼 시작 인덱스

	//시작위치=전세대 마지막위치
	int nowx = x; 
	int nowy = y;

	for(int i = 0; i<beforesize; i++){
		int nd ; //now direction
		if(dir[beforesize-i-1]==3){
			nd = 0;
		}
		else{
			nd = dir[beforesize-i-1]+1;
		}
		dir.push_back(nd); //방향벡터에 새로 집어넣기
		
    //현재꺼 위치
    nowx = nowx+dx[nd];
		nowy = nowy+dy[nd];
    //점찍기
		pp[nowy][nowx]=num;

	}
  //다음세대 확인
	Go(nowx,nowy,g,ng+1,num);
}
//4각형 점 갯수 세기
int count(){
	int cnt= 0;
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(pp[i][j]!=0&& pp[i+1][j]!=0&&pp[i][j+1]!=0&&pp[i+1][j+1]!=0)cnt++;
		}
	}
	return cnt;
}

int main(){
	cin >> N;
	int x, y, d, g;
	for(int q=1; q <= N; q++){
		cin >> x>>y>>d>>g;

    //0세대 점찍기
		pp[y][x] = q;
		pp[y+dy[d]][x+dx[d]]=q;
    //0세대 방향저장
		dir.push_back(d);
    //1세대부터 구하러 Go
		Go(x+dx[d],y+dy[d],g,1,q);
    
    //다음 드래곤커브를 위해 방향벡터 clear();
		dir.clear();
	}

  //4각형 되는 점 갯수 세
	cout << count();
	return 0;
}
