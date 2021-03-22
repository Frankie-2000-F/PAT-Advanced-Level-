#include <iostream>
#include <string>

using namespace std;

int flag = 0, space = 0;
string in1, in2;

int  digits[10], letters[26];
int main() {
	cin >> in1;
	cin >> in2;

	for (int i = 0; i < in1.size(); i++){
		if (in1[i] <= 'z' && in1[i] >= 'a'){
			in1[i] -= ('a' - 'A');
		}
	}
	for (int i = 0; i < in2.size(); i++){
		if (in2[i] <= 'z' && in2[i] >= 'a'){
			in2[i] -= ('a' - 'A');
		}
	}


	for (int j = 0; j < in1.size(); j++){
		if (in1[j] != in2[flag]){
			if (in1[j] <= 'Z' && in1[j] >= 'A' && letters[in1[j] - 'A'] == 0){
				cout << in1[j];
				letters[in1[j] - 'A']++;
			}
			else if (in1[j] <= '9' && in1[j] >= '0' && digits[in1[j] - '0'] ==0 ) {
				cout << in1[j];
				digits[in1[j] - '0']++;
			}
			else if (in1[j] == '_' && space == 0){
				cout << '_';
				space++;
			}
		}
		else
			flag++;
	}
    system("pause");
    return 0;
}
