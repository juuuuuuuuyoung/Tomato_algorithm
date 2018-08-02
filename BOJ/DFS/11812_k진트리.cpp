#include<iostream>
#include<vector>
using namespace std;

long long N;
int K,Q;
vector<long long> result;

int main(){
	scanf("%lld %d %d",&N, &K, &Q);
	
	for(int i = 0; i < Q; i++){
		long long x,y;
		scanf("%lld %lld",&x, &y);

		if(K==1){
			if(x>y)result.push_back(x-y);
			else result.push_back(y-x);
			continue;
		}

		long long ans = 0;
		while(x!=y){
			if(y>x) swap(x,y);

			x=(K-2+x)/K;
			ans++;
		}
		result.push_back(ans);
	}

	for(int i = 0; i < Q;i++){
		printf("%lld\n", result[i]);
	}

	return 0;
}
