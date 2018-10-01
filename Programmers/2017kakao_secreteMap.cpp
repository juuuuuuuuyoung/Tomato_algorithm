#include <string>
#include <vector>
using namespace std;


vector<string> secreteMap(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

	for(int i = 0; i < n; i++){
		answer.push_back("");
	}
	for(int i= 0; i < arr1.size(); i++){
		int now = arr1[i]|arr2[i];
		for(int j = 0; j < n; j++){
			if(now == 0) answer[i] = " "+answer[i];
			else{
				if(now%2==1) answer[i]="#"+answer[i];
				else answer[i] = " "+answer[i];
				now/=2;
			}

		}
	}

    return answer;
}
