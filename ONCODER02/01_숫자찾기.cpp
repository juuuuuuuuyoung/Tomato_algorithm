// left 이상, right 이하의 숫자중 36이 포함된 숫자의 갯수
// 0<= left, right <= 1,000,000
class Solution{
public:
    int find(int left, int right){
		int cnt = 0;
        
		if(left<36 && right < 36) return 0;
		else if(left<36 && right>=36) left = 36;
 
		while(left<=right){
			int now = left;
			
			while(now>=0){
				if(now%10 == 6){
					if(now%100 == 36) {
						cnt++;
						break;
					}
				}
				if(now<10)break;
				now/=10;
			}
			
			left++;
		}
		return cnt;
    }
};
