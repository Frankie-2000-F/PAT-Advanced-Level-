#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;

int post[40], in[40], N;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
}; 

Node* createNode(int postL, int postR, int inL, int inR){
	if (postL > postR)
		return NULL;
	Node* root = new Node;
	root->data = post[postR];
	int numLeft = inL;
	for (int i = inL; i <= inR; i++){
		if (in[i] == post[postR]){
			numLeft = i - inL;
			break;
		}
	}
	root->lchild = createNode(postL, postL + numLeft - 1, inL, inL + numLeft - 1);
	root->rchild = createNode(postL + numLeft, postR - 1, inL + numLeft + 1, inR);
	return root;
}
void BFS(Node* root){
	queue<Node*> q;
	q.push(root);
	int num = 0;
	while (!q.empty()){
		Node* node = q.front();
		q.pop();
		cout << node->data;
		num++;
		if (num < N)
			cout << " ";
		if (node->lchild != NULL)
			q.push(node->lchild);
		if (node->rchild != NULL)
			q.push(node->rchild);
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> post[i];
	}
	for (int i = 0; i < N; i++){
		cin >> in[i];
	}
	Node* root = createNode(0, N - 1, 0, N - 1);
	BFS(root);
	return 0;
}