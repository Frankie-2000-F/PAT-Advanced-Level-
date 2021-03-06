#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include<limits.h>
using namespace std;
int costs[500][500], dists[500][500];
int cost[500], dist[500], p[500];
int N, M, S, D;
bool visited[500];
void Dijkstra(){
	while (!visited[D]){
		int v = -1, MIN = INT_MAX;
		for (int i = 0; i < N; i++){
			if (!visited[i] && dist[i] < MIN){
				MIN = dist[i];
				v = i;
			}
		}
		if (v == -1)
			return;
		visited[v] = true;
		for (int i = 0; i < N; i++){
			if (!visited[i] && dists[v][i] != 0 && dist[v] + dists[v][i] < dist[i]){
				dist[i] = dist[v] + dists[v][i];
				cost[i] = cost[v] + costs[v][i];
				p[i] = v;
			}
			else if (!visited[i] && dists[v][i] != 0 && dist[v] + dists[v][i] == dist[i] && cost[i] > cost[v] + costs[v][i]){
				cost[i] = cost[v] + costs[v][i];
				p[i] = v;
			}
		}
	}
}

void DFS(int v){
	if (v == S){
		cout << v;
	}
	else{
		DFS(p[v]);
		cout << " " << v;
	}
}

int main(){

	cin >> N >> M >> S >> D;
	
	for (int i = 0; i < M; i++){
		int c1, c2, dist, cost;
		cin >> c1 >> c2 >> dist >> cost;
		costs[c1][c2] = costs[c2][c1] = cost;
		dists[c1][c2] = dists[c2][c1] = dist;
	}
	fill(dist, dist + N, INT_MAX);
	fill(cost, cost + N, INT_MAX);
	dist[S] = cost[S] = 0;
	Dijkstra();
	DFS(D);
	cout <<" " << dist[D]<< " " << cost[D];
	return 0;
}