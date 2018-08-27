//오답

//두 문자열 string s, string t에 대하여 s의 접미사와 t의 접두사가 일치하는 경우 s와 t사이에 겹침이 있다고 한다. 
//소문자로 이루어진 두 문자열 s, t가 주어질 때, s와 t 사이의 겹침의 개수를 리턴하시오.
//1<= s,t의 길이 <=1,000,000

#include <string>
using namespace std;
 
class Solution{
public:
    int solution(string s, string t){
		int cnt = 0;
		int sidx = s.size()-1;
		int size = 1;
		bool check;
 
		while(sidx>=0){
			if(size > t.size()) break;
			check = true;
			for(int i=0; i < size/2+1; i++){
				if(s[sidx+i]!=t[i]){
					check = false;
					break;
				}
				if(s[s.size()-1-i] != t[size-1-i]){
					check = false;
					break;
				}
			}
			if(check == true) {
				cnt ++;	
			}
			sidx--;
			size++;
		}
		
		return cnt;
	}
};
