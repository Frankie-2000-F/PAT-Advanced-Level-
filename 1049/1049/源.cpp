#include<iostream>

using namespace std;


int main(){
	int n, a = 1, now;
	int left, right;
	int num = 0;
	cin >> n;
	while (n / a != 0){
		left = n / (a * 10);
		now = n / a % 10;
		right = n%a;
		if (now == 0)num += left*a;
		else if (now == 1)num += left*a + right + 1;
		else num += (left + 1)*a;
		a *= 10;
	}
	cout << num;
	return 0;
}