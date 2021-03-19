#include<iostream>
#include<algorithm>
using namespace std;

int n, k=0;
int digits[1001], tree[1001];

int inorder(int root){
	if (root > n)return 0;
	int l = root * 2;
	int r = root * 2 + 1;
	inorder(l);
	tree[root] = digits[k++];
	inorder(r);
	return 0;
}



int main(){
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> digits[i];
	sort(digits, digits + n);
	inorder(1);
	for (int i = 1; i <= n; i++){
		cout << tree[i];
		if (i != n)
			cout << " ";
	}
	system("pause");
	return 0;
}