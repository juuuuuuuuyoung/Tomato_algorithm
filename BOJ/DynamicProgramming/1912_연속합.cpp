#include<iostream>
#include<math.h>
using namespace std;

int main(){   
    int now;//현재 숫자
    int result;//지금까지중에 가장 큰 연속합
    int sum; //새로운 연속합
    
    int num;//갯수
    cin >> num;
    
    //첫번째수로 초기화
    cin >> now;
    result = now;
    sum = now;
    
    for(int i = 2; i <= num; i++ ){
        cin >> now;//현재 숫자 받기
        sum = max(now,sum + now);        
        result = max(result, sum);
    }
    
    cout << result;
    return 0;
}
