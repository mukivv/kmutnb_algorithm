#include <iostream>
#include <vector>

using namespace std;

#define inf 50000
#define FALSE -1
#define TRUE 1
#define V 5

int minDist(int dist[], int tree[]){
	int min=inf,minIndex;
	for (int v=0;v<V;v++){
		if (tree[v] == FALSE && dist[v] <= min){
			min = dist[v];
			minIndex = v;
		}
	}
	return minIndex;
}

void printPath(int parent[],int curr){
	if (parent[curr] == FALSE) return;
	printPath(parent,parent[curr]);
	cout << " -> " << curr;
}
void dijkstra(int graph[][V],int src){
	int dist[V],tree[V],parent[V];
	for (int i=0;i<V;i++){
		dist[i] = inf; parent[i] = -1; tree[i]=-1;
	}
	
	dist[src] = 0;
	for (int i=0;i<V-1;i++){
		int u = minDist(dist,tree);
		tree[u] = TRUE;
		for (int v=0;v<V;v++){
			if (tree[v] == FALSE && dist[u] + graph[u][v] < dist[v] && graph[u][v] != 0){ //check relation
				dist[v] = dist[u] + graph[u][v];
				parent[v] = u;
			}
		}
	}
	
	for (int i=0;i<V;i++){
		if (i==src) continue;
		cout <<"Path "<< src << " to " << i << " :\t";
		cout << src;
		if (dist[i] != inf) printPath(parent,i);
		cout << endl;
	}
}

int main(){
	int graph[V][V] = {0} , src, e; //weight should > 0
	cin >> e;
	for (int i=0;i<e;i++){
		int s,d,w;
		cin >> s >> d >> w;
		graph[s][d] = w;
		graph[d][s] = w;
	}
	cin >> src;
	
	dijkstra(graph,src);
	
}
