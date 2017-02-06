#include <stdio.h>
#include <string>

using namespace std;

string result;

string add(string a, string b){
	string bigger = a.size() > b.size() ? a : b;
	string smaller = a == bigger ? b : a;
	string result = "";
	int remainder = 0;
	char curr;
	while(bigger.length()){
		if(smaller.length()){
			curr = ((bigger.back() - '0' + smaller.back() - '0' + remainder) % 10) + '0';
			remainder = (bigger.back() - '0' + smaller.back() - '0' + remainder) / 10;
		}else{
			curr = ((bigger.back() - '0' + remainder) % 10) + '0';
			remainder = (bigger.back() - '0' + remainder) / 10;
		}
		result = curr + result;
		bigger.pop_back();
		if(smaller.length())
			smaller.pop_back();
		}
		curr = remainder + '0';
	if(remainder)
		result = curr + result;
	while(result.front() == '0')
		result.erase(0);
	if(result.size() == 0)
		result = "0";
	return result;
}

string multiply(string a, string b){
	string bigger = a.size() > b.size() ? a : b;
	string smaller = a == bigger ? b : a;
	string result = "0";
	string counter = "";
	char curr;
	int remainder = 0;
	while(smaller.length()){
		string temp = bigger;
		string toAdd = "";
		remainder = 0;
		while(temp.length()){
			curr = (((temp.back() - '0') * (smaller.back() - '0')) + remainder) % 10 + '0';
			remainder =  (((temp.back() - '0') * (smaller.back() - '0')) + remainder) / 10;
			toAdd = curr + toAdd;
			temp.pop_back();
		}
		curr = remainder + '0';
		if(remainder)
			toAdd = curr + toAdd;
		toAdd = toAdd + counter;
		result = add(result, toAdd);
		counter += '0';
		smaller.pop_back();
	}
	return result;
}


int main(){
	int T;
	scanf("%d ", &T);
	int N;
	while(T--){
		result = "1";
		scanf("%d ", &N);
		while(N--) result = multiply(result, to_string(N + 1));
		printf("%s\n", result.c_str());
	}
	return 0;
}