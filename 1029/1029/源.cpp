#include<iostream>
#include<vector>
using namespace std;

long n1, n2;
vector<long> s1, s2, s;
int main(){
	cin >> n1;
	for (long i = 0; i < n1; i++){
		long x;
		cin >> x;
		s1.push_back(x);
	}
	cin >> n2;
	for (long i = 0; i < n2; i++){
		long x;
		cin >> x;
		s2.push_back(x);
	}
	long index1 = 0, index2 = 0;
	while (!(index1 == n1 && index2 == n2)){
		if (index1 == n1){
			s.push_back(s2[index2]);
			index2++;
		}
		else if (index2 == n2){
			s.push_back(s1[index1]);
			index1++;
		}else{ 
			if (s1[index1] < s2[index2]){
				s.push_back(s1[index1]);
				index1++;
			}
			else if (s1[index1] > s2[index2]){
				s.push_back(s2[index2]);
				index2++;
			}
			else{
				s.push_back(s1[index1]);
				s.push_back(s2[index2]);
				index1++;
				index2++;
			}
		}
	}
	cout << s[(n1 + n2 - 1) / 2];
	system("pause");
	return 0;
}