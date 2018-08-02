#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int little[9];
vector<int> result;
int main(){
	int height = 0;
	for(int i = 0; i < 9; i++) {
		cin >> little[i];
		height += little[i];
	}
	int sum = height;

	for(int i = 0; i < 9; i++){
		sum -= little[i];
		for(int j = i+1; j <9; j++){
			if(sum -little[j]==100){
				for(int k=0; k<9; k++){
					if(k==i || k==j) continue;
					result.push_back(little[k]);
				}
				sort(result.begin(),result.end());
				for(auto temp : result)cout << temp<<endl;
				return 0;
			}
		}
		sum = height;
	}
	return 0;
}
