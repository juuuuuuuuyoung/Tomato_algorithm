// Aan x Bbn 
//계산결과 행렬의 각 행렬의 요소를 1000000007 로 나머지 연산하여 리턴
#include <vector>
using namespace std;

class Solution{
public:
vector<vector<int> > multiply(vector<vector<int> > A, vector<vector<int> > B, int an, int bn){
    long long mod = 1000000007;  
	vector<vector<int>> now;
	
	vector<int>a;
	a.push_back(1LL);
	a.push_back(0LL);
	now.push_back(a);
	vector<int>b;
	b.push_back(0LL);
	b.push_back(1LL);
	now.push_back(b);
 
	for(int i = 1; i <= an; i++){		
		long long aa = ((now[0][0]*A[0][0])%mod + (now[0][1]*A[1][0])%mod)%mod;
		long long bb = ((now[0][0]*A[0][1])%mod + (now[0][1]*A[1][1])%mod)%mod;
		long long cc = ((now[1][0]*A[0][0])%mod + (now[1][1]*A[1][0])%mod)%mod;
		long long dd = ((now[1][0]*A[0][1])%mod + (now[1][1]*A[1][1])%mod)%mod;
		now[0][0]=aa%mod;
		now[0][1]=bb%mod;
		now[1][0]=cc%mod;
		now[1][1]=dd%mod;
		
		if(aa ==1 && bb==0 && cc== 0&& dd== 1)break;
		
	}
	for(int i = 1; i <= bn; i++){
		long long aa = ((now[0][0]*B[0][0])%mod + (now[0][1]*B[1][0])%mod)%mod;
		long long bb = ((now[0][0]*B[0][1])%mod + (now[0][1]*B[1][1])%mod)%mod;
		long long cc = ((now[1][0]*B[0][0])%mod + (now[1][1]*B[1][0])%mod)%mod;
		long long dd = ((now[1][0]*B[0][1])%mod + (now[1][1]*B[1][1])%mod)%mod;
		now[0][0]= aa%mod;
		now[0][1]= bb%mod;
		now[1][0]=cc%mod;
		now[1][1]=dd%mod;
		if(aa ==1 && bb==0 && cc== 0&& dd== 1)break;
	}
	return now;
}
 
};
