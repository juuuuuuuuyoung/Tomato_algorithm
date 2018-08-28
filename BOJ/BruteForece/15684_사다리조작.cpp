#include <iostream>
#include <vector>
using namespace std;

int H, N;
int ans = 4;
vector <vector<bool>> lineMap;

void dfs(int count, int rIdx, int cIdx){
    int cnt = 0;
    //다 잘되는지확인
    for (int startpoint = 0; startpoint < N; startpoint++){ 
        int k = 0, x = startpoint;
        
        while (k < H){
            if (x >= 1 && x < N && lineMap[k][x-1])//왼쪽으로
                x--;
            else if (x >= 0 && x < N-1 && lineMap[k][x])//오른쪽으로
                x++;  
            k++;
        }
        //세로한줄 확인하면!
        if (x == startpoint)cnt++; //만약에 내꺼에 잘 도착하면 cnt++;
        else break; //잘 못도착하면 그냥 for문 빠져나옴.
    }
    
    if (cnt == N && ans > count) ans = count;
    
    if (count < 3){//사다리 그릴 수 있으면
        if (rIdx < H){
            for (int k = cIdx; k < N-1; k++){
                if (k-1 >= 0 && lineMap[rIdx][k-1])	continue;//가장 왼쪽
                else if (k+1 < N-1 && lineMap[rIdx][k+1]) continue; //가장 오른쪽
                else if (lineMap[rIdx][k]) continue; //이미 그려져있는곳
                
                lineMap[rIdx][k] = true;
                dfs(count+1, rIdx, k+2);
                lineMap[rIdx][k] = false;
            }
            
            for (int j = rIdx+1; j < H; j++){
                for (int k = 0; k < N-1; k++){
                    if (k-1 >= 0 && lineMap[j][k-1]) continue;
                    else if (k+1 < N-1 && lineMap[j][k+1]) continue;
                    else if (lineMap[j][k]) continue;
                    
                    lineMap[j][k] = true;
                    dfs(count+1, j, k+2);
                    lineMap[j][k] = false;
                }
            }
        }
    }
}

int main (){
    int M, left, right;
    
    cin >> N >> M >> H;
    
    lineMap.resize(H);
    for (int i = 0; i < H; i++){
        for (int j = 0; j < N-1; j++){
            lineMap[i].push_back(false);
		}
    }
    
    for (int i = 0; i < M; i++){
        cin >> left;
        cin >> right;
        lineMap[left-1][right-1] = true;
    }
    
    dfs(0, 0, 0);
    
	if (ans == 4) ans = -1;
    cout << ans;
    
    return 0;
}
