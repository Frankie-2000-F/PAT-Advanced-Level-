#include<iostream>
#include<queue>
using namespace std;

int w[1000], r[1000];
int np, ng;
queue<int>q,p;
int main(){
	cin >> np >> ng;
	for (int i = 0; i < np; i++){
		cin >> w[i];
	}
	for (int i = 0; i < np; i++){
		int x;
		cin >> x;
		q.push(x);
	}
	while (1){
		int l;
		if (q.size() % ng == 0)
			l = q.size() / ng;
		else
			l = q.size()/ng + 1;
		while (!q.empty()){
			int max = 0;
			int flag = -1;
			for (int i = 1; i <= ng; i++){
				if(!q.empty()){
					int x = q.front();
					q.pop();
					r[x] = l + 1;
					if (w[x] > max){
						max = w[x];
						flag = x;
					}
				}
			}
			p.push(flag);
		}
		if (p.size() != 1){
			q = p;
			queue<int> empty;
			swap(empty, p);
		}
		else{
			r[p.front()] = 1;
			break;
		}
	}
	for (int i = 0; i < np; i++){
		cout << r[i];
		if (i != np - 1)
			cout << " ";
	}
	system("pause");
	return 0;
}