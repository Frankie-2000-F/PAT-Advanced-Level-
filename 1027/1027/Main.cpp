#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(){
	int rgb;
	int color[6];
	char digits[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };
	for (int i = 0; i < 6; i = i + 2){
			cin >> rgb;
			color[i] = rgb / 13;
			color[i + 1] = rgb % 13;
	}
	cout << "#" ;
	for (int i = 0; i < 6; i++){
		cout << digits[color[i]];
	}

}
