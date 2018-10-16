#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char map[111][111];
int R, C;
int N;
vector<pair<int, int>> group;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool visited[101][101]={0};

void dfs(int y, int x){
	if(map[y][x] == '.')return;
	if(visited[y][x]) return;
	
	visited[y][x] = true;

	group.push_back(make_pair(y,x));

	for(int k = 0; k < 4; k++){
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(nx>=0 && ny>=0 && nx<C && ny< R) dfs(ny, nx);
	}
}

void check(){
	memset(visited,false,sizeof(visited));

	for(int i = 0; i < R; i++){
		for(int j = 0; j<C; j++){
			if(map[i][j]=='.')continue;
			if(visited[i][j])continue;

			group.clear();

			dfs(i,j);

			vector<int> low(C,-1); //각 열별로 최대값 담아놓을 거 = 덩어리중에 열별로 미네랄 y 최대값

			for(auto &p : group){//first = y , second = x
				low[p.second] = max(low[p.second],p.first); //열별로 가장 큰값
				map[p.first][p.second]='.'; //싹지우기
			}

			int lowset = R; //덩어리째 lowset만큼 내릴 것 
			for(int i, j = 0; j < C; j++){
				if(low[j] == -1) continue; //이건 미네랄 없는거 = 패쓰
				for( i = low[j]; i<R && map[i][j]=='.';i++);//비어있는 가장 밑에까지
				lowset = min(lowset, (i -1)-low[j]); //열중에 가장 작은 값
			}

			for(auto &p : group){
				p.first += lowset; //다시 그리기
				map[p.first][p.second] = 'x';
				visited[p.first][p.second] = true;
			}
		}
	}


}
void Go(int h, int d){
	h = R-h;
	if(d==1){ //오른쪽
		for(int i = 0; i < C; i++){
			if(map[h][i]=='x'){
				map[h][i]='.';
				break;
			}
		}
	}
	else{ //왼쪽
		for(int i = C-1; i >= 0; i--){
			if(map[h][i]=='x'){
				map[h][i]='.';
				break;
			}
		}
	}
	check();
}


int main(){
	cin >> R >> C;
	for(int i=0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> map[i][j];
		}
	}
	cin>> N;
	for(int k = 1; k <= N; k++){
		int h;
		cin >> h;
		Go(h,k%2); //처음시작이 오른쪽!
	}

	for(int i=0; i < R; i++){
		for(int j = 0; j < C; j++){
			cout<< map[i][j];
		}
		cout << endl;
	}

	return 0;
}
