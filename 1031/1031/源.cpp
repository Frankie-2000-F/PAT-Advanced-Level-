#include<iostream>
#include<string>
using namespace std;

string s;
int N,k,n;
int main(){
	cin >> s;
	N = s.size();
	switch ((N+2) % 3){
	case 0:
		k = n = (N + 2) / 3;
		break;
	case 1:
		k = (N + 2) / 3;
		n = (N + 2) / 3 + 1;
		break;
	case 2:
		k = (N + 2) / 3;
		n = (N + 2) / 3 + 2;
		break;
	}
	for (int i = 0; i < k - 1; i++){
		cout << s[i];
		for (int j = 0; j < n - 2; j++)
			cout << " ";
		cout << s[N - i - 1] << endl;
	}
	for (int i = k - 1; i <= N - k; i++){
		cout << s[i];
	}
	system("pause");
	return 0;
}