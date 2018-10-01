#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//최소 이동거리는 4km 최대 이동거리는 178km
//40km까지 : 720원
//41km부터 : 8km마다 80원 추가
//최초 잔액이 20,000원
//더 이상 차감할 수 없으면 이동할 수 없으므로 현재 잔액을 출력하고 프로그램을 종료

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    
	int sum = 0;
	int money = 20000;
	bool standard = true;
	bool first = true;
	

	for (int distance; !(ss >> distance).fail(); ) {

		int before = money;
		sum += distance;


		if(sum <= 40) {
			if(standard){
				money -= 720;
				standard = false;
			}
			continue;
		}
		else {
			if(standard && first){
				money -= 720;
				standard = false;
				sum-=40;
			}
			else if(first) {
				sum -= 40;
				first = false;
			}
			money -= (sum/8) *80;
			sum = sum % 8;
		}

		if(money <0) {
			cout << before << endl;
			return 0;
		}
    }
	cout << money<<endl;
    return 0;
}
