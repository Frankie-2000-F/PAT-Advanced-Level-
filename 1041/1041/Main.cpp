#include <iostream>
using namespace std;

int counts[10001];
int nums[100001];
int n;
int main(){
	cin >> n;
	bool None = true;
	for (int i = 0; i < n; i++){
		int no;
		cin >> no;
		nums[i] = no;
		counts[no]++;
	}
	for (int i = 0; i < n; i++){
		if (counts[nums[i]] == 1){
			cout << nums[i];
			None = false;
			break;
		}
	}
	if (None)
		cout << "None";
}