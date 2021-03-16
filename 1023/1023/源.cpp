#include<iostream>
#include<cstring>
using namespace std;

int main(){
	char n[20];
	int count[10] = { 0 };
	scanf("%s", n);
	int flag = 0;
	int len = strlen(n);
	for (int i = len -1; i >= 0; i--){
		int temp = n[i] - '0';
		count[temp]++;
		temp = temp * 2 + flag;
		flag = 0;
		if (temp >= 10){
			temp -= 10;
			flag = 1;
		}
		n[i] = temp + '0';
		count[temp] --;
	}
	int x = 0;
	for (int i = 0; i < 10; i++){
		if (count[i] != 0){
			x = 1;
			break;
		}
	}
	printf("%s", (flag == 1 || x == 1) ? "No\n" : "Yes\n");
	if (flag == 1) printf("1");
	printf("%s", n);
	return 0;
}