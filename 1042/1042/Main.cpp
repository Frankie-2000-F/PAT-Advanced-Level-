#include<iostream>
#include<string>
using namespace std;

char ct[5] = { 'S', 'H', 'C', 'D', 'J' };
int card[55], result[55];
int order[55];

void initCard(){
	for (int i = 1; i <= 54; i++){
		card[i] = i;
	}
}

int main(){
	initCard();
	int iterTime;
	cin >> iterTime;
	for (int i = 1; i <= 54; i++){
		cin >> order[i];
	}
	for (int i = 0; i < iterTime; i++){
		for (int j = 1; j <= 54; j++){
			result[order[j]] = card[j];
		}
		for (int j = 1; j <= 54; j++){
			card[j] = result[j];
		}
	}
	for (int i = 1; i <= 54; i++){
		if (i == 54)
			cout << ct[(result[i] - 1)/13]<< (result[i] - 1)%13 + 1;
		else
			cout << ct[(result[i] - 1) / 13] << (result[i] - 1) % 13 + 1 << " ";
		
	}
	system("pause");
	return 0;

}