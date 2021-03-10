#include<stdlib.h>
#include<iostream>
#include <vector>
#include <string>
using namespace std;
int N;
struct stu{
	string name, id, gender;
	int grade;
	stu() :name("Absent"), gender(""), id(""), grade(-1){};
	void operator=(stu a)
	{
		name = a.name;
		gender = a.gender;
		id = a.id;
		grade = a.grade;
	}
};
int main(){
	vector<stu> v;
	cin >> N; 
	stu s;
	for (int i = 0; i < N; i++){
		cin >> s.name >> s.gender >> s.id >> s.grade;
		v.push_back(s);
	}
	int max = -1, min = 101;
	stu worstMale, bestFemale;
	for (int i = 0; i < v.size(); i++){
		if (v[i].gender == "M" && v[i].grade < min){
			min = v[i].grade;
			worstMale = v[i];
		}
		if (v[i].gender == "F" && v[i].grade > max){
			max = v[i].grade;
			bestFemale = v[i];
		}
	}
	if (bestFemale.name == "Absent")
		cout << "Absent" << endl;
	else
		cout << bestFemale.name << " " << bestFemale.id << endl;
	if (worstMale.name == "Absent")
		cout << "Absent" << endl;
	else
		cout << worstMale.name << " " << worstMale.id << endl;
	if (bestFemale.name == "Absent" || worstMale.name == "Absent")
		cout << "NA";
	else
		cout << bestFemale.grade - worstMale.grade;
	return 0;
}