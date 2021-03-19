#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

struct record{
	string name;
	int month, day, hour, minute;
	int type;
	int time;
	record() :name(), month(), day(), hour(), minute(), type(), time(){}
	record(string name, int mon, int d, int h, int m, int t, int time) :name(name), month(mon), day(d), hour(h), minute(m), type(t), time(time){}
};

struct period{
	int mon, sd, ed, sh, sm, eh, em;
	string name;
	int time;
	period() :mon(), sd(), ed(), sh(), sm(), eh(), em(), name(),time(){}
	period(int mon, int d1, int d2, int h1, int m1, int h2, int m2, string name, int time) :mon(mon), sd(d1), ed(d2), sh(h1), sm(m1), eh(h2), em(m2), name(name),time(time){}
};

bool cmp(record r1, record r2){
	if (strcmp(r1.name.c_str(), r2.name.c_str()) != 0)
		return strcmp(r1.name.c_str(), r2.name.c_str()) < 0;
	else
		return r1.time < r2.time;
		
}
int n;
float toll[24], daycost = 0;

float cal(int d, int h, int m){
	float sum = 0;
	sum += toll[h] * m + daycost*(d - 1);
	for (int i = 0; i < h; i++){
		sum += toll[i] * 60;
	}
	return sum;
}



vector<record> records;
vector<period> periods;
int main(){
	for (int i = 0; i < 24; i++){
		cin >> toll[i];
		toll[i] /= 100;
		daycost += toll[i] * 60;
	}
	cin >> n;
	for (int i = 0; i < n; i++){
		char name[20];
		char type[10];
		int mon, d, h, m, t;
		record temp;
		cin >> name;
		scanf_s("%d:%d:%d:%d", &mon, &d, &h, &m);
		cin >> type;
		t = strcmp(type, "on-line") == 0 ? 0 : 1;
		int time = (d-1) * 24 * 60 + h * 60 + m;
		temp = record(name, mon, d, h, m, t, time);
		records.push_back(temp);
	}
	sort(records.begin(), records.end(), cmp);
	record temp;
	for (int i = 0; i < records.size(); i++){
		if (records[i].type == 0)
			temp = records[i];
		if (records[i].type == 1 && temp.type == 0 && strcmp(records[i].name.c_str(), temp.name.c_str()) == 0){
			int time = records[i].time - temp.time;
			period p = period(temp.month, temp.day, records[i].day, temp.hour, temp.minute, records[i].hour, records[i].minute, temp.name, time);
			periods.push_back(p);
		}
	}
	int people = 1;
	string tempName = periods[0].name;
	vector<int> flag;
	flag.push_back(0);
	for (int i = 1; i < periods.size(); i++){
		if (strcmp(periods[i].name.c_str(), tempName.c_str()) != 0){
			people++;
			tempName = periods[i].name;
			flag.push_back(i);
		}
	}
	flag.push_back(periods.size());
	for (int i = 1; i <= people; i++){
		cout << periods[flag[i - 1]].name << " ";
		printf("%02d\n", periods[flag[i - 1]].mon);
		float total = 0;
		for (int j = flag[i - 1]; j <= flag[i] - 1; j++){
			float sum = 0;
			sum = cal(periods[j].ed, periods[j].eh, periods[j].em) - cal(periods[j].sd, periods[j].sh, periods[j].sm);
			total += sum;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", periods[j].sd, periods[j].sh, periods[j].sm, periods[j].ed, periods[j].eh, periods[j].em, periods[j].time, sum);
		}
		printf("Total amount: $%.2f\n", total);
	}
	system("pause");
	return 0;
}