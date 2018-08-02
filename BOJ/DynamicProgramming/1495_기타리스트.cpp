#include<iostream>
using namespace std;

int N,S,M;
int a[1003];
int dp[103][1003];


int go(int n,int s){
	 if(s<0 || s>M)
		 return -100000000; // caution 1,2

	 if(n==N)return s;
	 int& ret = dp[n][s];
	  if(ret!=-1) return ret;
	  ret = max(go(n+1,s+a[n]),go(n+1,s-a[n]));

	  return ret;
}

int main(){
	cin>>N >> S>>M;

	for(int i = 0; i <= N; i++){
		for(int j = 0; j <2001; j++){
			dp[i][j] = -1;
		}
	}

	for(int i=0;i<N;i++){ 
		cin >> a[i]; 
	}

	int ans = go(0,S);
	if(ans<0) printf("-1"); 
	else printf("%d",ans);


	
	return 0;
}

