#include<iostream>
#include<string>
using namespace std;

string id[1000],psw[1000],idT[1000];
int flag[1000], n, num = 0,maxid=0;
char origin[4] = { '1', '0', 'l', 'O' }, format[4] = { '@', '%', 'L', 'o' };
int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> id[i] >> psw[i];
		string result = "";
		for (char c : psw[i]){
			char a = c;
			for (int j = 0; j < 4; j++){
				if (c == origin[j]){
					a = format[j];
					flag[i] = 1;
					break;
				}
			}
			result.push_back(a);
		}
		if (flag[i] == 1){
			num++;
			if (i > maxid)
				maxid = i;
		}
		idT[i].assign(result);
	}
	if (num == 0){
		if (n == 1)
			cout << "There is 1 account and no account is modified";
		else
			cout << "There are " << n << " accounts and no account is modified";
	}
	else{
		cout << num << endl;
		for (int i = 0; i <= maxid; i++){
			if (flag[i] == 1){
				cout << id[i] << " " << idT[i];
				if (i != maxid)
					cout << endl;
			}
		}
	}
	system("pause");
	return 0;
}