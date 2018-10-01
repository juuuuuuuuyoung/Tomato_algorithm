#include <iostream>
#include <sstream>
#include <string>

using namespace std;

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
