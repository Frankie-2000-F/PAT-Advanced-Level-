#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

struct node{
	int weight;
	bool hasChild = false;
	node* parent = NULL;
};

node nodes[100];
int n, m, s;
vector<vector<int>> paths;


void DFS(node a){
	int sum = 0;
	node node = a;
	stack<int> weights;
	vector<int> path;
	while (node.parent != NULL){
		sum += node.weight;
		weights.push(node.weight);
		node = *(node.parent);
	}
	sum += node.weight;
	weights.push(node.weight);

	if (sum == s){
		while (!weights.empty()){
			path.push_back(weights.top());
			weights.pop();
		}
		paths.push_back(path);
	}
}

bool cmp(vector<int> v1, vector<int> v2){
	
	return v1 > v2;
}


int main(){
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++){
		cin >> nodes[i].weight;
	}
	for (int i = 0; i < m; i++){
		int id, childNum;
		cin >> id >> childNum;
		nodes[id].hasChild = true;
		for (int j = 0; j < childNum; j++){
			int childID;
			cin >> childID;
			nodes[childID].parent = &nodes[id];
		}
	}
	for (int i = 0; i < n; i++){
		if (!nodes[i].hasChild){
			DFS(nodes[i]);
		}
	}
	sort(paths.begin(), paths.end(), cmp);
	for (int i = 0; i < paths.size(); i++){
		for (int j = 0; j < paths[i].size(); j++){
			cout << (paths[i])[j];
			if (j != paths[i].size() - 1)
				cout << " ";
		}
		if (i != paths.size() - 1)
			cout << endl;
	}
	system("pause");
	return 0;
}