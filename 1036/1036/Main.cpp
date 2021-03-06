#include<stdlib.h>
#include<iostream>
#include <vector>
using namespace std;
int N;
vector<string> name, ID, gender;
vector<int> grade;
int main(){
	cin >> N;
	//for (int i = 1; i < N; i++){
	//	string name, id, gender;
	//	int grade;
	//	scanf("%s%s%s%d", &name, &id, &gender, &grade);
	//	name.append(name);

	//}
	string name;
	scanf_s("%s", &name);
	name.append(name);
	cout << name[0];
	system("pause");
	return 0;
}