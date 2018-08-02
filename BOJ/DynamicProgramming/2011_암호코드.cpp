#include<iostream>
#include<string>
using namespace std;

string code;//25114  //11011   
int mem[5001] ={0};
bool visited[5001] ={false};
int Go(int i){
	if(i >= code.length()) return 1;
	if(i == code.length()-1 ) 
	{
		if(code[i] == '0')return 0;
		return 1;
	}
	if(visited[i] == true) return mem[i];

	int count = 1;
	if(i+1<code.length()){
		if(code[i]=='0') 
			count = 0;
		else if(code[i]>'2') 
			count *= (Go(i+1))%1000000;	
		else if(code[i] == '2')
		{
			if(code[i+1] == '0') 
				count = Go(i+2)%1000000;
			else if(code[i+1]<='6')
				count *= (((Go(i+1))%1000000 + (Go(i+2))%1000000))%1000000;
			else 
				count *= (Go(i+1))%1000000;
		}
		else
		{
			if(code[i+1] == '0') 
				count *= Go(i+2)%1000000;
			else 
				count *= (((Go(i+1))%1000000 + (Go(i+2))%1000000))%1000000;
		}
	}
	visited[i] = true;
	mem[i] = count%1000000;
	return mem[i];
}
int main(){
	cin >> code;

	cout << Go(0)%1000000<<endl;
	return 0;
}
