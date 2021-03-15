#include<iostream>
#include<vector>
using namespace std;

int n, b;
vector<int>N;
int main(){
	cin >> n >> b;
	while (n / b != 0){
		N.push_back(n%b);
		n = n / b;
	}
	N.push_back(n%b);
	int k = N.size();
	bool palindromic = true;
	for (int i = 0; i < k/2; i++){
		if (N[i] != N[k - i - 1]){
			palindromic = false;
			break;
		}
	}
	if (palindromic)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = k - 1; i >= 0; i--){
		cout << N[i];
		if (i != 0)
			cout << " ";
	}
	system("pause");
	return 0;
}