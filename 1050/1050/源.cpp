#include<iostream>
#include<string>

using namespace std;

string s1, s2;
bool have[10000];
int main(){
	fill(have, have + 10000, false);
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.length(); i++){
		have[s2[i]] = true;
	}
	for (int i = 0; i < s1.length(); i++){
		if (!have[s1[i]])
			cout << s1[i];
	}
	return 0;
}