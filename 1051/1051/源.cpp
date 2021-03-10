#include<iostream>
#include<stack>
using namespace std;

char *result[] = { "NO", "YES"};
int flag[1000];
int m, n, k;
int main(){
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++){
		int line[1000];

		for (int j = 0; j < n; j++){
			cin >> line[j];
		}

		stack<int> s;
		int index = 0;
		for (int j = 1; j <=n; j++){
			s.push(j);
			if (s.size() > m)break;
			while (!s.empty() && s.top() == line[index]){
				s.pop();
				index++;
			}
		}
		if (index == n)
			flag[i] = 1;

	}
	for (int i = 0; i < k; i++){
		if (i == k - 1)
			cout << result[flag[i]];
		else
			cout << result[flag[i]] << endl;
	}
	system("pause");
	return 0;
}