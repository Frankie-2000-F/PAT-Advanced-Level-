#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int n, c;

struct stu{
	char id[20];
	char name[20];
	int grade;
};

bool cmp1(stu s1, stu s2){
	return strcmp(s1.id, s2.id) <= 0;
}

bool cmp2(stu s1, stu s2){
	if (strcmp(s1.name, s2.name) != 0){
		if (strcmp(s1.name, s2.name) < 0)
			return true;
		else
			return false;
	}
	else{
		return strcmp(s1.id, s2.id) <= 0;
	}
}

bool cmp3(stu s1, stu s2){
	if (s1.grade != s2.grade ){
		if (s1.grade < s2.grade)
			return true;
		else
			return false;
	}
	else{
		return strcmp(s1.id, s2.id) <=0;
	}
}
vector<stu> stus;




int main(){
	cin >> n >> c;
	for (int i = 0; i < n; i++){
		stu temp;
		cin >> temp.id >> temp.name >> temp.grade;
		stus.push_back(temp);
	}
	switch (c){
	case 1: sort(stus.begin(), stus.end(), cmp1); break;
	case 2: sort(stus.begin(), stus.end(), cmp2); break;
	case 3: sort(stus.begin(), stus.end(), cmp3); break;
	}
	for (int i = 0; i < stus.size(); i++){
		cout << stus[i].id << " " << stus[i].name << " " << stus[i].grade;
		if (i != stus.size() - 1)
			cout << endl;
	}
	system("pause");
	return 0;
}