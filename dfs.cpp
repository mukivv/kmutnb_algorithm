#include <iostream>
#include <vector>

using namespace std;

int n;

void dfs(const vector<vector<int> >& graph, vector<int>& visited, int i, int v) {
    visited[i] = 1;
    cout << i << " ";
    for (int j = 0; j < v; j++) {
        if (graph[i][j] == 1 && visited[j] == 0) {
            dfs(graph, visited, j, v);
        }
    }
}

int main(){
	int v,e;
	cin >> v >> e;
	vector<int> visited(v,0);
	vector<vector<int> > graph(v,vector<int>(v,0));
	
	for (int i=0;i<e;i++){
		int a,b;
		cin >> a >> b;
		graph[a][b] = 1;
	}
	
	dfs(graph,visited,0,v);
}
